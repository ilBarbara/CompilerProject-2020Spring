#include "../../include/actions.h"

using namespace Boost::Internal;
#define DEFAULT_TYPE Ref<const IRNode>

DEFAULT_TYPE Alist_action_1(DEFAULT_TYPE Alist, DEFAULT_TYPE IdExpr)
{
    //Alist:Ref<Var>
    //IdExpr:Ref<StringImm>
    std::shared_ptr<Var> Alist_ptr = std::const_pointer_cast<Var>(std::dynamic_pointer_cast<const Var>(Alist.real_ptr()));
    std::shared_ptr<const StringImm> IdExpr_ptr = std::dynamic_pointer_cast<const StringImm>(IdExpr.real_ptr());
    Alist_ptr->args.push_back(Expr(IdExpr_ptr));
    return DEFAULT_TYPE(Alist_ptr);
}

DEFAULT_TYPE Alist_action_2(DEFAULT_TYPE IdExpr)
{
    ////IdExpr:Ref<StringImm>
    std::shared_ptr<Var> Alist_ptr = std::make_shared<Var>(Type::int_scalar(32), "", std::vector<Expr>(), std::vector<size_t>());
    std::shared_ptr<const StringImm> IdExpr_ptr = std::dynamic_pointer_cast<const StringImm>(IdExpr.real_ptr());
    Alist_ptr->args.push_back(Expr(IdExpr_ptr));
    return DEFAULT_TYPE(Alist_ptr);
}
DEFAULT_TYPE Clist_action_1(DEFAULT_TYPE Clist, DEFAULT_TYPE TOKEN_INTEGER)
{
    //Alist:Ref<Var>
    //IdExpr:Ref<IntImm>
    std::shared_ptr<Var> Clist_ptr = std::const_pointer_cast<Var>(std::dynamic_pointer_cast<const Var>(Clist.real_ptr()));
    std::shared_ptr<const IntImm> INTEGER_ptr = std::dynamic_pointer_cast<const IntImm>(TOKEN_INTEGER.real_ptr());
    Clist_ptr->shape.push_back(INTEGER_ptr->value());
    return DEFAULT_TYPE(Clist_ptr);
}
DEFAULT_TYPE Clist_action_2(DEFAULT_TYPE TOKEN_INTEGER)
{
    ////IdExpr:Ref<IntImm>
    std::shared_ptr<Var> Clist_ptr = std::make_shared<Var>(Type::int_scalar(32), "", std::vector<Expr>(), std::vector<size_t>());
    std::shared_ptr<const IntImm> INTEGER_ptr = std::dynamic_pointer_cast<const IntImm>(TOKEN_INTEGER.real_ptr());
    Clist_ptr->shape.push_back(INTEGER_ptr->value());
    return DEFAULT_TYPE(Clist_ptr);
}
DEFAULT_TYPE RHS_1(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //ADD
    //RHS:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    Expr RHS_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Binary> RHS_ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Add, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_2(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //MUL
    //RHS:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    Expr RHS_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Binary> RHS_ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Mul, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_3(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //SUB
    //RHS:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    Expr RHS_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Binary> RHS_ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Sub, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_4(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //DIV
    //RHS:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    Expr RHS_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Binary> RHS_ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Div, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_5(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //Mod
    //RHS:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    Expr RHS_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Binary> RHS_ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Mod, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_6(DEFAULT_TYPE RHS_1, DEFAULT_TYPE RHS_2)
{
    //ExactlyDiv
    //RHS:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    Expr RHS_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_2.real_ptr()));
    std::shared_ptr<Binary> RHS_ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::ExactlyDiv, RHS_1_ptr, RHS_2_ptr);
    return DEFAULT_TYPE(RHS_ptr);
};
DEFAULT_TYPE RHS_7(DEFAULT_TYPE RHS_1)
{
    //TRef:Ref<Var>
    //SRef:Ref<Var>
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const Var>(RHS_1.real_ptr()));
    return RHS_1_ptr;
};
DEFAULT_TYPE RHS_8(DEFAULT_TYPE RHS_1)
{
    //RHS:Expr
    //Const:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    return RHS_1_ptr;
};
DEFAULT_TYPE RHS_9(DEFAULT_TYPE RHS_1)
{
    //brackets
    //RHS:Expr
    Expr RHS_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(RHS_1.real_ptr()));
    std::shared_ptr<Unary> RHS_ptr = std::make_shared<Unary>(Type::float_scalar(32), UnaryOpType::Bracket, RHS_1_ptr);
    return RHS_ptr;
};

DEFAULT_TYPE MyTRefBuilder(DEFAULT_TYPE val, DEFAULT_TYPE clist, DEFAULT_TYPE alist)
{
    std::shared_ptr<StringImm> Id_ptr = std::const_pointer_cast<StringImm>(std::dynamic_pointer_cast<const StringImm>(val.real_ptr()));
    std::shared_ptr<Var> clist_ptr = std::const_pointer_cast<Var>(std::dynamic_pointer_cast<const Var>(clist.real_ptr()));
    std::shared_ptr<Var> alist_ptr = std::const_pointer_cast<Var>(std::dynamic_pointer_cast<const Var>(alist.real_ptr()));
    std::shared_ptr<Var> tref_ptr = std::make_shared<Var>(Type::float_scalar(32), Id_ptr->value(), alist_ptr->args, clist_ptr->shape);
    return DEFAULT_TYPE(tref_ptr);
};

DEFAULT_TYPE MySRefBuilder(DEFAULT_TYPE val, DEFAULT_TYPE clist)
{
    std::shared_ptr<StringImm> Id_ptr = std::const_pointer_cast<StringImm>(std::dynamic_pointer_cast<const StringImm>(val.real_ptr()));
    std::shared_ptr<Var> clist_ptr = std::const_pointer_cast<Var>(std::dynamic_pointer_cast<const Var>(clist.real_ptr()));
    std::shared_ptr<Var> sref_ptr = std::make_shared<Var>(Type::float_scalar(32), Id_ptr->value(), std::vector<Expr>(), clist_ptr->shape);
    return DEFAULT_TYPE(sref_ptr);
};

DEFAULT_TYPE MySBuilder(DEFAULT_TYPE lhs, DEFAULT_TYPE rhs)
{
    Expr lhs_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(lhs.real_ptr()));
    Expr rhs_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(rhs.real_ptr()));
    std::shared_ptr<Move> s_ptr = std::make_shared<Move>(lhs_ptr, rhs_ptr, MoveType::MemToMem);
    return DEFAULT_TYPE(s_ptr);
}

DEFAULT_TYPE P_action_1(DEFAULT_TYPE P, DEFAULT_TYPE S)
{
    std::shared_ptr<Move> S_ptr = std::const_pointer_cast<Move>(std::dynamic_pointer_cast<const Move>(S.real_ptr()));
    std::shared_ptr<Kernel> kernal = std::const_pointer_cast<Kernel>(std::dynamic_pointer_cast<const Kernel>(P.real_ptr()));
    kernal->stmt_list.push_back(Stmt(S_ptr));
    return DEFAULT_TYPE(kernal);
}
DEFAULT_TYPE P_action_2(DEFAULT_TYPE S)
{
    std::shared_ptr<Move> S_ptr = std::const_pointer_cast<Move>(std::dynamic_pointer_cast<const Move>(S.real_ptr()));
    std::shared_ptr<Kernel> kernal = std::make_shared<Kernel>("kernal", std::vector<Expr>(), std::vector<Expr>(), std::vector<Stmt>(), KernelType::CPU);
    kernal->stmt_list.push_back(Stmt(S_ptr));
    return DEFAULT_TYPE(kernal);
}

DEFAULT_TYPE IdExpr_action_1(DEFAULT_TYPE IdExpr_1, DEFAULT_TYPE IdExpr_2)
{
    //ADD
    Expr IdExpr_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_1.real_ptr()));
    Expr IdExpr_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_2.real_ptr()));
    std::shared_ptr<Binary> ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Add, IdExpr_1_ptr, IdExpr_2_ptr);
    return ptr;
}

DEFAULT_TYPE IdExpr_action_2(DEFAULT_TYPE IdExpr_1, DEFAULT_TYPE IdExpr_2)
{
    //MUL
    Expr IdExpr_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_1.real_ptr()));
    Expr IdExpr_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_2.real_ptr()));
    std::shared_ptr<Binary> ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Mul, IdExpr_1_ptr, IdExpr_2_ptr);
    return ptr;
}
DEFAULT_TYPE IdExpr_action_3(DEFAULT_TYPE IdExpr_1, DEFAULT_TYPE IdExpr_2)
{
    //ExactlyDiv
    Expr IdExpr_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_1.real_ptr()));
    Expr IdExpr_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_2.real_ptr()));
    std::shared_ptr<Binary> ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::ExactlyDiv, IdExpr_1_ptr, IdExpr_2_ptr);
    return ptr;
}
DEFAULT_TYPE IdExpr_action_4(DEFAULT_TYPE IdExpr_1, DEFAULT_TYPE IdExpr_2)
{
    //Mod
    Expr IdExpr_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_1.real_ptr()));
    Expr IdExpr_2_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_2.real_ptr()));
    std::shared_ptr<Binary> ptr = std::make_shared<Binary>(Type::float_scalar(32), BinaryOpType::Mod, IdExpr_1_ptr, IdExpr_2_ptr);
    return ptr;
}
DEFAULT_TYPE IdExpr_action_5(DEFAULT_TYPE IdExpr_1)
{
    //Bracket
    Expr IdExpr_1_ptr = Expr(std::dynamic_pointer_cast<const ExprNode>(IdExpr_1.real_ptr()));
    std::shared_ptr<Unary> ptr = std::make_shared<Unary>(Type::float_scalar(32), UnaryOpType::Bracket, IdExpr_1_ptr);
    return ptr;
}
