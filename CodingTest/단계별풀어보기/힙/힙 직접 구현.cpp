#include <iostream>

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

using namespace std;

int heap[HEAP_SIZE];
int heapCount = 0;
//int* a => a값에 a의 주소값이 저장
void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void push(int x) {
	heap[++heapCount] = x;

	int child = heapCount;
	int parent = child / 2;

	while (child > 1 && heap[child] > heap[parent]) {
		swap(&heap[child], &heap[parent]);
		child = parent;
		parent = child / 2;
	}
}


int pop() {
	int ret = heap[1];
	swap(&heap[1], &heap[heapCount--]);

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heapCount)
		child = (heap[child] > heap[child + 1]) ? child : child + 1;

	while (child <= heapCount && heap[child] > heap[parent]) {
		swap(&heap[child], &heap[parent]);

		parent = child;
		child = parent * 2;

		if (child + 1 <= heapCount)
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	return ret;
}


int main() {
	int a[ARRAY_SIZE] = { 5, 6, 3, 7, 9, 8, 1, 2, 4, 10 };
	cout << "Push : \n";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout <<  a[i] << '\n';
		push(a[i]);
		for (int i = 1; i <= heapCount; i++)
			cout << heap[i] << ' ';
		cout << '\n';
	}
	cout << '\n';

	printf("Pop : ");
	//최대 힙에서 차례대로 pop()한 결과.
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << pop() << ' ';
	}
	printf("\n");
	return 0;
}

/*Result
Push :
5
5
6
6 5
3
6 5 3
7
7 6 3 5
9
9 7 3 5 6
8
9 7 8 5 6 3
1
9 7 8 5 6 3 1
2
9 7 8 5 6 3 1 2
4
9 7 8 5 6 3 1 2 4
10
10 9 8 5 7 3 1 2 4 6

Pop : 9 8 7 6 5 4 3 2 1 1
*/