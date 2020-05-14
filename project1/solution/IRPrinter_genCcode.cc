

#include "../../include/IRPrinter_genCcode.h"
using namespace Boost::Internal;

void IRPrinter_genCcode::visit(Ref<const Kernel> op)
{
    print_indent();
    oss << "void " << op->name << "(";
    print_arg = true;
    for (size_t i = 0; i < op->inputs.size(); ++i)
    {
        oss << op->printer_data_type << " ";
        op->inputs[i].visit_expr(this);
        if (i < op->inputs.size() - 1)
        {
            oss << ", ";
        }
    }
    for (size_t i = 0; i < op->outputs.size(); ++i)
    {
        oss << ", ";
        oss << op->printer_data_type << " ";
        op->outputs[i].visit_expr(this);
    }
    print_arg = false;
    oss << ") {\n";
    enter();
    for (auto stmt : op->stmt_list)
    {
        //stmt.visit_stmt(this);
    }
    exit();
    oss << "}\n";
}

std::string IRPrinter_genCcode::print(const Group &group)
{
    oss.clear();
    oss << "#include \"../run.h\"\n\n";
    group.visit_group(this);
    return oss.str();
}