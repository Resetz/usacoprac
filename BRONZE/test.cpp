#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void f(vector<int> t) {
    vector<int> t = t;
    t[0]++;
    cout << t[0] << endl;
}

int main() {
    vector<int> v(3);
    f(v);
    cout << v[0];
}