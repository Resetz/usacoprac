#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>

#include <map>

using namespace std;


void solve() {
    unsigned long long f, t;
    cin >> f >> t;

    queue<pair<pair<int,int>,unsigned long long>> q;

    q.push({{0, 0}, f}); 
    q.push({{0, 1}, t}); 
    // +1 = 0 
    // +1 +1 = 1 dont wanna add 1 again 

    map<unsigned long long, int> v;
    map<unsigned long long, int> v2;
    if (f == t) {
        cout << 0 << endl;
        return;}
    while (true) {
        unsigned long long i = q.front().second;
        unsigned long long time = q.front().first.first;
        unsigned long long type = q.front().first.second;
        q.pop();
        //cout << type << " " << i << " " << time << endl;
        if (type) {
            if (v2.find(i) != v2.end()) {continue;}
        } else {
            if (v.find(i) != v.end()) {continue;}
        }
        if (type) v2[i] = time;
        else v[i] = time;
        if ( t > f ) {
            if (type) {
                if (v.find(i) != v.end()) {
                    cout << v[i] + time << endl;
                    return;
                }
                if (i <= t && v2.find(i*2) == v2.end()) {
                    q.push({{time+1, 1}, i*2});
                    //cout << i*2 << endl;
                }
                if (i % 2 == 0 && v2.find(i/2) == v2.end()) {
                    q.push({{time+1, 1}, i/2});
                    //cout << i/2 << endl;
                }
                if (v2.find(i-1) == v2.end()) {
                    q.push({{time+1, 1}, i-1});
                    //cout << i-1 << endl;
                }
            } else {
                if (v2.find(i) != v2.end()) {
                    cout << v2[i] + time << endl;
                    return;
                }
                if (i <= t && v.find(i+1) == v.end()) {
                    q.push({{time+1, 0}, i+1});
                    //cout << i+1 << endl;
                }
                if (i <= t && v.find(i*2) == v.end()) {
                    q.push({{time+1, 0}, i*2});
                    //cout << i*2 << endl;
                }
                if (i % 2 == 0 && v.find(i/2) == v.end()) {
                    q.push({{time+1, 0}, i/2});
                    //cout << i/2 << endl;
                }
            }
        } else if (f > t) {
            if (type) {
                if (v.find(i) != v.end()) {
                    cout << v[i] + time << endl;
                    return;
                }
                if (v.find(i-1) == v.end()) {
                    q.push({{time+1, 1}, i-1});
                }
                if (i <= f && v.find(i*2) == v.end()) {
                    q.push({{time+1, 1}, i*2});
                }
                if (i % 2 == 0 && v.find(i/2) == v.end()) {
                    q.push({{time+1, 1}, i/2});
                }
            } else {
                if (v2.find(i) != v2.end()) {
                    cout << v2[i] + time << endl;
                    return;
                }
                if (i <= f && v.find(i+1) == v.end()) {
                    q.push({{time+1, 0}, i+1});
                }
                if (i <= f && v.find(i*2) == v.end()) {
                    q.push({{time+1, 0}, i*2});
                }
                if (i % 2 == 0 && v.find(i/2) == v.end()) {
                    q.push({{time+1, 0}, i/2});
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}