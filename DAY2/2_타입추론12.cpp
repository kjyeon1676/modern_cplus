// 2_Ÿ���߷�12

// ���
// �迭�� ���ø��� ���ڷ� �����ų�, auto �� ����ų��
// 1. ������ ������ �����ͷ� ����Ǿ �ް� �˴ϴ�.
//    => "decay" ��� �մϴ�.
// 
// 2. ������ ������ ��ȭ ���� �迭�� �ް� �˴ϴ�.


template<typename T> void f1(T  a, T  b){ }
template<typename T> void f2(T& a, T& b){ }

int main()
{
	f1("orange", "apple"); // ok
	// => �迭�� �����ϴ� ��, ������ �ް� �����Ƿ� �����ͷ� �ް� �˴ϴ�.
	// => "orange" const char[7] => const char*
	// => "apple"  const char[6] => const char*
	// ����, 2���� ���ڰ� ���� Ÿ���̾�� �Ѵٴ� ������ ����!! ���� �ƴ�.

	f2("orange", "apple"); // error. �� �����ϱ�� ?
	// => �迭�� ������ ������ T�� �迭 �Դϴ�.
	// => ���� Ÿ���� �����ؾ� �ϴµ�
	// => "orange" �� "apple" �� �ٸ� Ÿ���̹Ƿ� error


	// �ٽ� 1. ���ڿ� ���ͷ��� Ÿ��
	// "orange" : const char[7]
	// "apple"  : const char[6]
	// => ��, "orange" �� "apple" �� �ٸ� Ÿ�� �Դϴ�.
}