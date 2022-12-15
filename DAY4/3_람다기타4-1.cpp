class CompilerGeneratedName
{
	int v1;
	int v2;
public:
	CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

	inline int operator()(int a, int b) const
	{
		return a + b + v1 + v2;
	}
	// 캡쳐한 람다 표현식은 함수 포인터로 변환을 위한 
	// 아래 static 멤버 함수를 만들수가 없습니다.
	// 그래서 캡쳐한 람다 표현식은 함수 포인터로 변환 될수 없습니다.
	static inline int helper(int a, int b) 
	{
		return a + b + v1 + v2; // error.
								// static 멤버 함수는 멤버데이타 접근이 안됨.
	}

	using FP = int(*)(int, int);
		

	operator FP() { return &CompilerGeneratedName::helper; }
};


int main()
{
	int v1 = 10, v2 = 20;

	int(*f)(int, int) = [v1, v2](int a, int b) {return a + b + v1 +v2; }; // error

	int(*f1)(int, int) = CompilerGeneratedName(v1, v2);
	
	// 정리 : 캡쳐하지 않은 람다 표현식만 함수 포인터로 변환 됩니다.

	int(*f2)(int, int) = [](int a, int b) {return a + b; }; // ok
	int(*f3)(int, int) = [v1, v2](int a, int b) {return a + b+v1+v2; }; // error

}












