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
// ��� 1. auto ���
// => return "ǥ����" ���� "ǥ����"�� ���� ���� Ÿ���� �߷��� �޶�°�
// Ư¡ 1. return ������ �Ѱ��� ��츸 ����
// Ư¡ 2. return "ǥ����" ���� ǥ������ ������ �����Ǿ
//         auto �߷� �̹Ƿ� ���� Ÿ���� �� Ÿ��.

template<typename T1, typename T2>
auto Mul(T1 a, T2 b)
{
	return a * b;
}


int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

