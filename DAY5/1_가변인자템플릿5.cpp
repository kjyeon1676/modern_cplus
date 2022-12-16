#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args �� �ִ� ��� ��Ҹ� ������ �ʹٸ�
	// args : 1, 2, 3 �� �ֽ��ϴ�.!!
	// args �ȿ��� 2��° ��Ҹ� ������ �ʹ�!!!
	// => �ѹ��� �Ҽ� �ִ� ����� �����ϴ�.  
	// ��� 1. pack expansion
	// ��� 2. recursive �� ������ �Լ� ����
	// ��� 3. fold expression - C++17

	// ��� 1. pack expansion
	// 1. ����� Ÿ���� ���� ���� �����Ҽ� �ִٸ�
	//    �迭�̳� initializer_list � ��Ƽ� ���
	int x[] = { args... };	// ��, �̰�� args �� empty ��鿡��!
	std::initializer_list<int> e[] = { args... }; // ok


	// 2. ����� Ÿ���� �ٸ� ��� tuple �̶�� Ÿ�Կ� ������ �˴ϴ�.
	std::tuple<Types...> tp(args...);

	// tp �� 0��° ��� ����.
	std::cout << std::get<0>(tp) << std::endl; 

}

int main()
{
	foo(1, 2, 3);	// foo(int, int, int)
}

