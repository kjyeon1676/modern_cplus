// modern C++ ���� constexpr �� 3���� �뵵 �Դϴ�.
// 1. constexpr ���
// 2. constexpr �Լ�
// 3. constexpr if 

// constexpr �Լ� : ������ ���� ������ �ð��� �˼� �ְ�,
//				    �Լ�ȣ����� ���� ���� ������ �ð��� ���� �䱸�ϸ�
//                  �Լ�ȣ���� ������ �ð��� ����
constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}
int main()
{
	int n = 5;

	int arr1[Factorial(5)]; // ok.. ������ �ð��� �Լ� ȣ����� �Ϸ�
							// ������ �ϸ� "int arr1[120]" �� ��. 

//	int arr2[Factorial(n)]; // error. ���ڰ� ���� �̹Ƿ� 
							// ������ �ð��� �Լ��� �����Ҽ� ����.
						
	int s2 = Factorial(n);  // ok.. ����ð��� ����.

	int s3 = Factorial(3);  // ? ������ �ð� ? ����ð� ?
							// ǥ�ؿ� ���ǵǾ� ���� ����. 
							// �����Ϸ����� �ٸ��� ����.		

	const int s4 = Factorial(3); // �� �� ��������.

	constexpr int s5 = Factorial(3); // �ݵ�� ������ �Ҷ� �ش޶�� �ǹ�.
}

// ���� C++20 ���� consteval function �� �����մϴ�.
// => ������ �Ҷ��� ���డ��.
//consteval int square(int a) { return a * a; }

//square(3); // ok
//square(n); // error. ���� �ȵ�.