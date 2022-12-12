// 7_생성자상속1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	// 생성자는 기본적으로 상속 될수 없습니다.
	// C++11 부터 아래처럼 하면 생성자도 상속 됩니다.
	using Base::Base;
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
