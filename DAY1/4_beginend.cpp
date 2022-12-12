// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// 반복자를 얻는 방법
	// 1. C++98 스타일
	// 단점 : 컨테이너 변경시 반복자 타입도 변경해야 한다.
	// std::vector<int>::iterator p1 = v.begin();
	// std::vector<int>::iterator p2 = v.end();

	// 2. C++11 스타일 auto 사용
	// auto p1 = v.begin();
	// auto p2 = v.end();		// v가 raw array 인경우는 에러 발생

	// 멤버 함수 begin 말고 일반함수 begin 사용
	// => v 가 STL 컨테이너 뿐아니라 raw array 도 사용가능
	auto p1 = std::begin(v);
	auto p2 = std::end(v);		

	// auto sz1 = v.size(); // v가 컨테이너만 가능
	auto sz2 = std::size(v); // v가 컨테이너 또는 raw array 도 가능

	//------------------------------
	// C++20 에서 새로운 begin 이 등장합니다.
	
	// 기존 begin 의 문제점.
	// => 컨테이너가 임시객체인 경우에 대한 고려가 되어있지 않다.
	auto p3 = std::begin( std::vector<int>{1, 2, 3} );
	int n = *p3; // runtime error


	// C++20 의 새로운 begin 은
	// => 임시객체가 인자로 오는 경우
	// => Dangling iterator 라는 개념을 반환합니다.
	// => Dangling iterator 는 *연산이 되지 않습니다.
	auto p4 = std::ranges::begin(std::vector<int>{1, 2, 3});

	int n = *p4; // compile error
}