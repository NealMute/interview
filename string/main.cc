#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

#define H_ARRAY_SIZE H_ARRAYSIZE

void test1()
{
    using namespace qh;
    const char* oldstring = "qhstringtestcase1";
    qh::string qhstr(oldstring);
    assert(!strcmp(qhstr.data(), oldstring));
}

void test2()
{
    using namespace qh;
    const char* oldstring = "qhstringtestcase2";
    qh::string qhstr1(oldstring);
    qh::string qhstr2(qhstr1);
    assert(!strcmp(qhstr2.data(), oldstring));
}

void test3()
{
    using namespace qh;
    qh::string qhstr("qhstringtestcase3");
    char c = qhstr[5];
    assert(c=='i');
}

void test4()
{
    using namespace qh;
    qh::string qhstr("qhstringtestcase4");
    qhstr[5] = 'Q';
    assert(!strcmp(qhstr.data(), "qhstrQngtestcase4"));
}

void test5()
{
    using namespace qh;
    const char* oldstring = "qhstringtestcase5";
    qh::string qhstr1(oldstring);
    qh::string qhstr2 = qhstr1;
    assert(!strcmp(qhstr2.data(), oldstring));
}

void test6()
{
    using namespace qh;
    const char* oldstring = "qhstringtestcase5";
    qh::string qhstr1(oldstring,8);
    assert(!strcmp(qhstr1.data(), "qhstring"));
}

void test7()
{
    using namespace qh;
    qh::string qhstr1;
    assert(qhstr1.size() == 0);
}

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
#ifdef WIN32
    system("pause");
#endif

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    std::cout<<"All test passed!"<<std::endl;
	return 0;
}
