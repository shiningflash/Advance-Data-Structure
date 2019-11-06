/*
    @data_structure  : Disjoint Set Unit (DSU)
    @implementation  : Kruskal's MST, Tarjan's offline LCA
    @author          : Amirul Islam
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+5;
int par[mx];

// return the representation of r
int find(int r) {
	if (par[r] == r) return r;
	return par[r] = find(par[r]);
}

// at the beginning, everyone's representative is it itself
void init(int n) {
	for (int i = 1; i <= n; i++) par[i] = i;
}

int main() {
    //freopen("in", "r", stdin);

	int node, relation, a, b;
	scanf("%d %d", &node, &relation);
	init(node);
	while (relation--) {
		scanf("%d %d", &a, &b);
		int u = find(a);
		int v = find(b);
		if (u == v) printf("They are already friend\n");
		else par[u] = v; // make friend
	}
        return 0;
}
