#include <iostream>
#include <vector>
using namespace std;

int find(int x,vector<int> &par) {
    if(par[x] == x) return par[x];
    par[x] = find(par[x],par);
    return par[x];
}

void merge(int _x,int _y,vector<int> &par,vector<int> &r,vector<int> &sz) {
    int x = find(_x,par), y = find(_y,par);
    if(x == y) return;
    if(r[x] < r[y]) {
        par[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
    } else {
        par[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
        if(r[x] == r[y]) r[x]++;
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> par(n+1), r(n+1), sz(n+1);
    for(int i=1;i<=n;i++) par[i] = i, r[i] = 0, sz[i] = 1;
    while(m--) {
        int x,y; cin >> x >> y;
        merge(x,y,par,r,sz);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++) if(sz[i] & 1) cnt++;
    cout << (cnt & 1) << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}
