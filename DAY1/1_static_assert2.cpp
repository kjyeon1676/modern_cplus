#include <iostream>
#include <type_traits> 

#pragma pack(1)	// align 을 1byte 단위로 !
struct PACKET
{
	char cmd;
	int  data;
};

// PACKET 구조안에 필요 없는 padding 이 있다면 컴파일 멈추기
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
	// 가상함수가 있는 타입을 절대 memset 을 하면 안됩니다.

	// std::is_polymorphic<T>::value : T가 가상함수가 있는지 조사.

	static_assert( !std::is_polymorphic<T>::value,
					"error, T has virtual function");


	memset(p, 0, sizeof(T)); // 안전한 코드 일까요 ?
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
// static_assert :  프로그램에 기능, 성능에 대한 도구가 아님
//					안전한 코드를 작성하기 위한 도구..
//                  