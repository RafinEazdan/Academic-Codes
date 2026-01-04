#include <iostream>
using namespace std;

int main() {
    bool P, Q;
    cout << "P\tQ\tnot P^(P->Q)\n"; // table header
    for (P = false; P <= true; P = !P) {
        for (Q = false; Q <= true; Q = !Q) {
            bool result = !(P ^ (P -> Q)); // evaluate the expression
            cout << P << "\t" << Q << "\t" << result << "\n"; // table row
        }
    }
    return 0;
}
