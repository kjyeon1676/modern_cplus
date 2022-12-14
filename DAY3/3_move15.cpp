// 3_move15 - 10�� ����
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

// std::move �� ����� ���ô�.
template<typename T>
T&& xmove(T& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1; 
	Object o3 = xmove(o1); 

}

