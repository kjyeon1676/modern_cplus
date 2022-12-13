// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
	// T a = 10; // 결국 이 표기법이 됩니다. 10으로 T의 타입을 결정 
	auto a = 10; // 결국 이 표기법은 T의 자리에 auto 가 있을뿐 입니다.
				 // auto 의 추론 규칙은 템플릿과 동일합니다!!




	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// auto a1 = n;
	// T    a1 = n;
	// 결국 템플릿 파라미터가 값 타입일때 이므로 "규칙1" 입니다.
	// => 함수인자(우변)이 가진 const, volatile, reference 를 제거후에
	//    타입 결정. 
	// => 각 변수의 타입을 정확히 확인할수 없나요 ??
	//    => 아직 마땅한 방법은 없습니다. 그래서 템플릿으로 확인하는 것이 좋습니다.
	//    => 단, boost 의 type_id_with_cvr 이라는 클래스로 확인은 가능합니다.
	//    => typeid(a1).name()  의 방법은 reference, const 등을 출력안됩니다.
	// 규칙 1.
	auto a1 = n;  // int a1;
	auto a2 = r;  // int a2;
	auto a3 = c;  // int a3;
	auto a4 = cr; // int a4;

	// 규칙 2.
	// auto& a5 = n;
	// T&    a5 = 함수인자; 의 형태 이므로 규칙 2.
	// => 함수인자(우변)의 reference 만 제거하고 auto 타입 결정
	// => const, volatile 은 유지
	auto& a5 = n;	// auto=int				a5=int&
	auto& a6 = r;	// auto=int				a6=int&
	auto& a7 = c;	// auto=const int		a7=const int&
	auto& a8 = cr;	// auto=const int		a8=const int&

	//규칙 3.
	auto&& a9 = 10; // 중요.. 오후에 별도로!

}


