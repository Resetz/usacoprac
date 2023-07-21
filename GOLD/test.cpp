#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct {
    int a,b,c,d;
} s;

bool comp(s a, s b) {
    return a.c < b.c;
}

int main() {
    map<string, int> map;
    

    vector<s> v;
    v.push_back({5, 1});
    v.push_back({4, 2});
    v.push_back({3, 3});
    v.push_back({2, 4});
    v.push_back({1, 5});
    sort(v.begin(), v.end(), [](s a, s b) -> bool {
        return a.d < b.d;
    });
}