

// 가변인자 클래스 템플릿
// => 관례적으로 "T" 가 아닌 복수형으로 표기합니다.
// => "Types", "Ts" 등..
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, int> t2;			// Types : int, int
	tuple<int, int, double> t3;	// Types : int, int double
}