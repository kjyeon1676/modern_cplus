#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

int main()
{
    // C++표준(C++98) 에 이미 modulus 함수 객체가 있습니다.
    std::modulus<int> m;

    int n = m(10, 3);   // 10 % 3 즉, 1
                        // 이항 함수 객체

    //---------------------------------------
    int x[5] = { 9, 9,2,4,3};

    // 3의 배수가 아닌 것을 찾고 싶다.!
    // => % 연산을 수행하는 함수(함수객체)가 필요 
//  auto p = std::find_if ( x, x+5, m ); // error
                            // m 은 이항함수 객체인데.
                            // find_if 는 단항함수를 요구!!

    auto p = std::find_if(x, x + 5, std::bind(m, _1, 3) ); 
                            // ok.!!!
                            // 그런데, 이경우는 std::bind 보다는
                            // 그냥 람다 표현식을 권장합니다.
    // ASIO 라는 네트워크 라이브러리는 위 코드처럼 "상수 3" 이 아니라
    // 객체를 고정해야 하는 경우들이 많습니다.
    // => 그래서, 위와 같은 형태의 코드가 아주 많습니다.
}

















//












//
