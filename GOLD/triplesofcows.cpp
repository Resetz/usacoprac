#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

//dsu data structure 
class dsu {
    public:
    vector<int> parent;
    vector<int> s;
    int size = 0;
    dsu(int n) {
        parent.resize(n);
        s.resize(n, 1);
        size = n;
        for (int i = 0 ; i < n ; i++) parent[i] = i;
    }

    int find_set(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (s[a] < s[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            s[a] += s[b];
            //cout << a << " " << b << endl;
            size--;
        }
    }
};
int main () {
    ofstream myfile;
    myfile.open ("triplesofcows.txt");
    myfile << 5000 << endl;
    for (int i )
    return 0;
}