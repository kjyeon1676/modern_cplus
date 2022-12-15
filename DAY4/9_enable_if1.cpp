// 6_enable_if1.cpp

// 아래 코드는 C++11 부터 이미 표준에 있습니다.
template<bool, typename T = void > struct enable_if
{
	using type = T; // typedef  T type;
};
template<typename T> struct enable_if<false, T> 
{
	// 1번째 인자가 false 일때는 type 이 없다는 것이 핵심 입니다.
};
int main()
{
	// enable_if 사용법 : enable_if<bool값, 타입(생략시void)>::type

	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1;	// int n1
	enable_if<true>::type       n2;	// void n2 인데, void 변수는 만들수 
									//				없으므로 error
	enable_if<false, int>::type n3; // error. ::type 이 없다
	enable_if<false>::type n4;		// error. ::type 이 없다ㅏ.
}