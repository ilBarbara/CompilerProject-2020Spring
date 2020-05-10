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
    //IdExpr:Ref<StringImm>
    std::shared_ptr<Boost::Internal::Var> Clist_ptr = std::const_pointer_cast<Boost::Internal::Var>(std::dynamic_pointer_cast<const Boost::Internal::Var>(Clist.real_ptr()));
    std::shared_ptr<const Boost::Internal::IntImm> INTEGER_ptr = std::dynamic_pointer_cast<const Boost::Internal::IntImm>(TOKEN_INTEGER.real_ptr());
    Clist_ptr->shape.push_back(INTEGER_ptr->value());
    return DEFAULT_TYPE(Clist_ptr);
}
DEFAULT_TYPE Clist_action_2(DEFAULT_TYPE TOKEN_INTEGER)
{
    ////IdExpr:Ref<StringImm>
    std::shared_ptr<Boost::Internal::Var> Clist_ptr = std::make_shared<Boost::Internal::Var>(Boost::Internal::Type::int_scalar(32), "", std::vector<Boost::Internal::Expr>(), std::vector<size_t>());
    std::shared_ptr<const Boost::Internal::IntImm> INTEGER_ptr = std::dynamic_pointer_cast<const Boost::Internal::IntImm>(TOKEN_INTEGER.real_ptr());
    Clist_ptr->shape.push_back(INTEGER_ptr->value());
    return DEFAULT_TYPE(Clist_ptr);
}
