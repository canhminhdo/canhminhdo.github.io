#include <bits/stdc++.h>

using namespace std;

int n = 9;
int arr[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

void findSubArrayMax() {
    int best = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);
        best = max(best, sum);
    }
    cout << best << "\n";
}

void findSubArrayMaxWithIndices() {
    int best = INT_MIN, sum = 0;
    int best_start = 0, best_end = 0, current_start = 0;
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] < arr[i]) {
            current_start = i;
            sum = arr[i];
        } else {
            sum += arr[i];
        }

        if (best < sum) {
            best = sum;
            best_start = current_start;
            best_end = i;
        }
    }
    cout << best << "\n";
    cout << "start from " << best_start << " to " << best_end << "\n";
}

int main() {
    findSubArrayMax();
    findSubArrayMaxWithIndices();
}