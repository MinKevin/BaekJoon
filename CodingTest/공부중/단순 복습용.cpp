#include <iostream>

using namespace std;


int main(void)
vector<int> vec(1000000, 0);

// 단순 for문
void test1() {
    int size = vec.size();
    for (int i = 0; i < size; i++);
}

// 이터레이터 사용
void test2() {
    for (auto i = ob.begin(); i != vec.end(); i++);
}

// for_each
void test3() {
    for_each(vec.begin(), vec.end(), [](int item) {});
}