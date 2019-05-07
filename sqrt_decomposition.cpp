#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("in", "r", stdin);
    int n, l, r, q;
    scanf("%d", &n);

    // main array
    int a[n];
    for (int i = 0; i < n; scanf("%d", &a[i++]));

    // decomposed array, processing
    int len = (int) sqrt(n);
    len += !(len*len==n); // each block length and total block number
    int b[len];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; b[i/len] += a[i++]);

    // answering the queries
    for (scanf("%d", &q); q--; ) {
        scanf("%d %d", &l, &r);
        int sum = 0, left_block = l/len, right_block = r/len;
        if (left_block == right_block) for (int i = l; i <= r; sum += a[i++]); // range is in same block
        else {
            for (int i = l, end = (left_block+1)*len-1; i <= end; sum += a[i++]); // left most block sum
            for (int i = left_block+1; i < right_block; sum += b[i++]); // middle all block's sum
            for (int i = right_block*len; i <= r; sum += a[i++]); // right most block sum
        }
        printf("%d\n", sum);
    }
}
