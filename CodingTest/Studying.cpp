#include <iostream>
#include <algorithm>

int main() {
	int value = 5, value2 = 11;
	 const int * ptr = &value;

	std::cout << *ptr;//5
	std::cout << ptr;//주소값
	
	//상수를 가리키는 포인터가 가리키는 공간은 수정할 수 없는(conost) 공간이지만
	//*ptr = value2; <= 불가능
	// 
	//상수 변수의 주소를 가리키는 포인터는 수정할 수 있는 포인터
	ptr = &value2;

	/*
	const형식은 여러번 초기화 불가능
	컴파일 시 오류
	int const a = 10;
	int const a = 20;

	std::cout << a;
	*/

	/*
	상수 포인터
	위에서 나왔던 포인터는 가리키는 값은 변경 불가능하지만 다른 변수의 주소값으로 변경이 가능
	but 상수 포인터는 위와 반대로 주소를 바꿀 수 없음(값은 변경 가능)

	*/
	int* const ptr2 = &value;
	//주소 변경 시도는 오류
	//ptr2 = &value;

	*ptr2 = value2;


	/*
	상수를 가리키는 상수 포인터
	값과 주소 모두 변경 불가능
	*/
	const int* const ptr3 = &value;
	

	return 0;
}