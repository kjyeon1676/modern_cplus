#include <iostream>
#include <type_traits>

//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

// ���ο� enum �� ���������� ����ϴ� Ÿ���� �����Ҽ� �ֽ��ϴ�.
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	using type = std::underlying_type<DAYOFWEEK>::type;

	std::cout << typeid(type).name() << std::endl; // char
}




