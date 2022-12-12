// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

using namespace std::literals; // 표준에 이미 있는 literals
							// 사용하기 위해서..

void foo(const char* s) { std::cout << "char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello");  // const char*
	foo("hello"s); // string operator""s(const char*)
			
	std::chrono::seconds s1(3); // 3  초 객체
	auto s2 = 3s; // std::chrono::seconds operator""s(3)
	auto s3 = 1h + 10min + 20s; 
	std::cout << s3.count() << std::endl; // 4220
}



