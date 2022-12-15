// 1_가변인자템플릿1-1

// 타입 인자가 한개인 함수 템플릿
template<typename T> void foo(T arg)
{

}

int main()
{
	foo(1);
	foo(3.4);
}