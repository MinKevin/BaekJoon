

#include <iostream>

using namespace std;

int N;

int func() {
    for (int i = 1; i < N; i++) {
        int buf = i;
        int sum = i;
        while (buf != 0) {
            sum += buf % 10;
            buf /= 10;
        }
        //cout << sum << '\n';
        if (sum == N)
            return i;
    }

    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    cout << func();
}