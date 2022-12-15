#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;
};

template<typename T> 
void copy_type(T* dst, T* src, std::size_t sz)
{
	if constexpr (std::is_trivially_copy_constructible_v<T>)
	{
		std::cout << "memcpy ���" << std::endl;
		memcpy(dst, src, sizeof(T) * sz);
	}
	else
	{
		std::cout << "��������ڰ� trivial ���� ���� ���" << std::endl;

		while (sz--)
		{
			new(dst) T(*src); //  ���� ������ ȣ��
			++dst, ++src;
		}
	}
}

int main()
{
	Point buff1[10];
	Point buff2[10];

	copy_type(buff1, buff2, 10);
}
