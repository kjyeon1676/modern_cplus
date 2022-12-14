#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:

	// 인자로 전달받은 문자열을 보관(retain) 하는 경우는
	// move 지원을 위해 아래 처럼 2개의 setter 가 필요 합니다.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }


	// 인자로 전달받은것을 보관하지 않는 경우는
	// move 지원 등을 고려할필요 없습니다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// move의 효과가 없는 타입은 move를 지원할 필요 없습니다.
	// => 동적할당된 자원이 없는 경우들
	// => std::array<>, int 등.. 
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	std::string s = "hello";
	std::array<int, 32> arr = {0};

	People p;

	p.print_msg(s);
	p.set_data(arr);
}








