/**************************************
 * author - Amirul Islam (shiningflash)
 --------------------------------------
 * Segment tree (data structure)
 --------------------------------------
 * height (total) - log(n)
 * per query - O(log n)
 * per update - O(log n)
 * init func - O(n log n)
 * total complexity - O(n log n)
 **************************************/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;

/******* param ***********
 * arr[]  - main array
 * tree[] - conceptual tree
 * b      - begin index
 * e      - end index
 * node   - root node index
 * ls     - left part sum
 * rs     - right part sum
 *************************/

int arr[mx];
int tree[mx*4];
int n;

void print(int a[], int b, int e) {
	for (int i = b; i <= e; printf("%d %d\n", i, a[i]), i++);
	printf("\n");
}

void init(int node, int b, int e) {
	if (b == e) {
		tree[node] = arr[b];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	init(left, b, mid);
	init(right, mid + 1, e);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j) {
	if (i > e || j < b) return 0;
	if (b >= i && e <= j) return tree[node];
	int left = node << 2;
	int right = (node << 2) + 1;
	int mid = (b + e) >> 2;
	int ls = query(left, b, mid, i, j);
	int rs = query(right, mid + 1, e, i, j);
	return ls + rs;
}

void update(int node, int b, int e, int i, int val) {
	if (i > e || i < b) return;
	if (b >= i && e <= i) {
		tree[node] = val;
		return;
	}
	int left = node << 2;
	int right = (node << 2) + 1;
	int mid = (b + e) >> 2;
	update(left, b, mid, i, val);
	update(right, mid + 1, e, i, val);
	tree[node] = tree[left] + tree[right];
}

int main() {
//	freopen("in", "r", stdin);
	
	int n, q, i, j, ans;
	scanf("%d %d", &n, &q);
	for (int k = 1; k <= n; scanf("%d", &arr[k]), k++);
	init(1, 1, n);
	while (q--) {
		scanf("%d %d", &i, &j);
		ans = query(1, 1, n, i, j);
		printf("%d\n", ans);
	}
	return 0;
}

// 14 Feb, 2019 //////////////////
