class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 사용자가 복사 생성자를 만들지 않으면 컴파일러가 제공합니다.
	// 컴파일러가 복사 생성자를 만들지 않게 하려면
	// 복사 생성자를 삭제하면 됩니다.
	// => 싱글톤 같은 디자인 패턴에서 널리 사용
	// => std::unique_ptr 같은 스마트 포인터가 복사 금지 스마트 포인터
	Point(const Point&) = delete;
};
int main()
{
	Point p1;
	Point p2(1, 2);

	Point p3(p2); // 이 코드가 왜 에러가 없나요 ?
				  // 컴파일러가 만들어주는 복사생성자사용
}