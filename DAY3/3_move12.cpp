#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// 방법 1. const reference - C++98 시절에 최선의 코드
	// => move 를 지원하지 못하는 setter 입니다.
//	void set_name(const std::string& n) { name = n; }	// 항상 복사
//	void set_name(const std::string& n) { name = std::move(n); } //항상복사
														// const 객체이므로

	// C++11 부터 move 를 지원하는 setter 를 만들려면
	// => 2개의 함수를 제공해야 합니다.
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }

	// move 지원 setter 만들기 #2
	// T&& 를 사용하면 위 2개 함수를 자동생성할수 있습니다.
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
	//	name = n;			// 항상 복사
	//	name = std::move(n);// 항상 move
		name = std::forward<T>(n);
	}
};


int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}








