#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string buf = "a" + 1;
    cout << buf << '\n'; // �ƹ��͵� ��µ��� ����

    /*
    vector<int> v3 = {1,2,3};
    vector<int> v4;
    v4 = v3;
    v4[2] = 10;
    cout << v3[2];
    */

    /*
    int numArr[3][4] = {    // ���� 3, ���� 4 ũ���� int�� 2���� �迭 ����
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 110, 121, 132 }
    };

    int(*numPtr)[4] = numArr;

    printf("%p\n", *numPtr); // 002BFE5C: 2���� �迭 �����͸� �������ϸ� ���� ù ��°�� �ּҰ� ����
                             // ��ǻ�͸���, ������ ������ �޶���

    printf("%p\n", *numArr); // 002BFE5C: 2���� �迭�� �������ϸ� ���� ù ��°�� �ּҰ� ����
                             // ��ǻ�͸���, ������ ������ �޶���

    printf("%d\n", numPtr[2][1]);    // 110: 2���� �迭 �����ʹ� �ε����� ������ �� ����

    printf("%d\n", sizeof(numArr));  // 48: sizeof�� 2���� �迭�� ũ�⸦ ���ϸ� �迭�� �޸𸮿� 
                                     // �����ϴ� ������ ��µ�

    printf("%d\n", sizeof(numPtr));  // 4 : sizeof�� 2���� �迭 �������� ũ�⸦ 
                                     // ���ϸ� �������� ũ�Ⱑ ��µ�(64��Ʈ��� 8)
    */
    return 0;
}