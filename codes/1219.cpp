/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu1219.md
*/
#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, a[300005];
ll ans = 0;
template <typename T>
void Msort_Merge(T* a, T* tmp, int l, int mid, int r){
    int lpos = l, rpos = mid, pos = l;
    int ppos = l;
    while (lpos < mid && rpos < r){
        if (a[lpos] <= a[rpos]) tmp[pos++] = a[lpos++];
        else {
            while (ppos < mid && a[ppos] <= 2 * a[rpos])
                ++ppos;
            ans += mid - ppos;
            tmp[pos++] = a[rpos++];
        }
    }
    while (lpos < mid) tmp[pos++] = a[lpos++];
    while (rpos < r) tmp[pos++] = a[rpos++];
    for (int i = l; i < r; ++i)
        a[i] = tmp[i];
}
template <typename T>
void Msort(T *a, T* tmp, int l, int r){
    /* [l, r) */
    if (r - l <= 1) return ;
    int mid = (l + r) >> 1;
    Msort(a, tmp, l, mid);
    Msort(a, tmp, mid, r);
    Msort_Merge(a, tmp, l, mid, r);
}
template <typename T>
void MergeSort(T *a, int n){
    T *tmp = new T[n];
    Msort(a, tmp, 0, n);
    delete [] tmp;
}
void init(){
    n = read();
    for (int i = 0; i < n; ++i)
        a[i] = read();
}
void solve(){
    MergeSort(a, n);
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}