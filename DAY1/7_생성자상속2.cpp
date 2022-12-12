#include <list>

// STL 컨테이너에서 상속 받는 것은 권장하지 않습니다.
class MyList : public std::list<int>
{
public:
	using std::list<int>::list;

	void dump() {}
};

int main()
{
	// MyList 를 STL list 처럼 사용하고 싶습니다.
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
	MyList st3 = { 1,2,3,4,5 };
}




