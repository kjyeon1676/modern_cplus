// 9_enum - 32 page

void foo(int dayofaweek) {}

enum DAYOFWEEK { sum = 0, mon = 1};

int main()
{
	foo(0);		// 0 : 일요일, 1 : 월요일
				// => 가독성이 나쁘다.

	foo(DAYOFWEEK::mon);	// 이렇게 해도 되고.
	foo(mon);				// 이렇게 해도 됩니다.
							// unscoped enum
							// 지역변수등과 이름충돌가능성
	int mon = 100;			// 높음.. 
	foo(mon);	// 지역변수 
}





