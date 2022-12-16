#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// promise & future
// => �Լ��� �����忡 �°� �����ؾ� �մϴ�.

// 1. ������� �����ϴ� �Լ��� �ݵ�� promise ��ü�� ������ 
//    �޾ƾ� �մϴ�
void add(int a, int b, std::promise<int>&& pro)
{
	try
	{
		int c = a + b; // ������ ���� ������...

		// ����� promise ��ü�� ���ؼ� �˷��ݴϴ�.
		pro.set_value(c);
	}
	catch (...)
	{
		// ���� �߻��� ���ܸ� �ֽ����忡 ����. 
		pro.set_exception(std::current_exception());
	}

}

int main()
{
	// 1. promise ��ü�� �����, �̷��� ����� ���� future �� ���� �����ϴ�.
	std::promise<int> pro;

	std::future<int> ft = pro.get_future();

	// 2. ������ ���鶧 promise ��ü�� ������ ������ �մϴ�.
	std::thread t(&add, 1, 2, std::move(pro) );

	std::cout << "main ��� ����" << std::endl;

	// main �� ��� �۾��� �ϴٰ�, ����� �ʿ��ϸ�
	// future ��ü�� ���ؼ� ��� �ϸ� �˴ϴ�.
	int ret = 0;
	try
	{
		ret = ft.get(); // 1. ����� ������ ��� ������
						// 2. ������ pro.set_value()�Ҷ��� ���
						// 3. pro.set_exception()�� ���������
						//    catch()��
	}
	catch (...)
	{

	}

	t.join();
}


