// 9_enum - 32 page

void foo(int dayofaweek) {}

enum DAYOFWEEK { sum = 0, mon = 1};

int main()
{
	foo(0);		// 0 : �Ͽ���, 1 : ������
				// => �������� ���ڴ�.

	foo(DAYOFWEEK::mon);	// �̷��� �ص� �ǰ�.
	foo(mon);				// �̷��� �ص� �˴ϴ�.
							// unscoped enum
							// ����������� �̸��浹���ɼ�
	int mon = 100;			// ����.. 
	foo(mon);	// �������� 
}





