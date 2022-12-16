#include <iostream>
#include <thread>

// �پ��� ����ȭ ������ �����˴ϴ�.
#include <mutex>

std::mutex m;
int shared_data = 10;

/*
void foo()
{
	m.lock();

	// ���� �ڿ� ���	
	shared_data = 200;

	// �ڿ� �ݳ��� ���� �Ʒ�ó�� �����ϸ� �ȵ˴ϴ�.
	// 1. �Ǽ��� unlock ���� �������� �ְ�
	// 2. ���� ���� ��Ȳ�� �߻��Ǿ �Ʒ� ���� �����ϱ� ���Ҽ� �ֽ��ϴ�.
	m.unlock();
}
*/
// �Ʒ� �ڵ尡 ���� �ڵ� �Դϴ�.
// => RAII ���
// => �����ڿ� �Ҹ��ڸ� Ȱ���ؼ� "�ڿ��� �����ϴ� ���"
void foo()
{
	{
		std::lock_guard<std::mutex> g(m);
				// 1. �������� g ��ü�� m �� ������ ����
				// 2. g �����ڿ��� m.lock() ����
				// 3. g �Ҹ��ڿ��� m.unlock() ����

		shared_data = 200;
	}

	//....
}




int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

