#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello"); // �Ǿ� �մϴ�.!!! �������� �½��ϴ�.
				  // �˴ϴ�!!
				  // string s = "hello" �� �ȴٴ� �ǹ�
					// "string(const char*)" ����� �����ڰ� explicit��
					// �ƴ϶�� �ǹ� �Դϴ�.
	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok 


	goo(10); // �������� Ʋ���ϴ�. �ȵǾ� �մϴ�.
			 // �ȵ˴ϴ�.
			 // "vector<int> v = 10" �� ����
			 // "vector(int)"�� ����� �����ڰ� explicit 
	
	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error

}





