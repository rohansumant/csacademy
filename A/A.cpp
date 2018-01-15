#include <iostream>
#include <vector>
using namespace std;

int go(vector<int> &a,vector<int> &b,int n,int m) {
    int ans = 0;
    for(int i=0;i<m;i++) {
        int cnt = 0;
        for(int j=0;j<n;j++) if(i+j < m) cnt += (a[j] != b[i+j]);
        ans += (cnt == n);
    }
    return ans;
}


int main() {
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    cout << go(a,b,n,m);
}
