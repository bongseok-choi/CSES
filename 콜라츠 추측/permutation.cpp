#include <iostream>
#include <vector>

using namespace std;

vector<int> permutation;
int n = 3;
bool chosen[5];

void search() {
    if (permutation.size() == n) {
        // Process the permutation (e.g., print it)
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    search();
    return 0;
}
