#include <iostream>
#include <type_traits>

// ���� ���𹮿��� ���� �̸��� �����ϸ� Ÿ���� �˴ϴ�.
int n;		// ���� �̸� : n,   Ÿ�� : int
double d;	// ���� �̸� : d,   Ÿ�� : double

int x[3];	// ���� �̸� : x,   Ÿ�� : int[3]
			
// int[3];  // int Ÿ���� ũ�� 3�� �迭 Ÿ��
// T[3];    // ���� Ÿ���� ũ�� 3�� �迭 Ÿ��
// T[N];    // ���� Ÿ���� ���� ũ�� �迭 Ÿ��









// ���� ������ is_pointer �����ؼ� is_array ����� ������...

template<typename T> struct is_array
{
	static constexpr bool value = false;
	static constexpr int  size = -1;
};

template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
	static constexpr int  size = N;
};

template<typename T> void foo(T& a)
{
	// T : int[3]
	if ( is_array<T>::value ) 
		std::cout << "�迭�Դϴ�. ũ��� " << is_array<T>::size << std::endl;
	else
		std::cout << "�迭 �ƴ�" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };

	foo(arr);
}

