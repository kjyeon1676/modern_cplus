#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		std::cout << "copy ctor" << std::endl;
	}

	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		c.name = nullptr;

		std::cout << "move ctor" << std::endl;
	}
};

Cat foo()
{
	Cat c("yaong", 2);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// copy
	Cat c3 = foo();	// move

	// c1�� lvalue ���� �ǵ������� rvalue�� ĳ�����ϸ� 
	// => move �����ڰ� ȣ��˴ϴ�.
	Cat c4 = static_cast<Cat&&>(c1);

	Cat c5 = std::move(c2); // std::move ǥ���Լ��� �ϴ�����
			// ���� ���� rvalue �� ĳ�����ϴ� �۾��� �ϰ� �˴ϴ�.

	// �ٽ� 1. std::move() �� �ڿ��� �̵��ϴ� ���� �ƴմϴ�.
	//         => ��ü�� rvalue �� ĳ������ �һ��Դϴ�.
	//		   => ĳ������ ����� move �����ڰ� ȣ��Ǿ���
	//		   => move �����ھȿ��� �ڿ��� move �� �Ǵ� ���� �Դϴ�

	// �ٽ� 2. move �����ڸ� ������ �ʾҴµ�.. std::move�� ����ߴٸ�

	Cat c6 = std::move(c3); // static_cast<Cat&&>(c3)
	
	// 1. move �����ڰ� �ִٸ� move �����ڸ� ����մϴ�.
	// 2. move �����ڰ� ���ٸ� ���� �����ڸ� ����ϰ� �˴ϴ�.

	// ��, move �����ڸ� ������ ���� Ÿ�Ե� std::move() ����ص� �˴ϴ�.
	// => ��, ������ ����� ����,, ���� �����ڸ� ����ϰ� �˴ϴ�.
}