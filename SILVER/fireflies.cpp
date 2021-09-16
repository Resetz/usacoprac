#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

#define ll unsigned long long
#define pll pair<unsigned long long, unsigned long long>

int N;
int C;
int up, down;
pll arr;
int final[100];
int previous = -1;
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};
unordered_set<pll, pair_hash> s;
unordered_set<pll, pair_hash> v;

inline ll check(const pll p, int i) {
    if (i >= 64) {
        return p.second & (1ll << (i-64));
    } else {
        return p.first & (1ll << (i));
    }
}
inline void flip(pll *p, int i) {
    if (i >= 64) {
        p->second ^= (1ll << (i-64));
    } else {
        p->first ^= (1ll << (i));
    }
}
inline void setp(pll *p, int i, int j) {
    if (i >= 64) {
        p->second &= ~(1ll << (i-64));
        p->second |= (((unsigned long long) j) << (i-64));
    } else {
        p->first &= ~(1ll << i);
        p->first |= (((unsigned long long) j) << i);
    }
}

inline void check() {
    if (s.find(arr) != s.end()) return;
    for (int i = 0 ; i < N ; i++) {
        if (final[i] != -1 && final[i] != (check(arr, i) != 0 ? 1 : 0)) {
            return;
        }
    } 
    s.insert(arr);
    
}
void dfs(int f) {

    if (f >= C) {
        check();
        return;
    }
    for (int i = 0 ; i < 4 ; i++) {
        if (i == 0) {
            for (int k = 0 ; k < N ; k++) {
                flip(&arr, k); //xor with 1
            }
            dfs(f+1);
            for (int k = 0 ; k < N ; k++) {
                flip(&arr, k); //xor with 1
            }
        }
        if (i == 1) {
            for (int k = 1 ; k < N ; k += 2) {
                flip(&arr, k); //xor with 1
            } 
            dfs(f+1);
            for (int k = 1 ; k < N ; k += 2) {
                flip(&arr, k); //xor with 1
            } 
        } if (i == 2) {
            for (int k = 0 ; k < N ; k += 2) {
                flip(&arr, k); //xor with 1
            } 
            dfs(f+1);
            for (int k = 0 ; k < N ; k += 2) {
                flip(&arr, k); //xor with 1
            } 
        } if (i == 3) {
            for (int k = 0 ; k < N ; k += 3) {
                flip(&arr, k); //xor with 1
            } 
            dfs(f+1);
            for (int k = 0 ; k < N ; k += 3) {
                flip(&arr, k); //xor with 1
            } 
        }
    }
} 

int main() {
    cin >> N;
    cin >> C;
    C = min(C, 4);
    for (int i = 0 ; i < N ; i++) {
        final[i] = -1;
        setp(&arr, i, 1);
    }

    int n;
    while (cin >> n && n != -1) {
        final[n-1] = 1;
    }

    while (cin >> n && n != -1) {
        final[n-1] = 0;
    }
    dfs(0);
    if (s.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
    }
    vector<string> p;
    for (unordered_set<pll, pair_hash>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        string s = "";
        for (int i = 0 ; i < N ; i++) {
            s += (check(*itr, i) != 0) + '0';
        }
        p.push_back(s);
    }
    sort(p.begin(), p.end());
    //reverse(p.begin(), p.end());
    for (string s : p) {
        cout << s << endl;
    }
}