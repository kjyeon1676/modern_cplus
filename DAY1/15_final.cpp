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
	virtual void foo()      override final {}  // 더이상 재정의 불가!
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};
// 클래스에 final 이 붙으면 파생 클래스를 만들수 없습니다.
class Derived2 final : public Derived
{
public:
//	virtual void foo()      override  {}	// error
	virtual void goo(int a) override {}			// ok 
};

class Derived3 : public Derived2 // error
{
};

int main()
{
}