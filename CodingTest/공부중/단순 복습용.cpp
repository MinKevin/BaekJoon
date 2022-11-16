#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

string str, boom, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    int arr[3] = { 1, 2, 3 };
    vector<int> v(3, 1);

    int n = 10;
    
    cin >> n;//한글
    cout << n;
}