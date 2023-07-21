#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;



vector<vector<bool>> visited;
vector<vector<set<int>>> touched;
vector<vector<int>> id;
vector<vector<int>> v;
vector<vector<int>> si;

vector<vector<int>> ans;
int res = 0;
int n;

int di[] = {0,0,-1,1};
int dj[] = {1,-1,0,0};

int hasht(int x, int y) {
    return x * 62500 + y;
}

void ff(int x, int y, int cur) {
    if (x >= 0 && y >= 0 && x < n && y < n) {
        if (v[x][y] == cur && !visited[x][y]) {
            visited[x][y] = true;
            res++;
            for (int i = 0 ; i < n ; i++) {
                ff(x+di[i],y+dj[i],cur);
            }
        }
    }
}
void ff2(int x, int y, int cur, int amt, int idn) {
    if (x >= 0 && y >= 0 && x < n && y < n) {
        if (v[x][y] == cur && si[x][y] == -1) {
            si[x][y] = amt;
            id[x][y] = idn;
            for (int i = 0 ; i < n ; i++) {
                ff2(x+di[i],y+dj[i],cur,amt,idn);
            }
        }
    }
}

void ff3(int x, int y, int cur) {
    //find adjacent and add
    map<int, int> adj;
    set<int> touched;
    if (x >= 0 && y >= 0 && x < n && y < n) {
        if (v[x][y] == cur && !visited[x][y]) {
            visited[x][y] = true;
            for (int i = 0 ; i < n ; i++) {
                ff3(x+di[i],y+dj[i],cur);
            }
        } else if (v[x][y] != cur) {
            if (touched.insert(id[x][y]).second) {
                ans[cur][v[x][y]] += si[x][y];
            }
        }
    }
}

int main() {
    cin >> n;

    v.resize(n, vector<int>(n));
    si.resize(n, vector<int>(n, -1));
    id.resize(n, vector<int>(n, -1));
    ans.resize(n, vector<int>(n, 0));
    touched.resize(n, vector<set<int>>(n, set<int>()));
    visited.resize(n, vector<bool>(n));
    
    map<int,int> m;
    set<int> s;
    int k = 0;
    for (int i = 0 ; i < n ;i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> v[i][j];
            if (s.insert(v[i][j]).second) {
                m[v[i][j]] = k;
                k++;
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            v[i][j] = m[v[i][j]];
        }
    } 

    cout << "first" << endl;
    int curid = 1;
    vector<int> single(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (!visited[i][j]) {
                ff(i,j,v[i][j]);
                cout << curid << " " << res << endl;
                //id and size everything
                ff2(i, j, v[i][j], res, curid);

                single[v[i][j]] = res;
                res = 0;
                curid++;
            }
        }
    }
    cout << "first" << endl;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            visited[i][j] = false;
        }
    }

    cout << "first" << endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (!visited[i][j]) {
                ff3(i, j, v[i][j]);
            }
        }
    }

    int end = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            end = max(end, ans[i][j]+single[i]);
        }
    }
    cout << end << endl;

}