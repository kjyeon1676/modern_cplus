#include <iostream>
#include <algorithm>
#include <functional>

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수..

    // std::bind : M 항 함수의 인자를 고정해서
    //             N 항 함수로 변경하는 도구 ( 단, M > N)

    // 사용법 : std::bind( M항함수, M개인자)

    std::bind(&foo, 1, 2, 3, 4) ();
    //|-----결과가 다시함수-----|
}

