// 아래 주석을 이해해 보세요
// 1. 일반 함수는 자신만의 타입이 없다.
//    => signature 가 동일한 모든 함수는 같은 타입이다.

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