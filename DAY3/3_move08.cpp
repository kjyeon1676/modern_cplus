#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 1. 사용자가 복사 계열과 move 계열의 멤버함수를 모두 제공하지 않으면
// => 컴파일러가 모두 제공한다.
// => 복사 계열에서는 모든 멤버를 복사해주고
// => 이동 계열에서는 모든 멤버를 move해준다.

// 규칙 2. 사용자가 복사 계열만 제공한 경우
// => 컴파일러가 move 계열을 제공하지 않는다.
// => std::move() 사용시 사용자가 만든 복사 생성자 사용. 

// => 이 경우 컴파일러에게 디폴트 버전을 요청하려면 "= default" 를 사용하면됩니다.


// 규칙 3. 사용자가 move 계열만 제공한 경우
// => 복사 계열의 함수는 "삭제" 됩니다.
// => 복사 생성자가 필요한 코드는 모두 에러 입니다.
// => 물론 이경우도 "=default" 로 요청은 가능합니다.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}

	Object(Object&& obj) : name(std::move(obj.name)) { std::cout << "move" << std::endl; }

	/*
	// 복사를 사용자가 만들고, 나머지는 컴파일러에게 요청하는 코드
	Object(const Object& obj) : name(obj.name) { std::cout << "copy" << std::endl; }

	Object(Object&&) = default;
	Object& operator=(Object&&) = default;
	Object& operator=(const Object&) = default;
	*/
};



int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}