#include <unordered_set>

typedef std::unordered_set<int> SETI;
typedef std::unordered_set<double> SETD;

// "std::unordered_set<int>" 가 아닌 "std::unordered_set" 의 별명을만들수 없을까 ?
// 즉, 타입의 별명이 아닌 템플릿의 별명을 만들수 없을까 ??
// typedef 는 C언어 문법이므로 템플릿의 별명을 만들수 없다.
// C++11 의 using 은 가능

template<typename T>
using SET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;
//	SETI s1;
//	SETD s2;

	SET<int> s1;
	SET<double> s2;


}
