#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[2000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int target = arr[i];
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == target) {
                if (l != i && r != i) {
                    res++;
                    break;
                }
                if (l == i) l++;
                else if (r == i) r--;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << res;
    return 0;
}
