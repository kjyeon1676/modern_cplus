#include <iostream>
#include <vector>

// 사용자 정의 타입을 새로운 for 문에 넣으려면
// begin/end 가 제공되면 됩니다.
struct Point3D
{
	int x, y, z;

	int* begin() { return &x; }
	int* end()   { return &z + 1; }
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // 될까요 ? 되게하려면 필요한 것은 ?
		std::cout << n << std::endl; 

}















