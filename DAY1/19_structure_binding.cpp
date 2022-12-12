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

	// ��� ����� ������ �ʹ�.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// C++17 ���ʹ� �Ʒ�ó�� ��밡���մϴ�.
	// => structure binding �̶�� ���� �Դϴ�.
	auto [a1, a2, a3] = p3d; // auto a1 = p3d.x;
							 // auto a2 = p3d.y;
							 // auto a3 = p3d.z;

//	int [a1, a2, a3] = p3d; // error. auto �� ����
//	auto[a1, a2] = p3d; // error. ������ ���ƾ� �մϴ�.

	int arr[3] = { 1,2,3 };
	auto [b1, b2, b3] = arr;


	//-------------------------
	std::map<std::string, std::string> m;

	// map�� pair�� �����մϴ�.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "ȭ����";

	m.insert(p);	// pair �� �ְų�
	m["mon"] = "������";	// []�� ����ϰų�

	// C++14 ���� ���� ��� ��� ��ȸ 
	for (auto& p : m)
	{
		// map �� pair �� �����ϹǷ� p�� pair �Դϴ�.
		auto key = p.first;
		auto value = p.second;

	}

	// C++17 ���ʹ� �Ʒ� ó�� �ϼ���
	for (auto& [key, value] : m)
	{
		std::cout << key << ", " << value << std::endl;
	}
}

