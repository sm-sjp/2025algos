#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 105

int N, K, L, Val, Yes = 0;
vector<int> code[MAX];

vector<int> Fail(vector<int> &subcode) {
    vector<int> pi(subcode.size());
    for (int i = 1, j = 0; i < subcode.size(); i++) {
        while (j > 0 && subcode[i] != subcode[j]) j = pi[j - 1];
        if (subcode[i] == subcode[j]) pi[i] = ++j;
    }
    return pi;
}

int KMP(vector<int> &code, vector<int> &subcode) {
    vector<int> pi = Fail(subcode);
    for (int i = 0, j = 0; i < code.size(); i++) {
        while (j > 0 && code[i] != subcode[j]) j = pi[j - 1];
        if (code[i] == subcode[j]) {
            if (j == subcode.size() - 1)
                return 1;
            else
                j++;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> L;
        for (int j = 0; j < L; j++) {
            cin >> Val;
            code[i].push_back(Val);
        }
    }
    for (int i = 0; i < code[0].size() - K + 1; i++) {
        vector<int> subcode(K);
        for (int j = 0; j < K; j++) subcode[j] = code[0][i + j];
        int check = 1;
        for (int j = 1; j < N; j++) {
            vector<int> rev = code[j];
            reverse(rev.begin(), rev.end());
            if (!KMP(code[j], subcode) && !KMP(rev, subcode)) check = 0;
        }
        if (check) Yes = 1;
    }
    if (Yes)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
