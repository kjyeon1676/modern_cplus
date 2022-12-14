#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

template<typename T>
void Swap(T& a, T& b)
{
	// 아래 코드는 복사에 의한 swap 입니다.
	// => 성능이 좋지 않습니다.
	//T tmp = a;
	//a = b;
	//b = tmp;

	// 자원 이동에 의한 swap
	// 위 코드보다 빠릅니다.
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp)
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// 왜 move 가 중요 한가요 ?
// => swap, 버퍼 복사등 일부 알고리즘 작성시 복사가 아닌 move를 사용하면
//    성능이 향상 됩니다.

// move 에서 알아야 하는 것
// 1. swap 등을 만들때 std::move()를 사용하자는 것
// 
// 2. 사용자가 만든 클래스가 move 를 지원하려면 어떻게 해야 하는가 ?
People p1("kim", 20);
People p2 = std::move(p1); // move 효과를 보려면
							// People 을 어떻게 만들어야 하는가 ?

