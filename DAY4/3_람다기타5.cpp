// 5_����ǥ����6
// ����ǥ������ ���ڸ� �޴� ��� - 143p �Ʒ� �κ�

// ��� 1. �Լ� �����ͷ� �ޱ�
// => ĸ���� ���� ǥ������ ������ ����.
// => �Լ� �ȿ��� f���� �ζ��� ġȯ�� �ȵȴ�.
// void foo( int(*f)(int, int) ) {} 


// ��� 2. ���ø� - call by value
// => ���� �θ� ���Ǵ� ���
// => std::find_if() �� 3��° ���ڵ� �� ���.. ��, STL �� ����ϴ� ���
// => ����ǥ������ ����� Ÿ���� ĸ�ĸ� ���� ���� �ʴ´ٸ� ũ�Ⱑ ũ���� �ʴ�
//    ���纻�� ������带 ����� �ʿ�� ����.
template<typename T> void foo(T f) { f(1, 2); }

// ��� 3. ���ø� - call by reference 
// => error.
// => ����ǥ������ �ӽð�ü(rvalue) �̹Ƿ� lvalue reference �� ����������.
//template<typename T> void foo(T& f) { f(1, 2); } // error


// ��� 4. ���ø� - call by const reference
// => f �� ��� ��ü�� �ǹǷ� "operator()" �� �ݵ�� ��� �Լ� �̾�� �Ѵ�.
// => mutable labda �� �������� ������, ����Ҽ� ����.
//template<typename T> void foo(const T& f) { f(1, 2); }


// ��� 5. forwarding reference
// => ���� ���
// => Ư��, ĸ�ĸ� ������ ���� ���� ���� ���纻�� ������尡 ���� 
//    �˴ϴ�.
template<typename T> void foo(T&& f) { f(1, 2); }

int main()
{
	foo( [](int a, int b) { return a + b; } );
	foo( [](int a, int b) mutable { return a - b; } );
}


