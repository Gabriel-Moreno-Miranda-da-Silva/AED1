#include <iostream>
using namespace std;

int v[100000];

bool cmp(int a, int b) {
    if (a % 2 != b % 2) return a % 2 < b % 2;

    if (a % 2 == 0) return a < b;

    return a > b;
}

void qs(int l, int r) {
    int i = l, j = r;
    int p = v[(l + r) / 2];

    while (i <= j) {
        while (cmp(v[i], p)) i++;
        while (cmp(p, v[j])) j--;

        if (i <= j) {
            int t = v[i]; v[i] = v[j]; v[j] = t;
            i++; j--;
        }
    }
    if (l < j) qs(l, j);
    if (i < r) qs(i, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    qs(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}
