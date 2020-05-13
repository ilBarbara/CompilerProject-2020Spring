#ifndef BOOST_IRPRINTER_H
#define BOOST_IRPRINTER_H

#include <string>
#include <sstream>

#include "IR.h"
#include "IRVisitor.h"

namespace Boost
{

    namespace Internal
    {

#define DEFAULT_TYPE Ref<IRNode>

        class term_group
        {
        public:
            DEFAULT_TYPE term_ptr;
            BinaryOpType left_op;
            std::shared_ptr<LoopNest> for_stmt_group = nullptr;
            std::shared_ptr<IfThenElse> if_stmt_group = nullptr;
            std::shared_ptr<Move> move_stmt = nullptr;
            std::shared_ptr<Var> lhs, lhs_temp;

            template <typename U, typename std::enable_if<std::is_base_of<IRNode, U>::value>::type * = nullptr>
            term_group(std::shared_ptr<const U> _ptr, BinaryOpType _op)
            {
                term_ptr = DEFAULT_TYPE(std::const_pointer_cast<U>(_ptr));
                left_op = _op;
            }
        };

        class IRTermFinder : public IRVisitor
        {
        public:
            //std::vector< std::shared_ptr<IRNode> > term_list;
            std::vector<std::shared_ptr<term_group>> term_group_list;

            void visit(Ref<const Binary>) override;
            void visit(Ref<const Move>) override;

            void getForStmtGroup();
            void getIfStmtGroup();
            void getMoveStmt();
        };

        class IRIfFinder : public IRVisitor
        {
        public:
            std::vector<std::shared_ptr<IfThenElse>> _if_stmt_group;

            void visit(Ref<const Var>) override;
        };

    } // namespace Internal

} // namespace Boost

#endif // BOOST_IRPRINTER_H