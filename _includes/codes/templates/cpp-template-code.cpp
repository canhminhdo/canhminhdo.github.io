// automatically include all standard libraries at one time
#include <bits/stdc++.h>

using namespace std;

// Shortening code
// Type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

// Macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)

int main() {
    // g++ -std=c++11 -O2 -Wall test.cpp -o test
    cout << endl;
    cout << "\n"; // this is better than endl

    // Floating point numbers problem
    double x = 0.3*3+0.1;
    printf("%.20f\n", x); // 0.99999999999999988898 -> it is wired
    double a, b;
    // comparing 2 float numbers with an epsilon
    if (abs(a-b) < 1e-9) {}  // should not use a == b in the condition
}

// updating ...