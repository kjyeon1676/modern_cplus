// �Ʒ� �ּ��� ������ ������
// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����.
//    => signature(�Լ����ڿ� ����Ÿ�Ը��)�� ������ ��� �Լ��� ���� Ÿ���̴�.

// 2. �Լ���ü�� �ڽŸ��� Ÿ���� �ִ�.
//    => signature(�Լ����ڿ� ����Ÿ�Ը��)�� �����ص�
//       ��� �Լ���ü�� �ٸ� Ÿ���̴�.


struct Less 
{ 
	inline bool operator()(int a, int b) const { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) const { return a > b; }
};
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2);
	Greater f2; f2(1, 2);
}