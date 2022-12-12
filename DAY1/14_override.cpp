// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// 가상 함수 재정의시 실수(오타)
	// => 하지만 컴파일 에러가 아닙니다.
	// => 모두 새로운 가상함수를 추가했다고 생각하게 됩니다.
	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
};
class Derived2 : public Base
{
public:
	// C++11 부터 권장 : 가상함수 재정의시는 꼭 override 붙이세요
	// => 해당 함수가 기반 클래스에 없으면 컴파일 에러!!
	// => 가상함수 재정의시 안전한 코드를 위해서..
	virtual void fooo()        override {} // error
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}
};

int main()
{
}