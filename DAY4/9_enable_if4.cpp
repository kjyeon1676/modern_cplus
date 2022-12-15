#include <iostream>
#include <type_traits>

// ���� C++�� "Ư�� Ÿ��" �� ���� �Լ� �����ε���
// ���� �մϴ�.
void foo(int)    {}
void foo(double) {}

// "Ÿ��"�� �ƴ� "Ư�� ������ �����ϴ� Ÿ�Ե�"�� ���� �����ε��� ������
// ���� ������� ?
//void goo(�����Լ����ִ�Ŭ������) {}
//void goo(�����Լ�������Ŭ������) {}
// std::enable_if_t<����, ����Ÿ��> �ε�.. ����Ÿ���� void ��� ��������
template<typename T>
std::enable_if_t< std::is_polymorphic_v<T> > 
goo(T arg)
{
	std::cout << "�����Լ��� �ִ� Ÿ��" << std::endl;
}
// std::is_polymorphic_v<T> : �����Լ� ������ ����
template<typename T>
std::enable_if_t< ! std::is_polymorphic_v<T> >
goo(T arg)
{
	std::cout << "�����Լ��� ���� Ÿ��" << std::endl;
}
class Object
{
public:
//	virtual void f() {}
};
int main()
{
	Object obj;
	goo(obj);
}