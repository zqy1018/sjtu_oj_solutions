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
int n, k, a[100005], b[100005], c[100005];
int ans[100005];
struct node{
    int val, x, id;
    node(){}
    node(int v, int _x, int _id): val(v), x(_x), id(_id){}
    bool operator <(const node& nd) const{
        return val > nd.val;
    }
};
priority_queue<node> pq;
int f(int id, int x){
    return x * x * a[id] + x * b[id] + c[id];
}
void init(){
    n = read(), k = read();
    for (int i = 1; i <= n; ++i){
        a[i] = read(), b[i] = read(), c[i] = read();
    }
    for (int i = 1; i <= n; ++i){
        if (b[i] % (a[i] + a[i]) == 0){
            pq.push(node(f(i, (-b[i]) / (a[i] + a[i])), (-b[i]) / (a[i] + a[i]), i));
        }else {
            int pos = (-b[i]) / (a[i] + a[i]), pos2;
            if (b[i] < 0) pos2 = pos + 1;
            else pos2 = pos - 1;
            pq.push(node(f(i, pos), pos, i));
            pq.push(node(f(i, pos2), pos2, i));
        }
    }
}
void solve(){
    int tot = 0;
    while (k--){
        node tmp = pq.top();
        pq.pop();
        ans[++tot] = tmp.val;
        int i = tmp.id, x = tmp.x;
        if (b[i] % (a[i] + a[i]) == 0 && x == (-b[i]) / (a[i] + a[i])){
            pq.push(node(f(i, x - 1), x - 1, i));
            pq.push(node(f(i, x + 1), x + 1, i));
        }else {
            if (x * (a[i] + a[i]) < (-b[i])) pq.push(node(f(i, x - 1), x - 1, i));
            else pq.push(node(f(i, x + 1), x + 1, i));
        }
    }
    for (int i = 1; i < tot; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[tot]);
}
int main(){
    init();
    solve();
    return 0;
}