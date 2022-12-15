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
		std::cout << "memcpy 사용" << std::endl;
		memcpy(dst, src, sizeof(T) * sz);
	}
	else
	{
		std::cout << "복사생성자가 trivial 하지 않은 경우" << std::endl;

		while (sz--)
		{
			new(dst) T(*src); //  복사 생성자 호출
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
