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
    int len = (int) sqrt(n) + 1;
    int b[len];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; b[i/len] += a[i], i++);

    // answering the queries
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &l, &r);
        int sum = 0;
        int left_block = l/len;
        int right_block = r/len;
        if (left_block == right_block) for (int i = l; i <= r; sum += a[i++]); // range is in same block
        else {
            for (int i = l, end = (left_block+1)*len-1; i <= end; sum += a[i++]); // left most block sum
            for (int i = left_block+1; i < right_block; sum += b[i++]); // middle all block's sum
            for (int i = right_block*len; i <= r; sum += a[i++]); // right most block sum
        }
        printf("%d\n", sum);
    }
}
