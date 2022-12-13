#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello"); // 되야 합니다.!!! 논리적으로 맞습니다.
				  // 됩니다!!
				  // string s = "hello" 가 된다는 의미
					// "string(const char*)" 모양의 생성자가 explicit가
					// 아니라는 의미 입니다.
	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok 


	goo(10); // 논리적으로 틀립니다. 안되야 합니다.
			 // 안됩니다.
			 // "vector<int> v = 10" 이 에러
			 // "vector(int)"의 모양의 생성자가 explicit 
	
	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error

}





