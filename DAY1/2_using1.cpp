#include <unordered_set>

// C 스타일 코드 - typedef 
//typedef int DWORD;
//typedef void(*F)(); 

// C++11 using 
// 아래 2줄이 위 2줄과 완전히 동일합니다.
using DWORD = int;
using F = void(*)();

int main()
{
	DWORD n; // int n
	F     f; // 함수 포인터 f
}