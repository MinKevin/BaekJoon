#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

string str, boom, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("공부중/input.txt", "r", stdin);
    //freopen("공부중/output.txt", "w", stdout);
    int arr[3] = { 1, 2, 3 };
    vector<int> v(3, 1);

    int n = 10;
    
    cin >> n;
    cout << n + 100;
}