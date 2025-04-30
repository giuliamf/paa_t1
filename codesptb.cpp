#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll merge_sort(vector<int>& arr, int left, int right, vector<int>& temp) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    ll inv_count = 0;

    inv_count += merge_sort(arr, left, mid, temp);
    inv_count += merge_sort(arr, mid + 1, right, temp);

    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // conta as inversões
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int p = left; p <= right; p++)
        arr[p] = temp[p];

    return inv_count;
}

ll count_inversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return merge_sort(arr, 0, n - 1, temp);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i)
            cin >> a[i];
        cout << count_inversions(a) << endl;
    }
    return 0;
}
