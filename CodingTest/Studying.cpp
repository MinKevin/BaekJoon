#include <iostream>
#include <algorithm>

int main() {
	int value = 5, value2 = 11;
	 const int * ptr = &value;

	std::cout << *ptr;//5
	std::cout << ptr;//�ּҰ�
	
	//����� ����Ű�� �����Ͱ� ����Ű�� ������ ������ �� ����(conost) ����������
	//*ptr = value2; <= �Ұ���
	// 
	//��� ������ �ּҸ� ����Ű�� �����ʹ� ������ �� �ִ� ������
	ptr = &value2;

	/*
	const������ ������ �ʱ�ȭ �Ұ���
	������ �� ����
	int const a = 10;
	int const a = 20;

	std::cout << a;
	*/

	/*
	��� ������
	������ ���Դ� �����ʹ� ����Ű�� ���� ���� �Ұ��������� �ٸ� ������ �ּҰ����� ������ ����
	but ��� �����ʹ� ���� �ݴ�� �ּҸ� �ٲ� �� ����(���� ���� ����)

	*/
	int* const ptr2 = &value;
	//�ּ� ���� �õ��� ����
	//ptr2 = &value;

	*ptr2 = value2;


	/*
	����� ����Ű�� ��� ������
	���� �ּ� ��� ���� �Ұ���
	*/
	const int* const ptr3 = &value;
	

	return 0;
}