#include <iostream>

// SFINAE
// => Substitution Failure Is Not An Error
// 
// => �Լ� ���ø��� ����ϱ�� �����ߴµ�...
//    T�� Ÿ���� �����ϰ� ���� �Լ��� ����ٰ� ���� �ߴٸ�
//    ������ ������ �ƴ϶�, �Լ��� �ĺ������� ���� �ȴٴ� �ǹ�..!!

// => ���� �̸��� �ٸ� �Լ��� �ִٸ� ���ɼ� �ִ�.

template<typename T>
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a) { .... } �� ����� �����Ϸ��� �Ѵ�

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); 
}