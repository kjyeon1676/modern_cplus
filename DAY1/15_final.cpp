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
	virtual void foo()      override final {}  // ���̻� ������ �Ұ�!
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};
// Ŭ������ final �� ������ �Ļ� Ŭ������ ����� �����ϴ�.
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