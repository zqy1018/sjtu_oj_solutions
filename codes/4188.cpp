/*
    Hint: use SAM and hash (or SA?)
*/
#include <bits/stdc++.h>
#define INF 2000000000
#define M 100007ull
using namespace std;
typedef unsigned long long ull;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
struct SAM{
    int len[300005], link[300005], to[300005][27];
    int last, D;
    int Sigma;
    SAM(int sigma){
        last = D = 0;
        Sigma = sigma;
        len[0] = 0, link[0] = -1;
        for (int i = 0; i < Sigma; ++i)
            to[0][i] = -1;
    }
    int create_node(){
        int res = ++D;
        link[res] = -1;
        for (int i = 0; i < Sigma; ++i)
            to[res][i] = -1;
        return res;
    }
    int copy_node(int src){
        int res = ++D;
        link[res] = link[src];
        for (int i = 0; i < Sigma; ++i)
            to[res][i] = to[src][i];
        return res;
    }
    inline int get_cid(char c){
        return (c == '#' ? 26: c - 'a');
    }
    void insert(char c){
        int cid = get_cid(c);
        int cur = create_node();
        len[cur] = len[last] + 1;
        int p = last;
        while (p != -1 && to[p][cid] == -1){
            to[p][cid] = cur;
            p = link[p];
        }
        if (p == -1){
            link[cur] = 0;
        }else {
            int q = to[p][cid];
            if (len[p] + 1 == len[q]){
                link[cur] = q;
            }else {
                int clone = copy_node(q);
                len[clone] = len[p] + 1;
                link[cur] = link[q] = clone;
                while (p != -1 && to[p][cid] == q){
                    to[p][cid] = clone;
                    p = link[p];
                }
            }
        }
        last = cur;
    }
    bool check(const string& s){
        int cur = 0, l = s.length();
        for (int i = 0; i < l; ++i){
            cur = to[cur][get_cid(s[i])];
            if (cur == -1) return false;
        }
        return true;
    }
    bool check(char* s, int l){
        int cur = 0;
        for (int i = 0; i < l; ++i){
            cur = to[cur][get_cid(s[i])];
            if (cur == -1) return false;
        }
        return true;
    }
};
SAM sam(27);
int n;
vector<vector<ull> > hsh_pre, hsh_suf;
bool ans[50005] = {0};
void init(){
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        ans[i] = sam.check(s);
        for (char c: s)
            sam.insert(c);
        sam.insert('#');

        hsh_pre.push_back(vector<ull>());
        vector<ull>& v1 = hsh_pre.back();
        v1.push_back(0);
        ull lst = 0;
        for (char c: s)
            lst = lst * M + c - 'a', 
            v1.push_back(lst);

        hsh_suf.push_back(vector<ull>());
        vector<ull>& v2 = hsh_suf.back();
        v2.push_back(0);
        lst = 0;
        int l = s.length();
        for (int i = l - 1; i >= 0; --i)
            lst = lst * M + s[i] - 'a', 
            v2.push_back(lst);
    }
}
int lcp(vector<ull>& v1, vector<ull>& v2){
    int l = 0, r = max(v1.size(), v2.size());
    --r;
    while (r > l){
        int mid = (l + r + 1) >> 1;
        if (v1[mid] == v2[mid])
            l = mid;
        else r = mid - 1;
    }
    return l;
}
void solve(){
    int q;
    cin >> q;
    while (q--){
        int opr;
        cin >> opr;
        if (opr == 1){
            int t;
            cin >> t;
            printf("%s\n", (ans[t - 1] ? "yes": "no"));
        }
        if (opr == 2){
            int x, y;
            cin >> x >> y;
            printf("%d\n", lcp(hsh_pre[x - 1], hsh_pre[y - 1]));
        }
        if (opr == 3){
            int x, y;
            cin >> x >> y;
            printf("%d\n", lcp(hsh_suf[x - 1], hsh_suf[y - 1]));
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}