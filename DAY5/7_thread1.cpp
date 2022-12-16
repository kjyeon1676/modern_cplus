#include <iostream>

// C++11 부터 멀티 스레드를 지원
#include <thread> 
#include <chrono>
using namespace std::literals;

// this_thread namespace 
// => 4개의 도움 함수를 제공합니다.

int main()
{
	int n = std::this_thread::get_id();

	std::chrono::seconds sec(3);
	std::this_thread::sleep_for(sec);

	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::this_thread::sleep_for(3s);
}


