#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// 2. async

// promise-future 모델의 단점
// => 반환값으로 결과를 반환하지 않고, promise 사용
// => 아래 같이 스레드를 고려 하지 않은 함수라면
//    코드를 수정했어야 했다.


// std::async()를 사용하면 기존 함수를 변경하지 않고도
// 스레드로 수행할수 있다.

int add(int a, int b)
{
	int c = a + b;

	std::this_thread::sleep_for(3s);

	return c;
}

int main()
{
	std::future<int> ft = std::async(&add, 1, 2);

	std::cout << "주스레드는 계속 실행" << std::endl;

	int ret = ft.get();

	std::cout << ret << std::endl;

}


