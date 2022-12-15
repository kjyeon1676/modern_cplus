#include <iostream>
#include <type_traits>

// std::enable_if 를 정말 많이 사용했는데.. 너무 복잡해 보입니다.
// => 그래서 C++20 에서 "Concept" 이라는 새로운 문법이 등장합니다.

template<typename T> requires std::is_pointer_v<T> 
void printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);// ok.

	std::pair<int, int> p;
}


