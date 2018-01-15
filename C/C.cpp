#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a%b);
}

int get_smallest_factor(int x,int y) {
    vector<int> a;
    for(int i=1;i*i<=x;i++) if(!(x%i)) {
        a.push_back(i);
        a.push_back(x/i);
    }
    int ans = x;
    for(int i:a) if(i > y) ans = min(ans,i);
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) a[i] -= b[i];
    if(any_of(a.begin(),a.end(),[](int x){return x < 0;})) {
        cout << -1;
        return 0;
    }
    int accum = a[0], b_max = *max_element(b.begin(),b.end());
    if(all_of(a.begin(),a.end(),[](int x){return x == 0;})) {
        cout << b_max+1;
        return 0;
    }
    for(int i=1;i<n;i++) accum = gcd(accum,a[i]);
    if(accum <= b_max) {
        cout << -1;
        return 0;
    }
    cout << get_smallest_factor(accum,b_max);
}
