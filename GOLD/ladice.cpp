#include <iostream>
#include <vector>
#include <set>

using namespace std;

//dsu data structure 
class dsu {
    public:
    vector<int> parent;
    vector<int> s;
    vector<int> left;
    int size = 0;
    dsu(int n) {
        parent.resize(n);
        s.resize(n, 1);
        left.resize(n, 1);
        size = n;
        for (int i = 0 ; i < n ; i++) parent[i] = i;
    }

    int find_set(int a) {
        int cur = a;
        set<int> vis;
        while (vis.insert(cur).second && a != parent[cur]){
            cur = parent[cur];
        }
        if (parent[cur] == cur) return cur;
        else return -1;
    }

    bool place(int a) {
        if (left[a] > 0) {
            left[a]--;
            return true;
        }  else {
            return false;
        }
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == -1) {
            return;
        }
        if (a != b) {
            if (s[a] < s[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            s[a] += s[b];
            left[a] += left[b];
            //cout << a << " " << b << endl;
            size--;
        }
    }
};

int main() {
    int n, l;
    cin >> n >> l;
    
    dsu d(l);

    for (int i = 0 ; i < n ; i++) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        d.union_set(a,b);
        cout << (d.place(d.find_set(a)) ? "LADICA" : "SMECE") << endl;
    }
}