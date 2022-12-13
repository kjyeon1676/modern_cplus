// ������ȯ - 73 page �Ʒ� �κ�
#include <iostream>

// �Ʒ� �ڵ忡�� ? �� ��� ä���� �ұ�� ?
/*
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// ��� 1. auto �߷� ���
// => return "ǥ����" ���� "ǥ����"�� ���� ���� Ÿ���� �߷��� �޶�°�
// Ư¡ 1. return ������ �Ѱ��� ��츸 ����
// Ư¡ 2. return "ǥ����" ���� ǥ������ ������ �����Ǿ
//         auto �߷� �̹Ƿ� ���� Ÿ���� �� Ÿ��.
/*
template<typename T1, typename T2>
auto Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// ��� 2. decltype(auto) ��ȯ
// Ư¡ 1. return "ǥ����" ���� "ǥ����"�� ������ �����Ǹ� 
//         ��ȯ Ÿ�Ե� ���� ��� ( auto �� �ٸ� ��)
// Ư¡ 2. return  ������ 2����� ����..
/*
template<typename T1, typename T2>
decltype(auto) Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// ��� 3. ��ȯ Ÿ���� ���� ǥ��
// => return "ǥ����" �� ���� �߷����� ���� "a*b" �� �߷��� �޶�� ����Ѱ�
// => ���� Ÿ���� ���� ǥ�������Ƿ� return ������ �������� ��밡��
// => �׷���, �Ʒ� �ڵ�� ����. 
//    a, b ������ �������� ���Ǵ� �ڵ�
/*
template<typename T1, typename T2>
decltype( a * b ) Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// ��� 4. C++11���� �߰��� ���� ��ȯ Ÿ������ ��ȯ Ÿ�� ���!!
/*
//int add(int a, int b)
auto  add(int a, int b) -> int
{
	return a + b;
}
*/
// => return ������ ������ �־ �����ϰ�
// => a*b �� ������ �����Ǹ� ��ȯ Ÿ�Ե� ����.. !
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

