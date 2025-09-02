#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    if (N % 2 == 0)
        cout << "Song";
    else
        cout << "Soomin";
    return 0;
}
