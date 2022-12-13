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
	// ���ڸ� ������ "int&& arg = 10" ���� �ް� �˴ϴ�.
	// �� ǥ���Ŀ��� 10�� rvalue ������ arg �� lvalue �Դϴ�.
	// f(arg);	// arg�� lvalue �̹Ƿ� hoo(int&)�� ã�� �˴ϴ�.

	// �ذ�å :	chronometry �� �������� rvalue ���µ�..
	//			�����鼭 lvalue �� �Ȱ� �̹Ƿ�
	//			forwarding �Ҷ��� �ٽ� rvalue �� �����ؼ� ����
	f(static_cast<int&&>(arg));

}



int main()
{
	hoo(10); 

	chronometry(hoo, 10); 
}
