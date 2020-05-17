#include <iostream>

using namespace std;

#define N 4
void initialize();
void attemp(int i);
void print();

int n = N;  // number of vertices
int m = 6;  // number of edges
int maxE = 1000;
int maxC = 100 * maxE;
int C[N][N] = {
    {0, 3, 2, 1},
    {3, 0, 1, 2},
    {2, 1, 0, 4},
    {1, 2, 4, 0}
};
int X[N];   // store all possible ways
int BestWay[N]; // store best way
int T[N];   // store cost from x[0] to X[i]
int Free[N];    // Free[i] = True if not visit i
int BestConfig = maxC;  // best cost

int main() {
    // starting from 0 for easily manipulate with arrays
    initialize();
    attemp(1);
    print();
}

void initialize() {
    for (int i = 0; i < n; i ++) {
        Free[i] = true;
        BestWay[i] = 0;
        X[i] = 0;
        T[i] = 0;
    }
    Free[0] = false;    // start from vertice 0
    BestConfig = maxC;
}

void attemp(int i) {
    for (int j = 1; j < n; j ++) {
        if (Free[j]) {
            X[i] = j;
            T[i] = T[i - 1] + C[X[i - 1]][j];
            if (T[i] < BestConfig) {
                if (i < n - 1) {
                    Free[j] = false;
                    attemp(i + 1);
                    Free[j] = true;
                } else {
                    if (T[i] + C[X[i]][0] < BestConfig) {
                        for (int k = 0; k < n; k ++) {
                            BestWay[k] = X[k];
                        }
                        BestConfig = T[i] + C[X[i]][0];
                    }
                }
            }
        }
    }
}

void print() {
    cout << "Path: ";
    for (int i = 0; i < n; i ++) {
        cout << BestWay[i] + 1 << " -> ";
    }
    cout << 1 << endl;
    cout << "Cost: " << BestConfig << endl;
}

