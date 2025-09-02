#include <bits/stdc++.h>
using namespace std;
int n, s[51], ans;
char str[51];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        str[s[i]] = 'a' + i;
    }

    char c = 'a';
    ans++;

    for (int i = 1; i < n; ++i) {
        str[s[i]] = c;

        if (strcmp(str + s[i - 1], str + s[i]) >= 0) {
            c++;
            str[s[i]] = c;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
// 코드 참고 : https://github.com/ktjooho/problem_solving/blob/master/13013_%EC%A0%91%EB%AF%B8%EC%82%AC%EB%B0%B0%EC%97%B42.cpp
