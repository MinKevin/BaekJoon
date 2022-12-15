/*
Date : 22.12.07
Time : 00:39
Comment : 
	힙을 제대로 이해하고 손으로 짤 수 있게 된 부분에 만족한다.
	몇번 더 복습해서 완전히 채화하자!

*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int heap[100001];
int heapCount = 0;
vector<int> answer;

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int abs(int x) {
	return (x >= 0) ? x : -x;
}

void push(int x) {
	heap[++heapCount] = x;

	int child = heapCount;
	int parent = heapCount / 2;

	while (child > 1){
		if (abs(heap[child]) < abs(heap[parent]) || abs(heap[child]) == abs(heap[parent]) && heap[child] < heap[parent]) {
			swap(&heap[child], &heap[parent]);

			child = parent;
			parent = child / 2;
		}
		else
			break;
	}
}

int pop() {
	if (heapCount == 0)
		return 0;

	int ret = heap[1];
	swap(&heap[1], &heap[heapCount--]);
	
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heapCount) {
		if (abs(heap[child]) > abs(heap[child + 1]) || abs(heap[child]) == abs(heap[child + 1]) && heap[child] > heap[child + 1])
			child = child + 1;
	}
		

	while (child <= heapCount) {
		if (abs(heap[child]) < abs(heap[parent]) || abs(heap[child]) == abs(heap[parent]) && heap[child] < heap[parent]) {
			swap(&heap[child], &heap[parent]);
			parent = child;
			child = parent * 2;

			if (child + 1 <= heapCount) {
				if (abs(heap[child]) > abs(heap[child + 1]) || abs(heap[child]) == abs(heap[child + 1]) && heap[child] > heap[child + 1])
					child = child + 1;
			}
		}
		else
			break;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int order;
	while (N--) {
		cin >> order;
		if (order == 0)
			answer.push_back(pop());
		else
			push(order);

		/*test
		cout << "Heap : ";
		for (int i = 1; i <= heapCount; i++)
			cout << heap[i] << ' ';
		cout << '\n';
		cout << "heapCount : " << heapCount << '\n';
		*/
	}

	for (auto v : answer)
		cout << v << '\n';
}