#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// 2. async

// promise-future ���� ����
// => ��ȯ������ ����� ��ȯ���� �ʰ�, promise ���
// => �Ʒ� ���� �����带 ��� ���� ���� �Լ����
//    �ڵ带 �����߾�� �ߴ�.


// std::async()�� ����ϸ� ���� �Լ��� �������� �ʰ�
// ������� �����Ҽ� �ִ�.

int add(int a, int b)
{
	int c = a + b;

	std::this_thread::sleep_for(3s);

	return c;
}

int main()
{
	std::future<int> ft = std::async(&add, 1, 2);

	std::cout << "�ֽ������ ��� ����" << std::endl;

	int ret = ft.get();

	std::cout << ret << std::endl;

}


