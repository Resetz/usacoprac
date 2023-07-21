#include <iostream>
#include <set>

using namespace std;

void solve(){ 
    double a,b;
    cin >> a >> b;
    set<double> set;
    set.insert(a+b);
    set.insert(a-b);
    set.insert(a/b);
    set.insert(a*b);
    set.insert(b+a);
    set.insert(b-a);
    set.insert(b/a);
    set.insert(b*a);
    cout << set.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}