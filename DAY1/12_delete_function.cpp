// 12_delete_function 37 page

int gcd(int a, int b) 
{
	// 최대 공약수 반환
	return 0;
}

double gcd(double a, double b) = delete; // C++11 함수 삭제 문법

int main()
{
	gcd(10, 20);
	gcd(1.3, 3.4); // 에러가 나오게 하고 싶습니다.
}
