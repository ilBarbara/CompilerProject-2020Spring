// this is a silly solution
// just to show you how different
// components of this framework work
// please bring your wise to write
// a 'real' solution :)

#include <iostream>
#include <fstream>
#include <string>
#include "../../include/IR.h"
#include "../../3rdparty/jsoncpp/include/json/json.h"
#include "../../include/mytest.h"
#include "../../include/y.tab.h"
int main()
{
    std::string cheat_src =
        "// this is supposed to be generated by codegen tool\n\
#include \"../run.h\"\n\
\n\
void kernel_example(float (&B)[32][16], float (&C)[32][16], float (&A)[32][16]) {\n\
    for (int i = 0; i < 32; ++i) {\n\
        for (int j = 0; j < 16; ++j) {\n\
            A[i][j] = B[i][j] * C[i][j];\n\
        }\n\
    }\n\
}";
    Boost::Internal::Ref<const Boost::Internal::IRNode> myroot;

    Json::CharReaderBuilder reader_builder;
    Json::Value root;
    JSONCPP_STRING errs;
    std::ofstream ofile("./kernels/kernel_example.cc", std::ios::out);
    std::ifstream infile("./cases/case1.json", std::ios::binary);
    if (!infile.is_open())
    {
        std::cout << "open file failed";
    }
    bool parse_ok = Json::parseFromStream(reader_builder, infile, &root, &errs);
    if (!parse_ok)
    {
        std::cout << "parse failed";
    }
    std::string str = root["kernel"].asString();
    myroot = yyparse_string((char *)(str.c_str()));
    Boost::Internal::IRNodeType nodetype;
    nodetype = Boost::Internal::IRNodeType::Kernel;
    bool flag = (nodetype == Boost::Internal::IRNodeType::Kernel);
    if (flag)
        ofile << cheat_src;
    else
        ofile << cheat_src;
    //演示返回的是id节点。下面这一行进行类型强转，访问id节点的value属性，输出到example.cc里，所以make的时候会报错。
    ofile << ((std::dynamic_pointer_cast<const Boost::Internal::Var>(myroot.real_ptr()))->shape[0]);
    ofile.close();
    return 0;
}