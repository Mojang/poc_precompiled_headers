#include <iostream>

const char* msg_ok = "There's connection";
const char* msg_fail = "There is not connection"; 


int main(int argc, char *argv[]) {
    /* An small test case */
    auto uf = union_find(7);

    uf.do_union(1, 2);
    std::cout << ("union 1 2") << std::endl;

    uf.do_union(3, 4);
    std::cout << ("union 3 4") << std::endl;

    uf.do_union(1, 0);
    std::cout << ("union 1 0") << std::endl;

    uf.do_union(1, 3);
    std::cout << ("union 1 3") << std::endl;

    if ( uf.do_find(6, 4) )
    {
        std::cout << msg_ok << std::endl;
    }
    else
    {
        std::cout << msg_fail << std::endl;
    }

    return 0;
}
