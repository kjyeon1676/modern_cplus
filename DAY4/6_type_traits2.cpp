#include <iostream>
#include <type_traits>


// 만드는 방법
// 1. primary template 을 만들고 false 리턴 ( value = false 라는 의미)
// 2. 조건을 만족하는 부분 특수화를 작성하고 true 리턴(value=true)

// T가 포인터 인지 조사하는 방법
template<typename T> struct is_pointer
{
	// 왜 enum 상수로 하나요 ?
//	bool value = false;		// 1. C++98 시절에 이렇게 초기화 할수 없고
							// 2. 또한, 이렇게 하면 value 가 컴파일시간에
							//    알수 있는 값이 아닙니다.

//	enum { value = false }; // 그래서 C++98 시절에는 이 방법이 유일했습니다.
							// 흔히, "enum hack" 이라 불리던 기술 입니다.

	// C++11 이후 부터는 enum 을 사용하지 않고 아래 처럼 만들게 됩니다.
	// => enum 으로 하면 value 가 int 타입인데
	// => 아래 처럼 하면 value 가 bool 타입이 됩니다.
	static constexpr bool value = false;
};


template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};


template<typename T> void foo(const T& a)
{
	// T : int, int*
	if ( is_pointer<T>::value  )

		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}