#include <unordered_set>

typedef std::unordered_set<int> SETI;
typedef std::unordered_set<double> SETD;

// "std::unordered_set<int>" �� �ƴ� "std::unordered_set" �� ����������� ������ ?
// ��, Ÿ���� ������ �ƴ� ���ø��� ������ ����� ������ ??
// typedef �� C��� �����̹Ƿ� ���ø��� ������ ����� ����.
// C++11 �� using �� ����

template<typename T>
using SET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;
//	SETI s1;
//	SETD s2;

	SET<int> s1;
	SET<double> s2;


}
