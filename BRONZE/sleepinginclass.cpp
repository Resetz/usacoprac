#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void testcase() {
    int n;
    cin >> n;
    stack<int> s;
    vector<int> v(n);
    int highest = 0;
    for (int i = 0; i < n ; ++i) {
        cin >> v[i];
    }

    s.push(v[0]);
    highest = v[0];
    for (int i = 1; i < n ; ++i) {
        s.push(v[0]);
    }
}

int main() {
    int t;
    cin >> t;
    while (--t) testcase();
}