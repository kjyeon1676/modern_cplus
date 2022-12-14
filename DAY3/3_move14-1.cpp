#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// ���ڰ� �Ѱ��� setter �� move ����
	// => 2���� �Լ��� ���� �����ϼ���

	// ������ ������ 2�� �̻��� setter �� move ����
	// => forwarding reference �� ����ϼ���
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// �����ڵ� ������ ���ô�.
	// => �Ʒ� �ڵ�� move �� �������� ���ϴ� ������ �Դϴ�.
	// People(const std::string& n, const std::string& addr)
	//	: name(n), address(addr) {}

	// �ᱹ �����ڰ� move �� �����Ϸ��� �Ʒ�ó�� forwarding reference��
	// ������ �մϴ�.!!
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








