#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	std::string s3 = s1;	// s1 이 사용하는 자원을
							// s3 가 깊은 복사!

	std::string s4 = std::move(s2);
							// s2 의 자원을
							// s4 로 이동
							// s2 는 이제 자원 없음.

	std::cout << s1 << std::endl; // "to be or not to be"
	std::cout << s2 << std::endl; // ""


}

