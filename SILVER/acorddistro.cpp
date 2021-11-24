#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    deque<int> q;
    int n, k, p;

    cin >> n >> k >> p;

    for (int i = 1; i <= k; i++) { q.push_back(i); }

    vector<int> v;
    for (int i = 1 ; i <= k ; i++) { 
        int a = q.front();
        q.pop_front();

        if (i % n == 0) {
            v.push_back(a);
        }
        for (int j = 0 ; j < p && !q.empty() ; j++) {
            int b = q.front();
            q.pop_front();
            q.push_back(b);
        }
        
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < v.size() ; i ++) {
        cout << v[i] << endl;
    }

}