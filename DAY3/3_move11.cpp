// 105 page.. ��� ��ü�� move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	//move

	// �����ü�� move �ɼ� �����ϴ�.
	const Object o3;
	Object o4 = std::move(o3);	// copy	
				// => static_cast< o3Ÿ��&& >(o3)
				// => static_cast< const Object && >(o3)

}



