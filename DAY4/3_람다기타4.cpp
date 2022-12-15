class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// �Լ� �����ͷ��� ��ȯ�� ���ؼ� ��ȯ �����ڸ� �����մϴ�.
	using FP = int(*)(int, int);

	//operator FP() { return &CompilerGeneratedName::operator(); }
			// => error.
			// => ����Լ��� operator() �� �ּҴ� �Ϲ��Լ�������Ÿ�԰�
			//	  ȣȯ���� �ʽ��ϴ�

	// �Լ� �����ͷ� ��ȯ�ϱ� ���� operator() �����ڿ� ������ ���� �ϴ�
	// static member function �� �߰��� �ʿ� �մϴ�.
	static inline int helper(int a, int b) { return a + b; }

	operator FP() { return &CompilerGeneratedName::helper; }
};		


int main()
{
	// ����ǥ������ �Լ������Ϳ� ���� ����
	int(*f1)(int, int) = CompilerGeneratedName();
						// => ��ü�� �ٸ� Ÿ������ ����Ƿ���
						// => "��ȯ ������"�� ������ �˴ϴ�.
						// => �ӽð�ü.operator �Լ�������Ÿ��()



	// ����ǥ������ �Լ� �����Ϳ� ������ �ֽ��ϴ�.
	int(*f)(int, int) = [](int a, int b) {return a + b; };
						// CompilerGeneratedName()
}












