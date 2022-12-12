// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}
	
	// C++17 의 새로운 if문 
	// => 초기화 구문을 가진 if 문
	// => if ( init; condition) {}
	if ( int ret2 = foo(); ret2 == 0 )
	{

	}	// <= ret2 파괴

	// switch 문도 초기화 구문을 가질수 있습니다.
	switch (int n = foo(); n)
	{
	case 0: break;
	case 1: break;
	}

	// while 도 될까요 ? => 없습니다. 필요하면 for 문 사용하면됩니다.
//	while (int cnt = 0; cnt < 9)
//	{
//	}
}