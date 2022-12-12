#include <iostream>

int main()
{
	std::cout << "hello, cpp" << std::endl;

	int n1 = 10;

	// C++11 auto : 우변의 표현식으로 좌변의 타입을 결정
	//			    컴파일시간에 타입결정
	//				실행시간 오버헤드는 없음.
	auto n2 = 10;	// "int n2 = 10"

	
	// decltype () : ()안의 표현식의 타입을 결정해 달라.
	decltype(n2) n3; // int n3	


	int x[3] = { 1,2,3 };

	decltype(x[0]) d1; // ?
}











// github.com/codenuri/moderncpp 에서

// DAY1.zip 받으시면 됩니다.


// 1. DAY1.zip 압축 풀러 보세요
// 
// 2. VC 에서 열어 보세요..
// => A. 프로젝트 메뉴, DAY1속성 메뉴 선택후
// => B. 나타나는 창에서 버전설정해야 합니다.
// => C. Ctrl + F5 로 빌드해서 확인해 보세요

// 3. 소스파일을 빌드에 추가/제외 하는 방법

