// 91 page
int main()
{
	int n = 10;

	// 핵심 1. 포인터의 포인터를 만들수 있습니다.
	int *p = &n;
	int* *pp = &p; // ok.. 이중 포인터

	// 핵심 2. reference 를 가리키는 reference 를 코드로 직접
	//		   만들수 없습니다.
	int& r = n;
	int& &rr = r;	// error.


	using LREF = int&; 
	using RREF = int&&;

	// 핵심 3. 타입 추론 과정에서 발생되는 reference 충돌은
	//         에러가 아니라 아래 규칙으로 타입을 결정됩니다.
	// reference collapsing
	LREF& r3 = n ;	// int&  &	=> int&
	RREF& r4 = n ;  // int&& &	=> int&
	LREF&& r5 = n ; // int&  && => int&
	RREF&& r6 = 10; // int&& && => int&&
}

template<typename T> void foo(T a)
{
	T& r = a;	// int& & r = a
				// int& r = a;
}

int n = 0;
foo<int&>(n);




