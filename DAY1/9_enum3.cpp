#include <iostream>
#include <type_traits>

//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

// 새로운 enum 은 내부적으로 사용하는 타입을 변경할수 있습니다.
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	using type = std::underlying_type<DAYOFWEEK>::type;

	std::cout << typeid(type).name() << std::endl; // char
}




