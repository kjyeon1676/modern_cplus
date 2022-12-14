#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// �ٽ� : move �迭 �Լ��� ���鶧��
	// => �ǵ��� ���ܰ� �߻����� �ʰ� ���弼��
	// => �׸���, ���ܰ� ������ �˸��� ���� �� noexcept �� ���̼���

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};
int main()
{
	Object o1;
	Object o2 = o1; // �׻� ���� ������ ���
	Object o3 = std::move(o1); // �׻� move ������ ���
	Object o4 = std::move_if_noexcept(o2); // �ٽ�
						// => move �����ڿ� ���ܰ� ������ move �����ڻ��
						// => move �����ڿ� ���� ���ɼ��� ������ copy ���


	std::vector<Object> v(3);

	std::cout << "----------------" << std::endl;

	v.resize(5); // �̼����� ������ �����غ��ô�.

	std::cout << "----------------" << std::endl;
}

