#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;

public:
	// ��� 1. const reference - C++98 ������ �ּ��� �ڵ�
	// => move �� �������� ���ϴ� setter �Դϴ�.
//	void set_name(const std::string& n) { name = n; }	// �׻� ����
//	void set_name(const std::string& n) { name = std::move(n); } //�׻󺹻�
														// const ��ü�̹Ƿ�

	// C++11 ���� move �� �����ϴ� setter �� �������
	// => 2���� �Լ��� �����ؾ� �մϴ�.
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }

	// move ���� setter ����� #2
	// T&& �� ����ϸ� �� 2�� �Լ��� �ڵ������Ҽ� �ֽ��ϴ�.
	template<typename T>
	void set_name(T&& n)
	{
		// ������ �´� ���� ?
	//	name = n;			// �׻� ����
	//	name = std::move(n);// �׻� move
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








