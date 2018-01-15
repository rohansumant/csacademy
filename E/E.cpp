#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
const int N = 1e5+5, M = 25;
vector<int> a[N];
int anc[M][N],ht[N],sz[N];

int jump_up(int node,int diff) {
    for(int i=M-1;i>=0;i--) {
        if(diff & (1<<i)) node = anc[i][node];
    }
    return node;
}

int lca(int x,int y) {
    if(ht[x] > ht[y]) swap(x,y);
    int diff = ht[y] - ht[x];
    int target_ancestor = jump_up(y,diff);
    while(x != target_ancestor) {
        x = anc[0][x];
        target_ancestor = anc[0][target_ancestor];
    }
    return target_ancestor;
}


void dfs(int x,int par) {
    if(par > 0) {
        anc[0][x] = par;
        ht[x] = ht[par]+1;
    }
    sz[x] = 1;
    for(int ch:a[x]) if(ch != par) {
        dfs(ch,x);
        sz[x] += sz[ch];
    }
}


int main() {
    int n,q;
    cin >> n >> q;
    for(int i=1;i<n;i++) {
        int x,y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    anc[0][1] = -INF; // 1 is the root
    dfs(1,-1);
    for(int i=1;i<M;i++) {
        for(int j=1;j<=n;j++) {
            anc[i][j] = anc[i-1][j] == -INF ? -INF : anc[i-1][anc[i-1][j]];
        }
    }
    while(q--) {
        int a,b,c;
        cin >> a >> b >> c;
        int x = lca(a,b);
        if(lca(c,x) != x) {
            cout << 0 << endl;
            continue;
        }
        int ans;
        if(x == c) {
            ans = sz[1];
            int diff = ht[a] - ht[c];
            ans -= sz[jump_up(a,diff-1)];
            diff = ht[b] - ht[c];
            ans -= sz[jump_up(b,diff-1)];
        } else {
            if(lca(c,a) == c) {
                int diff = ht[a] - ht[c];
                ans = sz[c] - sz[jump_up(a,diff-1)];
            } else {
                int diff = ht[b] - ht[c];
                ans = sz[c] - sz[jump_up(b,diff-1)];
            }
        }
        cout << ans << endl;
    }
}

