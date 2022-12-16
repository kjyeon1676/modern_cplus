#include <iostream>

// C++ â���ڰ� "C++11" ��ǥ�Ҷ� ������ ������ 
// printf �����
// ���� �˻� "C++ Variadic template printf"

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
	// printf �� ������
	// => �߸� ����ؼ� ���ܵ��� ������ ���� �ƴ϶�..
	//    ������ ����, �Ǵ� �߸��� ������� ���´�.
	printf("%d\n", 10, 20); // ������ ������ ����.
	printf("%d, %d\n", 10); // ������ ������ ����.
}