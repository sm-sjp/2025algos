#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<pair<string, string>> info;
vector<bool> used;

int best_cnt = 0;
int min_sel = INT_MAX;

void dfs(int idx, int sel_cnt) {
    if (idx == n) {
        vector<bool> song(m, false);
        int cover = 0;

        for (int i = 0; i < n; i++) {
            if (!used[i]) continue;

            string ab = info[i].second;
            for (int j = 0; j < ab.size(); j++) {
                if (ab[j] == 'Y' && !song[j]) {
                    song[j] = true;
                    cover++;
                }
            }
        }

        if (best_cnt < cover) {
            best_cnt = cover;
            min_sel = sel_cnt;
        } else if (best_cnt == cover) {
            min_sel = min(min_sel, sel_cnt);
        }
        return;
    }

    used[idx] = true;
    dfs(idx + 1, sel_cnt + 1);

    used[idx] = false;
    dfs(idx + 1, sel_cnt);
}

int main() {

    cin >> n >> m;
    info.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> info[i].first >> info[i].second;
    }

    used.assign(n, false);
    dfs(0, 0);

    if (min_sel == 0) min_sel = -1;
    cout << min_sel;
    return 0;
}
