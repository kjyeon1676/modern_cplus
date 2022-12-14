// 3_move15 - 10�� ����
#include <iostream>
#include <vector>
#include <type_traits>
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
// T& : ���ڷ� lvalue �� �ްڴٴ� �� 
// T&&: ���ڷ� lvalue �� rvalue �� ��� �ްڴٴ� ��

// move �� lvalue �� rvalue �� ��� ������ �־�� �մϴ�.
template<typename T>
std::remove_reference_t<T>&&  xmove(T&& obj)
{
	// ���ڷ� T&& �� ����Ҷ� �Ʒ� ĳ������ ���� rvalue ĳ������ �ƴմϴ�.
	// ���ڷ� lvalue �� ������ static_cast<Object&>(obj)
	// ���ڷ� rvalue �� ������ static_cast<Object&&>(obj)
	// ��, ��Ȳ�� ���� �ٸ� ĳ�����Դϴ�.
	// static_cast<T&&>(obj);

	// move �� ��ǥ�� ������ rvalue �� ĳ�����ؾ� �մϴ�.
	return static_cast< std::remove_reference_t<T> &&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;			// copy
	Object o3 = xmove(o1);	// move

	Object o4 = xmove(Object()); // move

}

