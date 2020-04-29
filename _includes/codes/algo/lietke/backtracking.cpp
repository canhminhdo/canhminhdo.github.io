#include <iostream>

using namespace std;

void attemp(int n);
void show();

int arr[3];
int choices[2] = {0, 1};
int numChoices = 2;
int length = 3;

int main() {
    // starting from 0 for easily manipulate with arrays
    attemp(0);
}

void attemp(int i) {
    for (int j = 0; j < numChoices; j ++) {
        arr[i] = choices[j];
        if (i == length - 1)
            show();
        else
            attemp(i + 1);
    }
}

void show() {
    for (int i = 0; i < length; i ++) {
        cout << arr[i];
    }
    cout << endl;
}
