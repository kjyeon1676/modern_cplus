#include <iostream>
#include <string>
#include <vector>

// move ����

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	std::string s3 = s1;	// s1 �� ����ϴ� �ڿ���
							// s3 �� ���� ����!

	std::string s4 = std::move(s2);
							// s2 �� �ڿ���
							// s4 �� �̵�
							// s2 �� ���� �ڿ� ����.

	std::cout << s1 << std::endl; // "to be or not to be"
	std::cout << s2 << std::endl; // ""


}

