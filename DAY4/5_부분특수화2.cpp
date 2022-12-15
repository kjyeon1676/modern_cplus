#include <iostream>
using namespace std;

// 160 page
template<typename T, typename U> struct Object
{
	static void foo() { cout << "T, U" << endl; }
};

template<typename T, typename U> struct Object<T*, U*>
{
	static void foo() { cout << "T*, U*" << endl; }
};

template<typename T, typename U> struct Object<T*, U>
{
	static void foo() { cout << "T*, U" << endl; }
};
//================================================
// �ٽ�!!!
// primaray template�� Ÿ�� ���ڰ� 2���϶�
// 1. ����ڴ� �ݵ�� 2���� Ÿ���� �����ؾ� �մϴ�. - main �Լ� ����
// 2. �κ� Ư��ȭ ��絵 �ݵ�� ���ڰ� 2�� �̾�� �մϴ�. - Object<T,T> 
// 3. ������, �κ� Ư��ȭ�� ���ø� ������ ������ �޶����� �ֽ��ϴ�.
//   => �Ʒ� ������ ���ø� ���ڰ� �Ѱ�
template<typename T> struct Object<T, T>
{
	static void foo() { cout << "T, T" << endl; }
};

// Ư��ȭ
template<> struct Object<int, short>
{
	static void foo() { cout << "int, short" << endl; }
};

int main()
{
	// �Ʒ� ó�� ������ ����� ������.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	// �Ʒ� ó�� ��µǰ� �� ������
	Object<int, Object<double, short>>::foo(); 
					// T, Object<U,V>
}

