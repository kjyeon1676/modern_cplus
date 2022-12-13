// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       표현식(expression) 에 부여 되는 개념
// 
// expression : 한개의 값을 나타내는 코드 집합

int main()
{
	int n = 0;

	//(n + 1) * 2 + n;
	//=====================
	n = 10;		// ok.    "n" 이라는 표현식(코드집합)은 lvalue

	n + n = 10;	// error. "n + n" 이라는 표현식은 rvalue

	(n = 20) = 10; // ok.. "n=20" 이라는 표현식은 lvalue

	(n + 1) = 10;  // error. "n+1" 이라는 표현식은 rvalue 

	++n = 10;		// ok.   "++n" 이라는 표현식은 lvalue 
}