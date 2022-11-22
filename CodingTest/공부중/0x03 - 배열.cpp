#include <stdio.h>
#include <stdlib.h>

struct NODE {
	struct NODE *next;
	int data;
};

void addFirst(struct NODE *target, int data) {
	struct NODE* newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;//占쏙옙 占쏙옙占쏙옙占?占쏙옙占쏙옙 占쏙옙恙?
								//占쏙옙占쏙옙 占쏙옙占쏙옙占?占쏙옙占쏙옙 占쏙옙躍?占쏙옙占쏙옙
	newNode->data = data;		//占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙

	target->next = newNode;		//占쏙옙占쏙옙 占쏙옙占쏙옙占?占쏙옙占쏙옙 占쏙옙恙?占쏙옙 占쏙옙躍?占쏙옙占쏙옙
}

int main() {
	struct NODE* head = malloc(sizeof(struct NODE)); //占쌈몌옙 占쏙옙占?占쏙옙占쏙옙
	head->next = NULL;

	addFirst(head, 10);
	addFirst(head, 20);
	addFirst(head, 30);

	//占쏙옙占써리占쏙옙트 占쏙옙회占쏙옙 占쏙옙占쏙옙占싶울옙 첫 占쏙옙째 占쏙옙占쏙옙占?占쌍쇽옙 占쏙옙占쏙옙
	struct NODE* curr = head->next; 

	while (curr != NULL) {//占쏙옙占쏙옙占싶곤옙 NULL占쏙옙 占싣댐옙 占쏙옙 占쏙옙占?占쌥븝옙
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