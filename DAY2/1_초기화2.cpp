#include <complex>

int main()
{
	// C++98 ������ ������ ������ ����
	// �ʱ�ȭ ����� �޶����ϴ�.
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);

	// C++11 ���ʹ� ��� ������ ������ {}�� �ʱ�ȭ �����մϴ�.
	// "�ϰ��� �ʱ�ȭ(uniform initialization)" �̶�� ����
	// => ����, �߰�ȣ �ʱ�ȭ(brace init) �̶�� �մϴ�.
	int n1 = { 10 };
	int x[2] = { 1,2 };
	std::complex<double> c = { 1, 2 };

	// = �� ��� �˴ϴ�.
	int n1 { 10 };
	int x[2] { 1,2 };
	std::complex<double> c { 1, 2 };

	// direct(����) initialization : = �� ���� �ʱ�ȭ �ϴ� ��
	// copy(����)   initialization : = �� �ִ� �ʱ�ȭ
	
}












