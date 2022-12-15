#include <type_traits>

// std::move 를 직접 만드는 것을 생각 해봅시다.

template<typename T>
std::remove_reference_t<T>&& xmove(T&& arg)
{
	// move 의 목표 : 인자로 받은 객체를 rvalue 로 캐스팅하는것
	// 하지만 아래 코드는 rvalue 캐스팅이 아닙니다.
	// 이유   : T 안에 참조가 포함되어 있을수 있으므로
	// return static_cast<T&&>(arg);

	// 해결책 : T 안에 있는 참조를 제거한후 && 를 붙여서 캐스팅.  
	return static_cast< std::remove_reference_t<T> &&>(arg);

	// C++11 스타일
//	return static_cast<typename std::remove_reference<T>::type &&>(arg);
}


int main()
{

}