#include <iostream>
#include <thread>

// 다양한 동기화 도구도 제공됩니다.
#include <mutex>

std::mutex m;
int shared_data = 10;

/*
void foo()
{
	m.lock();

	// 공유 자원 사용	
	shared_data = 200;

	// 자원 반납은 절대 아래처럼 직접하면 안됩니다.
	// 1. 실수로 unlock 하지 않을수도 있고
	// 2. 예외 등의 상황이 발생되어서 아래 줄을 실행하기 못할수 있습니다.
	m.unlock();
}
*/
// 아래 코드가 좋은 코드 입니다.
// => RAII 기술
// => 생성자와 소멸자를 활용해서 "자원을 관리하는 기술"
void foo()
{
	{
		std::lock_guard<std::mutex> g(m);
				// 1. 지역변수 g 객체를 m 을 참조로 보관
				// 2. g 생성자에서 m.lock() 수행
				// 3. g 소멸자에서 m.unlock() 수행

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

