// 5_람다표현식6
// 람다표현식은 인자를 받는 방법 - 143p 아래 부분

// 방법 1. 함수 포인터로 받기
// => 캡쳐한 람다 표현식은 받을수 없다.
// => 함수 안에서 f사용시 인라인 치환은 안된다.
// void foo( int(*f)(int, int) ) {} 


// 방법 2. 템플릿 - call by value
// => 가장 널리 사용되는 방법
// => std::find_if() 의 3번째 인자도 이 방식.. 즉, STL 이 사용하는 방식
// => 람다표현식이 만드는 타입은 캡쳐를 많이 하지 않는다면 크기가 크지는 않다
//    복사본의 오버헤드를 고려할 필요는 없다.
template<typename T> void foo(T f) { f(1, 2); }

// 방법 3. 템플릿 - call by reference 
// => error.
// => 람다표현식은 임시객체(rvalue) 이므로 lvalue reference 로 받을수없다.
//template<typename T> void foo(T& f) { f(1, 2); } // error


// 방법 4. 템플릿 - call by const reference
// => f 가 상수 객체가 되므로 "operator()" 가 반드시 상수 함수 이어야 한다.
// => mutable labda 를 받을수는 있지만, 사용할수 없다.
//template<typename T> void foo(const T& f) { f(1, 2); }


// 방법 5. forwarding reference
// => 좋은 방법
// => 특히, 캡쳐를 많이한 람다 같은 경우는 복사본의 오버헤드가 없게 
//    됩니다.
template<typename T> void foo(T&& f) { f(1, 2); }

int main()
{
	foo( [](int a, int b) { return a + b; } );
	foo( [](int a, int b) mutable { return a - b; } );
}


