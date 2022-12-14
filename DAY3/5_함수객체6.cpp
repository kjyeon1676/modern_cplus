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
//------------------------------------------------
// �� ��å�� ��ü�Ҽ� �ְ�, 
// �� ��å ��ü�� �ζ��� ġȯ �Ҽ� �ִ� Sort
// ���ø� �� �Լ� ��ü�� ����� ���
// STL �� �ٽ� ���� ����.
template<typename T> 
void Sort(int* arr, int sz, T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{			
			if (cmp(arr[i], arr[j]) ) // cmp.operator()( ... )
				std::swap(arr[i], arr[j]);
		}
	}
}
//-----------------------------------------
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); Sort(x, 10, f1);
	Greater f2; f2(1, 2); Sort(X, 10, f2);
}