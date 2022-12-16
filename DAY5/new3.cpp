// new1
#include <iostream>

struct Point
{
	int x, y;

	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point(int, int)" << std::endl; }
};

int main()
{
	// 3개짜리 버퍼를 사용했습니다.
	Point* buff = new Point[3];

	// 그런데 5개로 버퍼를 키워야 합니다.
	// => 아래 처럼 하면 새로운 버퍼의 5개 객체에 대해 생성자가 호출됩니다.
	// => 어차피, 이전 버퍼를 복사하면 되므로 생성자 호출할 필요 없다.
	// Point* temp = new Point[5]; // bad!!!! 

	Point* temp = static_cast<Point>(operator new(sizeof(Point) * 5));

	// 앞의 3개는 기존 버퍼의 객체를 복사(이동)생성하면 됩니다.
	for (int i = 0; i < 3; i++)
	{
	//	new(&temp[i]) Point;			// 디폴트 생성자
	//	new(&temp[i]) Point(buff[i]);	// 복사 생성자
	//	new(&temp[i]) Point(std::move(buff[i]));	// move 생성자
		new(&temp[i]) Point(std::move_if_noexcept(buff[i])); // move 생성자
	}

	// 새로운 2개는 디폴트 생성자로 초기화
	for (int i = 3; i < 5; i++)
	{
		new(&temp[i]) Point;
	}

	// 기존 버퍼제거 - 기존 버퍼는 new로 했으므로 delete 사용
	delete[] buff;

	buff = temp;
}



