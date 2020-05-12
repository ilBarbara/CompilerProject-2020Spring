#include "../../include/actions.h"

#define DEFAULT_TYPE Boost::Internal::Ref<const Boost::Internal::IRNode>

DEFAULT_TYPE Alist_action_1(DEFAULT_TYPE Alist, DEFAULT_TYPE IdExpr)
{
    //Alist:Ref<Var>
    //IdExpr:Ref<StringImm>
    std::shared_ptr<Boost::Internal::Var> Alist_ptr = std::const_pointer_cast<Boost::Internal::Var>(std::dynamic_pointer_cast<const Boost::Internal::Var>(Alist.real_ptr()));
    std::shared_ptr<const Boost::Internal::StringImm> IdExpr_ptr = std::dynamic_pointer_cast<const Boost::Internal::StringImm>(IdExpr.real_ptr());
    Alist_ptr->args.push_back(Boost::Internal::Expr(IdExpr_ptr));
    return DEFAULT_TYPE(Alist_ptr);
}

DEFAULT_TYPE Alist_action_2(DEFAULT_TYPE IdExpr)
{
    ////IdExpr:Ref<StringImm>
    std::shared_ptr<Boost::Internal::Var> Alist_ptr = std::make_shared<Boost::Internal::Var>(Boost::Internal::Type::int_scalar(32), "", std::vector<Boost::Internal::Expr>(), std::vector<size_t>());
    std::shared_ptr<const Boost::Internal::StringImm> IdExpr_ptr = std::dynamic_pointer_cast<const Boost::Internal::StringImm>(IdExpr.real_ptr());
    Alist_ptr->args.push_back(Boost::Internal::Expr(IdExpr_ptr));
    return DEFAULT_TYPE(Alist_ptr);
}
DEFAULT_TYPE Clist_action_1(DEFAULT_TYPE Clist, DEFAULT_TYPE TOKEN_INTEGER)
{
    //Alist:Ref<Var>
    //IdExpr:Ref<IntImm>
    std::shared_ptr<Boost::Internal::Var> Clist_ptr = std::const_pointer_cast<Boost::Internal::Var>(std::dynamic_pointer_cast<const Boost::Internal::Var>(Clist.real_ptr()));
    std::shared_ptr<const Boost::Internal::IntImm> INTEGER_ptr = std::dynamic_pointer_cast<const Boost::Internal::IntImm>(TOKEN_INTEGER.real_ptr());
    Clist_ptr->shape.push_back(INTEGER_ptr->value());
    return DEFAULT_TYPE(Clist_ptr);
}
DEFAULT_TYPE Clist_action_2(DEFAULT_TYPE TOKEN_INTEGER)
{
    ////IdExpr:Ref<IntImm>
    std::shared_ptr<Boost::Internal::Var> Clist_ptr = std::make_shared<Boost::Internal::Var>(Boost::Internal::Type::int_scalar(32), "", std::vector<Boost::Internal::Expr>(), std::vector<size_t>());
    std::shared_ptr<const Boost::Internal::IntImm> INTEGER_ptr = std::dynamic_pointer_cast<const Boost::Internal::IntImm>(TOKEN_INTEGER.real_ptr());
    Clist_ptr->shape.push_back(INTEGER_ptr->value());
    return DEFAULT_TYPE(Clist_ptr);
}
DEFAULT_TYPE RHS_1(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //ADD
    //RHS:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    Boost::Internal::Expr RHS_2_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Boost::Internal::Binary> RHS_ptr = std::make_shared<Boost::Internal::Binary>(Boost::Internal::Type::float_scalar(32), Boost::Internal::BinaryOpType::Add, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_2(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //MUL
    //RHS:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    Boost::Internal::Expr RHS_2_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Boost::Internal::Binary> RHS_ptr = std::make_shared<Boost::Internal::Binary>(Boost::Internal::Type::float_scalar(32), Boost::Internal::BinaryOpType::Mul, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_3(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //SUB
    //RHS:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    Boost::Internal::Expr RHS_2_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Boost::Internal::Binary> RHS_ptr = std::make_shared<Boost::Internal::Binary>(Boost::Internal::Type::float_scalar(32), Boost::Internal::BinaryOpType::Sub, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_4(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //DIV
    //RHS:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    Boost::Internal::Expr RHS_2_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Boost::Internal::Binary> RHS_ptr = std::make_shared<Boost::Internal::Binary>(Boost::Internal::Type::float_scalar(32), Boost::Internal::BinaryOpType::Div, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_5(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //Mod
    //RHS:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    Boost::Internal::Expr RHS_2_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Boost::Internal::Binary> RHS_ptr = std::make_shared<Boost::Internal::Binary>(Boost::Internal::Type::float_scalar(32), Boost::Internal::BinaryOpType::Mod, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_6(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //ExactlyDiv
    //RHS:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    Boost::Internal::Expr RHS_2_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Boost::Internal::Binary> RHS_ptr = std::make_shared<Boost::Internal::Binary>(Boost::Internal::Type::float_scalar(32), Boost::Internal::BinaryOpType::ExactlyDiv, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_7(DEFAULT_TYPE RHS_1)
{
    //TRef:Ref<Var>
    //SRef:Ref<Var>
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::Var>(RHS_1.real_ptr()));
    return RHS_1_ptr;
};
DEFAULT_TYPE RHS_8(DEFAULT_TYPE RHS_1)
{
    //RHS:Expr
    //Const:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    return RHS_1_ptr;
};
DEFAULT_TYPE RHS_9(DEFAULT_TYPE RHS_1)
{
    //brackets
    //RHS:Expr
    Boost::Internal::Expr RHS_1_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(RHS_1.real_ptr()));
    std::shared_ptr<Boost::Internal::Unary> RHS_ptr = std::make_shared<Boost::Internal::Unary>(Boost::Internal::Type::float_scalar(32), Boost::Internal::UnaryOpType::Bracket, RHS_1_ptr);
    return RHS_ptr;
};

DEFAULT_TYPE MyTRefBuilder(DEFAULT_TYPE val, DEFAULT_TYPE clist, DEFAULT_TYPE alist)
{
    std::shared_ptr<Boost::Internal::StringImm> Id_ptr = std::const_pointer_cast<Boost::Internal::StringImm>(std::dynamic_pointer_cast<const Boost::Internal::StringImm>(val.real_ptr()));
    std::shared_ptr<Boost::Internal::Var> clist_ptr = std::const_pointer_cast<Boost::Internal::Var>(std::dynamic_pointer_cast<const Boost::Internal::Var>(clist.real_ptr()));
    std::shared_ptr<Boost::Internal::Var> alist_ptr = std::const_pointer_cast<Boost::Internal::Var>(std::dynamic_pointer_cast<const Boost::Internal::Var>(alist.real_ptr()));
    std::shared_ptr<Boost::Internal::Var> tref_ptr = std::make_shared<Boost::Internal::Var>(Boost::Internal::Type::float_scalar(32), Id_ptr->value(), alist_ptr->args, clist_ptr->shape);
    return DEFAULT_TYPE(tref_ptr);
};

DEFAULT_TYPE MySRefBuilder(DEFAULT_TYPE val, DEFAULT_TYPE clist)
{
    std::shared_ptr<Boost::Internal::StringImm> Id_ptr = std::const_pointer_cast<Boost::Internal::StringImm>(std::dynamic_pointer_cast<const Boost::Internal::StringImm>(val.real_ptr()));
    std::shared_ptr<Boost::Internal::Var> clist_ptr = std::const_pointer_cast<Boost::Internal::Var>(std::dynamic_pointer_cast<const Boost::Internal::Var>(clist.real_ptr()));
    std::shared_ptr<Boost::Internal::Var> sref_ptr = std::make_shared<Boost::Internal::Var>(Boost::Internal::Type::float_scalar(32), Id_ptr->value(), std::vector<Boost::Internal::Expr>(), clist_ptr->shape);
    return DEFAULT_TYPE(sref_ptr);
};

DEFAULT_TYPE MySBuilder(DEFAULT_TYPE lhs, DEFAULT_TYPE rhs)
{
    Boost::Internal::Expr lhs_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(lhs.real_ptr()));
    Boost::Internal::Expr rhs_ptr = Boost::Internal::Expr(std::dynamic_pointer_cast<const Boost::Internal::ExprNode>(rhs.real_ptr()));
    std::shared_ptr<Boost::Internal::Move> s_ptr = std::make_shared<Boost::Internal::Move>(lhs_ptr, rhs_ptr, Boost::Internal::MoveType::MemToMem);
    return DEFAULT_TYPE(s_ptr);
}

DEFAULT_TYPE P_action_1(DEFAULT_TYPE P, DEFAULT_TYPE S)
{
    std::shared_ptr<Boost::Internal::Move> S_ptr = std::const_pointer_cast<Boost::Internal::Move>(std::dynamic_pointer_cast<const Boost::Internal::Move>(S.real_ptr()));
    std::shared_ptr<Boost::Internal::Kernel> kernal = std::const_pointer_cast<Boost::Internal::Kernel>(std::dynamic_pointer_cast<const Boost::Internal::Kernel>(P.real_ptr()));
    kernal->stmt_list.push_back(Boost::Internal::Stmt(S_ptr));
    return DEFAULT_TYPE(kernal);
}
DEFAULT_TYPE P_action_2(DEFAULT_TYPE S)
{
    std::shared_ptr<Boost::Internal::Move> S_ptr = std::const_pointer_cast<Boost::Internal::Move>(std::dynamic_pointer_cast<const Boost::Internal::Move>(S.real_ptr()));
    std::shared_ptr<Boost::Internal::Kernel> kernal = std::make_shared<Boost::Internal::Kernel>("kernal", std::vector<Boost::Internal::Expr>(), std::vector<Boost::Internal::Expr>(), std::vector<Boost::Internal::Stmt>(), Boost::Internal::KernelType::CPU);
    kernal->stmt_list.push_back(Boost::Internal::Stmt(S_ptr));
    return DEFAULT_TYPE(kernal);
}