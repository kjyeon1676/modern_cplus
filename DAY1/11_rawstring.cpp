// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// �Ϲ� ���ڿ������� "\"�� Ư�� ������ ����
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw string : "\" �� �Ϲ� ���ڷ� ó���� �޶�.
	// R : RawString �̶�� �ǹ�
	// "( : ���ڿ� ����
	// )" : ���ڿ� ����
	s1 = R"(\\\\.\\pipe\\server)";

	// ���ڿ� �߰��� "�� �ʿ� �ϸ�
	s1 = R"(\\"\\.\\pi'pe\\server)";


	// ���ڿ� �߰��� )"  �� �ʿ� �ϸ� ?
	s1 = R"***(\\\\.\\pi)"pe\\server)***";


	std::cout << s1 << std::endl;
}