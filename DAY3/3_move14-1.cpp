#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// 인자가 한개인 setter 의 move 지원
	// => 2개의 함수를 직접 제공하세요

	// 인자의 갯수가 2개 이상인 setter 의 move 지원
	// => forwarding reference 를 사용하세요
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// 생성자도 생각해 봅시다.
	// => 아래 코드는 move 를 지원하지 못하는 생성자 입니다.
	// People(const std::string& n, const std::string& addr)
	//	: name(n), address(addr) {}

	// 결국 생성자가 move 를 지원하려면 아래처럼 forwarding reference로
	// 만들어야 합니다.!!
	template<typename T1, typename T2>
	People(T1&& n, T2&& a) 
		: name(std::forward<T1>(n)), 
		  address(std::forward<T2>(a))
	{

	}

};


int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p(name, std::move(addr));

	p.set(name, addr);
	p.set(std::move(name), addr);
	p.set(name, std::move(addr));
	p.set(std::move(name), std::move(addr));
}








