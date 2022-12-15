// 6_enable_if1.cpp

// �Ʒ� �ڵ�� C++11 ���� �̹� ǥ�ؿ� �ֽ��ϴ�.
template<bool, typename T = void > struct enable_if
{
	using type = T; // typedef  T type;
};
template<typename T> struct enable_if<false, T> 
{
	// 1��° ���ڰ� false �϶��� type �� ���ٴ� ���� �ٽ� �Դϴ�.
};
int main()
{
	// enable_if ���� : enable_if<bool��, Ÿ��(������void)>::type

	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ?
	enable_if<true, int>::type  n1;	// int n1
	enable_if<true>::type       n2;	// void n2 �ε�, void ������ ����� 
									//				�����Ƿ� error
	enable_if<false, int>::type n3; // error. ::type �� ����
	enable_if<false>::type n4;		// error. ::type �� ���٤�.
}