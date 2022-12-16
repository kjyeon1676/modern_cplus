#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders; // _1, _2 를 사용하기 위해

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

    std::bind(&foo, 1, 2, 3, 4) (); // 4항 => 0항 함수로 변경
    //|-----결과가 다시함수-----|


    std::bind(&foo, 5, _1, 3, _2) (8, 9);   // foo( 5, 8, 3, 9)
                                    // 4항 => 2항 함수


    std::bind(&foo, _2, _3, 8, _1 ) (9, 7, 5);   
                // foo(7, 5, 8, 9) 의미가 되도록 ? 채워 보세요
                // 4항 => 3항 함수로 변경
}

