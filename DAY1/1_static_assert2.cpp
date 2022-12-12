#include <iostream>
#include <type_traits> 

#pragma pack(1)	// align �� 1byte ������ !
struct PACKET
{
	char cmd;
	int  data;
};

// PACKET �����ȿ� �ʿ� ���� padding �� �ִٸ� ������ ���߱�
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
				"error, not unexpected padding");
/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/


template<typename T> void object_set_zero(T* p)
{
	// �����Լ��� �ִ� Ÿ���� ���� memset �� �ϸ� �ȵ˴ϴ�.

	// std::is_polymorphic<T>::value : T�� �����Լ��� �ִ��� ����.

	static_assert( !std::is_polymorphic<T>::value,
					"error, T has virtual function");


	memset(p, 0, sizeof(T)); // ������ �ڵ� �ϱ�� ?
}
class AAA
{	
	int data;
public:
//	virtual void foo() {}
};

int main()
{
	AAA aaa;
	object_set_zero(&aaa); // ???
	
}
// static_assert :  ���α׷��� ���, ���ɿ� ���� ������ �ƴ�
//					������ �ڵ带 �ۼ��ϱ� ���� ����..
//                  