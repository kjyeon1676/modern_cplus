#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// promise & future
// => 함수를 스레드에 맞게 수정해야 합니다.

// 1. 스레드로 수행하는 함수는 반드시 promise 객체를 참조로 
//    받아야 합니다
void add(int a, int b, std::promise<int>&& pro)
{
	try
	{
		int c = a + b; // 복잡한 연산 수행후...

		// 결과를 promise 객체를 통해서 알려줍니다.
		pro.set_value(c);
	}
	catch (...)
	{
		// 현재 발생된 예외를 주스레드에 전달. 
		pro.set_exception(std::current_exception());
	}

}

int main()
{
	// 1. promise 객체를 만들고, 미래의 결과를 담은 future 를 꺼내 놓습니다.
	std::promise<int> pro;

	std::future<int> ft = pro.get_future();

	// 2. 스레를 만들때 promise 객체를 참조로 보내야 합니다.
	std::thread t(&add, 1, 2, std::move(pro) );

	std::cout << "main 계속 실행" << std::endl;

	// main 은 계속 작업을 하다가, 결과가 필요하면
	// future 객체를 통해서 대기 하면 됩니다.
	int ret = 0;
	try
	{
		ret = ft.get(); // 1. 결과가 있으면 즉시 꺼내고
						// 2. 없으면 pro.set_value()할때를 대기
						// 3. pro.set_exception()이 실행됐으면
						//    catch()로
	}
	catch (...)
	{

	}

	t.join();
}


