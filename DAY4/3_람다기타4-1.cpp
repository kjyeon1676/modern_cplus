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
	// ĸ���� ���� ǥ������ �Լ� �����ͷ� ��ȯ�� ���� 
	// �Ʒ� static ��� �Լ��� ������� �����ϴ�.
	// �׷��� ĸ���� ���� ǥ������ �Լ� �����ͷ� ��ȯ �ɼ� �����ϴ�.
	static inline int helper(int a, int b) 
	{
		return a + b + v1 + v2; // error.
								// static ��� �Լ��� �������Ÿ ������ �ȵ�.
	}

	using FP = int(*)(int, int);
		

	operator FP() { return &CompilerGeneratedName::helper; }
};


int main()
{
	int v1 = 10, v2 = 20;

	int(*f)(int, int) = [v1, v2](int a, int b) {return a + b + v1 +v2; }; // error

	int(*f1)(int, int) = CompilerGeneratedName(v1, v2);
	
	// ���� : ĸ������ ���� ���� ǥ���ĸ� �Լ� �����ͷ� ��ȯ �˴ϴ�.

	int(*f2)(int, int) = [](int a, int b) {return a + b; }; // ok
	int(*f3)(int, int) = [v1, v2](int a, int b) {return a + b+v1+v2; }; // error

}












