#include <algorithm>
#include <iostream>
using namespace std;

int arr[2001];
int n;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int target = arr[i];
        int left = 0, right = n - 1;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            int sum = arr[left] + arr[right];
            if (sum == target) {
                cnt++;
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
