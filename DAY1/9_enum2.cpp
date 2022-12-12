
// C++98 enum
// enum DAYOFWEEK { sum = 0, mon = 1 };

// C++11 �� ���ο� enum
enum class DAYOFWEEK { sum = 0, mon = 1 };

//void foo(int dayofaweek) {} // ��� ������ ������ �ְ� �ȴ�.

void foo(DAYOFWEEK dayofaweek) {} // ���ϸ� ������ �ִ�.

int main()
{
//	int n1 = mon; // error. DAYOFWEEK �ʿ�
//	int n2 = DAYOFWEEK::mon;	// error.
								// int �� �ƴ� DAYOFWEEK Ÿ��

	DAYOFWEEK n3 = DAYOFWEEK::mon; // ok

	foo(DAYOFWEEK::mon);
}





