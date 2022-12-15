#include <type_traits>

// std::move �� ���� ����� ���� ���� �غ��ô�.

template<typename T>
std::remove_reference_t<T>&& xmove(T&& arg)
{
	// move �� ��ǥ : ���ڷ� ���� ��ü�� rvalue �� ĳ�����ϴ°�
	// ������ �Ʒ� �ڵ�� rvalue ĳ������ �ƴմϴ�.
	// ����   : T �ȿ� ������ ���ԵǾ� ������ �����Ƿ�
	// return static_cast<T&&>(arg);

	// �ذ�å : T �ȿ� �ִ� ������ �������� && �� �ٿ��� ĳ����.  
	return static_cast< std::remove_reference_t<T> &&>(arg);

	// C++11 ��Ÿ��
//	return static_cast<typename std::remove_reference<T>::type &&>(arg);
}


int main()
{

}