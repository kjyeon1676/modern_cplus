int main()
{
	int  n1 = 3.4; // ok. 경고는 발생. 하지만 아주 나쁜 코드!
	char c1 = 500; // 오버플로우이지만 허용

	// prevent narrow - 56 page 중간부분
	// => {} 초기화는 기존 초기화 보다 엄격합니다.
	int n2{ 3.4 };  // error
	char c2{ 500 }; // error

	int n3 = { 3.4 }; // error

}