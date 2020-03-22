/*
    See the solution at https://github.com/zqy1018/sjtu_oj_solutions/blob/master/solutions/sjtu4286.md
*/
#include <cstdio>
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
int n, a[20000005], K;
int sd, ta, tb;
int gene(){
    return (sd = sd * ta + tb);
}
int BFPRT(int *a, int l, int r, int K);
template <typename T>
void swap(T& p1, T& p2){
    T tmp = p1;
    p1 = p2, p2 = tmp;
}
int get_index(int *a, int l, int r){
    // 对 [l, r] 插入排序
    for (int i = l + 1; i <= r; ++i){
        int tmp = a[i], pos = i - 1;
        while (pos >= l && tmp < a[pos])
            a[pos + 1] = a[pos], --pos;
        a[pos + 1] = tmp;
    }
    return (l + r) >> 1;
}
int get_pivot(int *a, int l, int r){
    // 每五个获取中位数，不停的获取
    if (r - l < 4) 
        return get_index(a, l, r);
    int pos = l - 1; 
    for (int i = l; i + 4 <= r; i += 5) {
        int id = get_index(a, i, i + 4);
        swap(a[++pos], a[id]);
    }
    int len = pos - l + 1;
    return BFPRT(a, l, pos, (len >> 1) + 1);
}
int partition(int *a, int l, int r, int pivot_id){
    // 依照枢纽元划分
    swap(a[pivot_id], a[r]);
    int pos = l;
    for (int i = l; i < r; ++i)
        if (a[i] < a[r]){
            while (pos < i && a[pos] < a[r])
                ++pos;
            swap(a[pos], a[i]), ++pos;
        }
    swap(a[pos], a[r]);
    return pos;
}
int BFPRT(int *a, int l, int r, int K){
    // 主过程，和快速选择差不多
    int pivot_id = get_pivot(a, l, r);
    int div_pos = partition(a, l, r, pivot_id);
    if (div_pos - l >= K)
        return BFPRT(a, l, div_pos - 1, K);
    else if (div_pos - l + 1 == K)
        return div_pos;
    else 
        return BFPRT(a, div_pos + 1, r, K - div_pos + l - 1);
}
void init(){
    n = read(), K = read();
    sd = read(), ta = read(), tb = read();
    for (int i = 1; i <= n; ++i)
        a[i] = gene();
}
void solve(){
    printf("%d\n", a[BFPRT(a, 1, n, K)]);
}
int main(){
    init();
    solve();
    return 0;
}