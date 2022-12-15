#include <iostream>
#include <vector>
#include <algorithm>

struct People
{
	// name, addr
	int age;
	People(int a) : age(a) {}
};

int main()
{
	std::vector<People> v;
	v.emplace_back(10); // v.push_back(People(10)) 의미.
	v.emplace_back(20);
	v.emplace_back(15);

	// 나이가 15살인 사람을 찾고 싶다. ?
	auto ret = std::find_if(v.begin(), v.end(),
		[](const People& p) { return p.age == 15; });

	// 나이가 k살 인 사람을 찾고 싶다. ?
	int k = 15;
	auto ret2 = std::find_if(v.begin(), v.end(),
						[k](const People& p) { return p.age == k;} );

	// 위 코드도 결국, std::find_if 안에 단항함수를 전달하는데..

	// "단항함수 뿐 아니라 지역변수 k" 도 같이 전달하는 코드 입니다.
	// 즉, 클로져 입니다.

	// 람다 표현식도 결국 함수 객체를 만드는 표기법이므로
	// "클로져" 가 될수 있습니다.!!!
	// => 클로져 개념을 꼭 복습해 보세요..
}







