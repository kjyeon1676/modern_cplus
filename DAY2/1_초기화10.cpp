// 1_초기화10
#include <iostream>
#include <vector>
void foo(std::vector<int> v) {}

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// 아래 2줄의 차이점은 ?
	// => 핵심. 상황에 따라 () 초기화와 {} 초기화의 결과가 
	//    다를수 있습니다.!!
	std::vector<int> v3(10, 2); // vector(int, int) 생성자
								// => 10개의 요소를 2로 초기화
								// => v3.size() 는 10

	std::vector<int> v4{10, 2};	// vector(std::initializer_list) 생성자
								// => 2개의 요소를 10, 2로 초기화
								// => v4.size()는 2

	// 아래 코드에서 에러는 ?
	std::vector<int> v5 = 10;	// error
								// "explicit vector(int)"

	std::vector<int> v6 = {10}; // ok.
								// "vector(std::initializer_list)"
								// => 즉, explicit 아님.
	foo(10); // error
	foo({ 10 }); // ok
}




