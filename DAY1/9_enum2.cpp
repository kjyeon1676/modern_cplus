
// C++98 enum
// enum DAYOFWEEK { sum = 0, mon = 1 };
enum class DAYOFWEEK { sum = 0, mon = 1 }; //  C++11 의 새로운 enum

//void foo(int dayofaweek) {} // 모든 정수를 받을수 있게 된다.

void foo(DAYOFWEEK dayofaweek) {} // 요일만 받을수 있다.

int main()
{
//	int n1 = mon; // error. DAYOFWEEK 필요
//	int n2 = DAYOFWEEK::mon;	// error.
								// int 가 아닌 DAYOFWEEK 타입

	DAYOFWEEK n3 = DAYOFWEEK::mon; // ok

	foo(DAYOFWEEK::mon);
}





