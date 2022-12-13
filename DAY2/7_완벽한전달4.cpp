#include <iostream>

void hoo(int&& arg) {}

template<typename F> 
void chronometry(F f, int& arg)
{
	f(arg);
}
// main					chronometry							hoo(int&&)
// hoo(10) ==================================================> ok
// chronometry(10) ==> int&& arg = 10; 
//						hoo(arg)=============================> error
//						hoo(static_cast<int&&>(arg)) ========> ok
template<typename F> 
void chronometry(F f, int&& arg)
{
	// 인자를 받을때 "int&& arg = 10" 으로 받게 됩니다.
	// 위 표현식에서 10은 rvalue 이지만 arg 는 lvalue 입니다.
	// f(arg);	// arg가 lvalue 이므로 hoo(int&)를 찾게 됩니다.

	// 해결책 :	chronometry 에 보낼때는 rvalue 였는데..
	//			받으면서 lvalue 가 된것 이므로
	//			forwarding 할때는 다시 rvalue 로 변경해서 전달
	f(static_cast<int&&>(arg));

}



int main()
{
	hoo(10); 

	chronometry(hoo, 10); 
}
