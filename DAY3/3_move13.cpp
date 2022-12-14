#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:

	// ���ڷ� ���޹��� ���ڿ��� ����(retain) �ϴ� ����
	// move ������ ���� �Ʒ� ó�� 2���� setter �� �ʿ� �մϴ�.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }


	// ���ڷ� ���޹������� �������� �ʴ� ����
	// move ���� ���� ������ʿ� �����ϴ�.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// move�� ȿ���� ���� Ÿ���� move�� ������ �ʿ� �����ϴ�.
	// => �����Ҵ�� �ڿ��� ���� ����
	// => std::array<>, int ��.. 
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








