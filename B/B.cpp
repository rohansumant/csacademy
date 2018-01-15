#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    double sum;
    int q,k;
    cin >> sum >> q >> k;
    vector<int> a(q);
    for(int i=0;i<q;i++) cin >> a[i];
    sort(a.begin(),a.end());
    double mul = 1;
    for(int i:a) mul *= (1.0 + i/100.0);
    double ans = sum*mul;
    for(int i=0;i<q;i++) {
        mul /= 1.0 + a[i]/100.0;
        ans = max(ans,(sum+(i+1)*k)*mul);
    }
    printf("%.9f",ans);
}
