// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성사 : 복사 초기화는 사용할수 없고
	//					직접 초기화만 가능하다.
	//				    C++98 문법
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} // Vector v = 10				  

int main()
{
	// 핵심 1. 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);		// C++98. direct initialization
	Vector v2 = 10;		// C++98. copy   initialization

	Vector v3{ 10 };	// C++11. direct initialization
	Vector v4 = { 10 }; // C++11. copy   initialization

	//----------------
	// 핵심 2. 함수의 인자 전달은 복사 초기화 입니다.
	foo(10); // ?
//	foo( Vector(10) ); // 임시객체로 보내거나
//	Vector v;
//	foo(v); // vector를 만든 후 전달..
			// Vector v = v; 이므로 복사 생성자 호출
			// 복사 생성자는 대부분 explicit 가 아닙니다.
}







