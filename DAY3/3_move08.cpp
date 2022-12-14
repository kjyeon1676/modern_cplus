#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.

// ��Ģ 1. ����ڰ� ���� �迭�� move �迭�� ����Լ��� ��� �������� ������
// => �����Ϸ��� ��� �����Ѵ�.
// => ���� �迭������ ��� ����� �������ְ�
// => �̵� �迭������ ��� ����� move���ش�.

// ��Ģ 2. ����ڰ� ���� �迭�� ������ ���
// => �����Ϸ��� move �迭�� �������� �ʴ´�.
// => std::move() ���� ����ڰ� ���� ���� ������ ���. 

// => �� ��� �����Ϸ����� ����Ʈ ������ ��û�Ϸ��� "= default" �� ����ϸ�˴ϴ�.


// ��Ģ 3. ����ڰ� move �迭�� ������ ���
// => ���� �迭�� �Լ��� "����" �˴ϴ�.
// => ���� �����ڰ� �ʿ��� �ڵ�� ��� ���� �Դϴ�.
// => ���� �̰�쵵 "=default" �� ��û�� �����մϴ�.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}

	Object(Object&& obj) : name(std::move(obj.name)) { std::cout << "move" << std::endl; }

	/*
	// ���縦 ����ڰ� �����, �������� �����Ϸ����� ��û�ϴ� �ڵ�
	Object(const Object& obj) : name(obj.name) { std::cout << "copy" << std::endl; }

	Object(Object&&) = default;
	Object& operator=(Object&&) = default;
	Object& operator=(const Object&) = default;
	*/
};



int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}