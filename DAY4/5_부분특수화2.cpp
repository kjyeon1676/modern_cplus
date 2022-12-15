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
// 핵심!!!
// primaray template의 타입 인자가 2개일때
// 1. 사용자는 반드시 2개의 타입을 전달해야 합니다. - main 함수 참고
// 2. 부분 특수화 모양도 반드시 인자가 2개 이어야 합니다. - Object<T,T> 
// 3. 하지만, 부분 특수화의 템플릿 인자의 갯수는 달라질수 있습니다.
//   => 아래 버전은 템플릿 인자가 한개
template<typename T> struct Object<T, T>
{
	static void foo() { cout << "T, T" << endl; }
};

// 특수화
template<> struct Object<int, short>
{
	static void foo() { cout << "int, short" << endl; }
};

int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	// 아래 처럼 출력되게 해 보세요
	Object<int, Object<double, short>>::foo(); 
					// T, Object<U,V>
}

