#include <iostream>
using namespace std;

struct Aresta { 
    int u, v, w; 
} arestas[200000];

int p[200000];

void qs(int l, int r) {
    int i = l, j = r, P = arestas[(l + r) / 2].w;
    while (i <= j) {
        while (arestas[i].w < P) i++;
        while (arestas[j].w > P) j--;
        if (i <= j) { Aresta t = arestas[i]; arestas[i++] = arestas[j]; arestas[j--] = t; }
    }
    if (l < j) qs(l, j);
    if (i < r) qs(i, r);
}

int find(int x) { 
    return p[x] == x ? x : p[x] = find(p[x]); 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n;
    while (cin >> m >> n && m) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> arestas[i].u >> arestas[i].v >> arestas[i].w;
            total += arestas[i].w;
        }
        qs(0, n - 1);
        for (int i = 0; i < m; i++) p[i] = i;

        for (int i = 0; i < n; i++) {
            int a = find(arestas[i].u), b = find(arestas[i].v);
            if (a != b) {
                p[a] = b;
                total -= arestas[i].w;
            }
        }
        cout << total << "\n";
    }
}
