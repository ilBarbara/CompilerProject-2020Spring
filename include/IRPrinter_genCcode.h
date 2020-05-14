#ifndef BOOST_IRPRINTER_GENCCODE_H
#define BOOST_IRPRINTER_GENCCODE_H

#include "IRPrinter.h"

namespace Boost
{

    namespace Internal
    {

        class IRPrinter_genCcode : public IRPrinter
        {
        public:
            IRPrinter_genCcode() : IRPrinter() {}
            void visit(Ref<const Kernel> op);
            std::string print(const Group &);
        };

    } // namespace Internal

} // namespace Boost

#endif // BOOST_IRPRINTER_GENCCODE_H