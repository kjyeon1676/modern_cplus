

// �������� Ŭ���� ���ø�
// => ���������� "T" �� �ƴ� ���������� ǥ���մϴ�.
// => "Types", "Ts" ��..
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, int> t2;			// Types : int, int
	tuple<int, int, double> t3;	// Types : int, int double
}