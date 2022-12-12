// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반 문자열에서는 "\"는 특수 문자의 시작
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw string : "\" 를 일반 문자로 처리해 달라.
	// R : RawString 이라는 의미
	// "( : 문자열 시작
	// )" : 문자열 종료
	s1 = R"(\\\\.\\pipe\\server)";

	// 문자열 중간에 "가 필요 하면
	s1 = R"(\\"\\.\\pi'pe\\server)";


	// 문자열 중간에 )"  가 필요 하면 ?
	s1 = R"***(\\\\.\\pi)"pe\\server)***";


	std::cout << s1 << std::endl;
}