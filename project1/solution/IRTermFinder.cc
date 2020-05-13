#include "../../include/IRTermFinder.h"

extern std::map<std::string, std::pair<int, int>> global_map;
using namespace Boost::Internal;

void IRTermFinder::visit(Ref<const Move> op)
{
    IRNodeType node_type = op->src->node_type();
    bool term_flag = true;
    if (node_type == IRNodeType::Binary)
    {
        std::shared_ptr<const Binary> src_ptr = (op->src).as<const Binary>();
        BinaryOpType src_op_type = src_ptr->op_type;
        if (src_op_type == BinaryOpType::Add || src_op_type == BinaryOpType::Sub)
        {
            term_flag = false;
            term_group_list.push_back(std::make_shared<term_group>((src_ptr->b).real_ptr(), src_op_type));

            IRNodeType a_nodetype = src_ptr->a->node_type();
            bool a_term_flag = true;
            if (a_nodetype == IRNodeType::Binary)
            {
                std::shared_ptr<const Binary> a_ptr = (src_ptr->a).as<const Binary>();
                BinaryOpType a_op_type = a_ptr->op_type;
                if (a_op_type == BinaryOpType::Add || a_op_type == BinaryOpType::Sub)
                {
                    a_term_flag = false;
                    (src_ptr->a).visit_expr(this);
                }
            }
            if (a_term_flag)
            {
                term_group_list.push_back(std::make_shared<term_group>((src_ptr->a).real_ptr(), BinaryOpType::Add));
            }
        }
    }
    if (term_flag)
    {
        term_group_list.push_back(std::make_shared<term_group>((op->src).real_ptr(), BinaryOpType::Add));
    }
}

void IRTermFinder::visit(Ref<const Binary> op)
{
    BinaryOpType op_type = op->op_type;
    term_group_list.push_back(std::make_shared<term_group>((op->b).real_ptr(), op_type));

    IRNodeType a_node_type = op->a->node_type();
    bool a_term_flag = true;
    if (a_node_type == IRNodeType::Binary)
    {
        std::shared_ptr<const Binary> a_ptr = (op->a).as<const Binary>();
        BinaryOpType a_op_type = a_ptr->op_type;
        if (a_op_type == BinaryOpType::Add || a_op_type == BinaryOpType::Sub)
        {
            a_term_flag = false;
            (op->a).visit_expr(this);
        }
    }
    if (a_term_flag)
    {
        term_group_list.push_back(std::make_shared<term_group>((op->a).real_ptr(), BinaryOpType::Add));
    }
}

void IRTermFinder::getIfStmtGroup()
{
    for (auto term_group_ptr : term_group_list)
    {
        IRIfFinder iffinder;
        term_group_ptr->term_ptr.real_ptr()->visit_node(&iffinder);
        std::shared_ptr<IfThenElse> ptr;
        for (int i = iffinder._if_stmt_group.size() - 1; i >= 0; i--)
        {
            if (i == int(iffinder._if_stmt_group.size() - 1))
            {
                ptr = iffinder._if_stmt_group[i];
                ptr->true_case = Stmt(term_group_ptr->move_stmt);
            }
            else
            {
                iffinder._if_stmt_group[i]->true_case = Stmt(ptr);
                ptr = iffinder._if_stmt_group[i];
            }
        }
        term_group_ptr->if_stmt_group = ptr;
    }
}

void IRTermFinder::getForStmtGroup()
{
    for (auto term_group_ptr : term_group_list)
    {
        std::vector<Expr> index_vec;
        std::shared_ptr<const ExprNode> ptr = std::dynamic_pointer_cast<const ExprNode>(term_group_ptr->term_ptr.real_ptr());
        std::set<std::string> variables;
        for (std::string varname : term_group_ptr->lhs->variables)
        {
            variables.insert(varname);
        }
        for (std::string varname : ptr->variables)
        {
            variables.insert(varname);
        }
        for (std::string varname : variables)
        {
            std::pair<int, int> item = global_map[varname];
            Expr dom = Dom::make(Type::int_scalar(32), item.first, item.second);
            index_vec.push_back(Index::make(Type::int_scalar(32), varname, dom, IndexType::Block));
        }
        term_group_ptr->for_stmt_group = std::make_shared<LoopNest>(index_vec, std::vector<Stmt>());
        term_group_ptr->for_stmt_group->body_list.push_back(Stmt(term_group_ptr->if_stmt_group));
    }
}

void IRTermFinder::getMoveStmt()
{
    for (auto term_group_ptr : term_group_list)
    {
        MoveOp move_op = MoveOp::Equal;
        if (term_group_ptr->left_op == BinaryOpType::Add)
            move_op = MoveOp::Plus;
        else if (term_group_ptr->left_op == BinaryOpType::Sub)
            move_op = MoveOp::Minus;
        term_group_ptr->move_stmt = std::make_shared<Move>(Expr(), Expr(std::dynamic_pointer_cast<const ExprNode>(term_group_ptr->term_ptr.real_ptr())), MoveType::MemToMem);
        term_group_ptr->move_stmt->move_op = move_op;
    }
}

void IRIfFinder::visit(Ref<const Var> op)
{
    std::shared_ptr<const Var> op_ptr = op.real_ptr();
    if (op_ptr->name.compare(""))
    {
        int arg_len = op_ptr->args.size();
        for (int i = 0; i < arg_len; ++i)
        {
            Expr comp1 = Compare::make(Type::int_scalar(32), CompareOpType::LE, Expr(0), op_ptr->args[i]);
            Expr comp2 = Compare::make(Type::int_scalar(32), CompareOpType::LT, op_ptr->args[i], Expr(static_cast<uint64_t>(op_ptr->shape[i])));
            Expr _cond = Binary::make(Type::int_scalar(32), BinaryOpType::And, comp1, comp2);

            _if_stmt_group.push_back(std::make_shared<IfThenElse>(_cond, Stmt(), Stmt()));
        }
    }
}
