// 9_FOLD - 237 page
#include <vector>
#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}


template<typename ... Types>
void Show(Types ... args)
{
	// 핵심 1. std::cout 이 초기값이고, << 가 이항 연산자
	// (I op ... op args )
	//(std::cout << ... << args); 
		// ((((( std::cout << 1) << 2 ) << 3) << 4  .... 

	// 핵심 2. "pack이름" 뿐 아니라 "pack이름을 사용하는 패턴" 을 넣어도 됩니다.
	// => , 도 이항 연산자 입니다.
	// ( pack이름 op ...)
	(printv(args) , ...);
			// ( printv(1), (printv(2), (printv(3), 
}

template<typename C, typename ... Types>
void insert_container(C& c, Types ... args)
{
	(c.push_back(args), ...);
			//  ( c.push_back(1), (c.push_back(3), (c.push_back(3), 
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	std::vector<int> v;
	insert_container(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for (auto e : v)
		std::cout << e << std::endl;
}



