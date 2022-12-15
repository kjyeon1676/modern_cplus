#include <iostream>
#include <type_traits>


// std::enable_if<����, Ÿ��>::type  ���� "::type" ��
// 
// => ������ true  �̸� "Ÿ��"
// => ������ flase �̸� "::type" �� �����ϴ�.
//    => SFINAE ��Ģ�� ���ؼ� "::type" �� ������ ������ �ƴ϶�
//		 �ĺ����� ������ �˴ϴ�.

// �ǹ� : ������ true �̸� ����ϰ�!!
//		  ������ false �̸� ������� �ʰڴٴ� �ǵ�(������ �ƴ� �ĺ�����)
template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T>::type 

std::enable_if_t< std::is_integral_v<T>, T>   // C++14 ����

gcd(T a, T b)
{
	return 0;
}




double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1, 5.4);	
	gcd(3.1f, 5.4f);
}