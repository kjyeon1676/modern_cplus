#include <iostream>

// C++11 ���� ��Ƽ �����带 ����
#include <thread> 
#include <chrono>
using namespace std::literals;

// this_thread namespace 
// => 4���� ���� �Լ��� �����մϴ�.

int main()
{
	int n = std::this_thread::get_id();

	std::chrono::seconds sec(3);
	std::this_thread::sleep_for(sec);

	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::this_thread::sleep_for(3s);
}


