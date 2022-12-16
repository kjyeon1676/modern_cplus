#include <iostream>

// C++ 창시자가 "C++11" 발표할때 보여준 예제가 
// printf 만들기
// 구글 검색 "C++ Variadic template printf"

void safe_printf(const char* s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw "invalid format string: missing arguments";
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void safe_printf(const char* s, T& value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                safe_printf(s + 1, args...); // call even when *s == 0 to detect extra arguments
                return;
            }
        }
        std::cout << *s++;
    }
    throw "extra arguments provided to printf";
}
int main()
{
	// printf 의 문제점
	// => 잘못 사용해서 예외등이 나오는 것이 아니라..
	//    비정상 종료, 또는 잘못된 결과등이 나온다.
	printf("%d\n", 10, 20); // 인자의 갯수가 많다.
	printf("%d, %d\n", 10); // 인자의 갯수가 적다.
}