#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n,w;
    cin >> n >> w;
    vector<pair<int,int>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }
    v.push_back({0,0});

    stack<int> s;
    int a = 0;
    for (int i = 0; i <= n ; i++) {

        while (!s.empty() && s.top() > v[i].second){
            //cout << "popped " << s.top() << endl;
            s.pop();
            a++;
            
        }
        /*if (!s.empty()) {
            if (v[i].second != s.top()) {
                a++;
            }
        }*/ 
        if (!s.empty()) {
            if (v[i].second == s.top()) continue;
        }
        s.push(v[i].second);
    }
    cout << a << endl;

}