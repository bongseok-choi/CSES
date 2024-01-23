#include <iostream>
#include <vector>

using namespace std;

void search(int y, int n, int& cnt, vector<int>& col, vector<int>& diag1, vector<int>& diag2) {
    if (y == n) {
        cnt++;
        return;
    }

    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;

        // 배열을 1로 초기화
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;

        search(y + 1, n, cnt, col, diag1, diag2);

        // 배열을 0으로 초기화
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input for n. Please enter a positive integer." << endl;
        return 1; // Exit with an error code
    }

    vector<int> col(n, 0); // Initialize col vector with zeros
    vector<int> diag1(2 * n - 1, 0); // Initialize diag1 vector with zeros
    vector<int> diag2(2 * n - 1, 0); // Initialize diag2 vector with zeros

    int cnt = 0;
    search(0, n, cnt, col, diag1, diag2);

    cout << "Number of solutions: " << cnt << endl;

    return 0;
}
