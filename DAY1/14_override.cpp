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
	// ���� �Լ� �����ǽ� �Ǽ�(��Ÿ)
	// => ������ ������ ������ �ƴմϴ�.
	// => ��� ���ο� �����Լ��� �߰��ߴٰ� �����ϰ� �˴ϴ�.
	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
};
class Derived2 : public Base
{
public:
	// C++11 ���� ���� : �����Լ� �����ǽô� �� override ���̼���
	// => �ش� �Լ��� ��� Ŭ������ ������ ������ ����!!
	// => �����Լ� �����ǽ� ������ �ڵ带 ���ؼ�..
	virtual void fooo()        override {} // error
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}
};

int main()
{
}