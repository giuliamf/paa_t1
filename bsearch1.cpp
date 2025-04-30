#include <iostream>
#include <vector>
using namespace std;

int binary_search_first(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // compatível com g++ 4.3.2

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    while (Q--) {
        int query;
        cin >> query;
        cout << binary_search_first(arr, query) << "\n";
    }

    return 0;
}
