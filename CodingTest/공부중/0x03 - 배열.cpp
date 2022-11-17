#include <stdio.h>
#include <stdlib.h>

struct NODE {
	struct NODE *next;
	int data;
};

void addFirst(struct NODE *target, int data) {
	struct NODE* newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;//�� ����� ���� ��忡 
								//���� ����� ���� ��带 ����
	newNode->data = data;		//������ ����

	target->next = newNode;		//���� ����� ���� ��忡 �� ��带 ����
}

int main() {
	struct NODE* head = malloc(sizeof(struct NODE)); //�Ӹ� ��� ����
	head->next = NULL;

	addFirst(head, 10);
	addFirst(head, 20);
	addFirst(head, 30);

	//���Ḯ��Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
	struct NODE* curr = head->next; 

	while (curr != NULL) {//�����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
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