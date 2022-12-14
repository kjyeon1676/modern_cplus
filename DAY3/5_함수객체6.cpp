// 아래 주석을 이해해 보세요
// 1. 일반 함수는 자신만의 타입이 없다.
//    => signature(함수인자와 리턴타입모양)가 동일한 모든 함수는 같은 타입이다.

// 2. 함수객체는 자신만의 타입이 있다.
//    => signature(함수인자와 리턴타입모양)가 동일해도
//       모든 함수객체를 다른 타입이다.

struct Less 
{ 
	inline bool operator()(int a, int b) const { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) const { return a > b; }
};
//------------------------------------------------
// 비교 정책을 교체할수 있고, 
// 비교 정책 자체를 인라인 치환 할수 있는 Sort
// 템플릿 과 함수 객체로 만드는 기술
// STL 의 핵심 설계 원리.
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