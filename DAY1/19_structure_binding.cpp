// 19_structure_binding - 52 page
#include <map>
#include <string>
#include <iostream>
struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// 모든 멤버를 꺼내고 싶다.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// C++17 부터는 아래처럼 사용가능합니다.
	// => structure binding 이라는 문법 입니다.
	auto [a1, a2, a3] = p3d; // auto a1 = p3d.x;
							 // auto a2 = p3d.y;
							 // auto a3 = p3d.z;

//	int [a1, a2, a3] = p3d; // error. auto 만 가능
//	auto[a1, a2] = p3d; // error. 갯수가 같아야 합니다.

	int arr[3] = { 1,2,3 };
	auto [b1, b2, b3] = arr;


	//-------------------------
	std::map<std::string, std::string> m;

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";

	m.insert(p);	// pair 를 넣거나
	m["mon"] = "월요일";	// []를 사용하거나

	// C++14 까지 맵의 모든 요소 순회 
	for (auto& p : m)
	{
		// map 은 pair 를 보관하므로 p는 pair 입니다.
		auto key = p.first;
		auto value = p.second;

	}

	// C++17 부터는 아래 처럼 하세요
	for (auto& [key, value] : m)
	{
		std::cout << key << ", " << value << std::endl;
	}
}

