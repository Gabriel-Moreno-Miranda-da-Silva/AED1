#include <iostream>
#include <vector>
#include <string>

using namespace std;

int get_id(string s) {
    if (s == "XXL") return 0;
    if (s == "XL") return 1;
    if (s == "L") return 2;
    if (s == "M") return 3;
    if (s == "S") return 4;
    return 5; // XS
}

vector<int> adj[35]; 

int match[40]; 

bool vis[40];

bool dfs(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        
        if (vis[v]) continue;
        vis[v] = true;

        if (match[v] < 0 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {

    int num_casos;
    cin >> num_casos;

    while (num_casos--) {
        int N, M;
        cin >> N >> M;

        int limit = N / 6;

        for (int i = 0; i < M; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < M; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            
            int tipo1 = get_id(s1);
            int tipo2 = get_id(s2);

            for (int k = 0; k < limit; k++) {
                adj[i].push_back(tipo1 * limit + k);
            }

            for (int k = 0; k < limit; k++) {
                adj[i].push_back(tipo2 * limit + k);
            }
        }

        for (int i = 0; i < N; i++) {
            match[i] = -1;
        }

        int matches = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) vis[j] = false;

            if (dfs(i)) {
                matches++;
            }
        }

        if (matches == M) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
