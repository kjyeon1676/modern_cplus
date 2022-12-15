class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환을 위해서 변환 연산자를 제공합니다.
	using FP = int(*)(int, int);

	//operator FP() { return &CompilerGeneratedName::operator(); }
			// => error.
			// => 멤버함수인 operator() 의 주소는 일반함수포인터타입과
			//	  호환되지 않습니다

	// 함수 포인터로 변환하기 위해 operator() 연산자와 동일한 일을 하는
	// static member function 이 추가로 필요 합니다.
	static inline int helper(int a, int b) { return a + b; }

	operator FP() { return &CompilerGeneratedName::helper; }
};		


int main()
{
	// 람다표현식이 함수포인터에 담기는 원리
	int(*f1)(int, int) = CompilerGeneratedName();
						// => 객체가 다른 타입으로 변경되려면
						// => "변환 연산자"가 있으면 됩니다.
						// => 임시객체.operator 함수포인터타입()



	// 람다표현식은 함수 포인터에 담을수 있습니다.
	int(*f)(int, int) = [](int a, int b) {return a + b; };
						// CompilerGeneratedName()
}












