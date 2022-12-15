#include <iostream>
#include <type_traits>

// 변수 선언문에서 변수 이름을 제거하면 타입이 됩니다.
int n;		// 변수 이름 : n,   타입 : int
double d;	// 변수 이름 : d,   타입 : double

int x[3];	// 변수 이름 : x,   타입 : int[3]
			
// int[3];  // int 타입의 크기 3인 배열 타입
// T[3];    // 임의 타입의 크기 3인 배열 타입
// T[N];    // 임의 타입의 임이 크기 배열 타입









// 앞의 예에서 is_pointer 복사해서 is_array 만들어 보세요...

template<typename T> struct is_array
{
	static constexpr bool value = false;
};


template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
};



template<typename T> void foo(T& a)
{
	// is_array 만들어 보세요
	if ( is_array<T>::value ) 
		std::cout << "배열" << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };

	foo(arr);
}

