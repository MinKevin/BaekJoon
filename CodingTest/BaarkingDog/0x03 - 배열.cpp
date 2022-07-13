#include <stdio.h>
#include <stdlib.h>

struct NODE {
	struct NODE *next;
	int data;
};

void addFirst(struct NODE *target, int data) {
	struct NODE* newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;//새 노드의 다음 노드에 
								//기존 노드의 다음 노드를 지정
	newNode->data = data;		//데이터 저장

	target->next = newNode;		//기존 노드의 다음 노드에 새 노드를 지정
}

int main() {
	struct NODE* head = malloc(sizeof(struct NODE)); //머리 노드 생성
	head->next = NULL;

	addFirst(head, 10);
	addFirst(head, 20);
	addFirst(head, 30);

	//연결리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	struct NODE* curr = head->next; 

	while (curr != NULL) {//포인터가 NULL이 아닐 때 계속 반복
		printf("%d \n", curr->data);
		curr = curr->next;
	}

	curr = head->next;
	while (curr != NULL) {
		struct NODE* next = curr->next;
		free(curr);
		curr = next;
	}
}