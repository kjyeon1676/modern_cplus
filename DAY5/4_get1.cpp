#include <iostream>
using namespace std;

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;

	cout << d.value << endl; // 20. derived value

	cout << (static_cast<Base&>(d)).value << endl; 
							// 10. base value
		
}