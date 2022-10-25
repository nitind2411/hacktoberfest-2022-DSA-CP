#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        cout << "Move disc 1 from " << src << " to " << dest << endl;
        return;
    }
    // Move 'n-1' discs from src to aux
    towerOfHanoi(n-1, src, aux, dest);
    // Move last disc from src to dest
    cout << "Move disc " << n << " from " << src << " to " << dest << endl;
    // Move 'n-1' disc from aux to dest
    towerOfHanoi(n-1, aux, dest, src);
}

int main() {
    towerOfHanoi(3, 'A', 'C', 'B');
}
