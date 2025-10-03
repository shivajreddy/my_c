#include <iostream>

using namespace std;

int add(int a, int b);

int main() {
    // cout << "hello there\n";
    cout << add(20, 88) << endl;
    return 0;
}

int add(int a, int b) {
    return a + b;
}
