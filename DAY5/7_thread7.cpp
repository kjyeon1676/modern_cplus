#include <atomic>
// godbolt.org
int a = 0;
int b = 0;

// foo, goo �� �ٸ� �����尡 �����մϴ�.
void foo()
{
	a = b + 1;

	// �� �ڵ�� �Ʒ� �ڵ尡 ���θ� ħ���Ҽ� ������
	// �潺�� ��ġ �մϴ�.
	std::atomic_thread_fence(std::memory_order_seq_cst);

	b = 1;
}

void goo()
{
	if (b == 1)
	{
		// �ٽ�!!! a�� �ݵ�� 1�ϱ�� ?
	}
}

int main()
{
}