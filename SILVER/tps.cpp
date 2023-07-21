#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;



/*
 * Complete the 'countUniqueSums' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING inputString as parameter.
 */
vector<int> sum;
vector<pair<int,int>> et;
vector<int> t;

void dfs(vector<int> &v, vector<pair<int,pair<int,int>>> &tree, int cur, int cursum) {
    if (cur == -1) {return;}
    sum[cur] = cursum + v[cur];
    dfs(v, tree, tree[cur].second.first, sum[cur]);
    dfs(v, tree, tree[cur].second.second, sum[cur]);
}

void euler(vector<pair<int,pair<int,int>>> &tree, int cur, int d) {
    if (cur == -1) return;
    if (t[cur] == -1) t[cur] = (int)et.size();
    et.push_back({d,cur});
    if (tree[cur].second.first != -1) {
        euler(tree, tree[cur].second.first, d+1);
        et.push_back({d,cur});
    }
    if (tree[cur].second.second != -1) {
        euler(tree, tree[cur].second.second, d+1);
        et.push_back({d,cur});
    }
}

pair<int,int> query(vector<vector<pair<int,int>>> rmq, int f, int t) {
    pair<int,int> ret = rmq[0][f];
    int cur = 9;
    while (cur >= 0) {
        if (f + (1<<cur) <= t+1) {
            if (rmq[cur][f].first < ret.first) {
                ret = rmq[cur][f];
            }
            f += (1<<cur);
        }
        cur--;
    }
    return ret;
}

int countUniqueSums(string inputString) {
    int n = inputString.size();
    vector<pair<int,pair<int,int>>> tree(n);
    vector<int> v(n);
    for (int i = 0 ; i < inputString.size() ; i++) {
        int val = inputString[i] - '0';
        tree[i] = {-1, {-1,-1}};
        v[i] = val;
        int cur = 0;
        int prev = -1;
        bool left = false;
        while (cur != -1) {
            int check = -1;
            if (val <= v[cur]) {
                left = true;
                check = tree[cur].second.first;
            } else {
                left = false;
                check = tree[cur].second.second;
            }
            prev = cur;
            cur = check;
            //cout << cur << endl;
        }
        if (i != 0) {
            if (left) {
                tree[prev].second.first = i;
            } else {
                tree[prev].second.second = i;
            }
            tree[i].first = prev;
        }
        //cout << tree[i].first << " " << tree[i].second.first << " " << tree[i].second.second << endl;
    }

    sum.resize(n);
    t.resize(n, -1);
    dfs(v, tree, 0, 0);
    euler(tree, 0, 0);
    
    //cout << "fin" << endl;
    vector<vector<pair<int,int>>> rmq(10, vector<pair<int,int>>(600));
    for (int i = 0 ; i < (int)et.size() ; i++) {
        //cout << et[i].first << " " << et[i].second << endl;
        rmq[0][i] = et[i];
    }

    for (int i = 1 ; i < 10 ; i++) {
        for (int j = 0 ; j < (int)et.size() - (1 << i) ; j++) {
            pair<int,int> a = rmq[i-1][j];
            pair<int,int> b = rmq[i-1][j+(1<<(i-1))];
            if (a.first < b.first) {
                rmq[i][j] = a;
            } else {
                rmq[i][j] = b;
            }
        }
    }

    //cout << "fin" << endl;
    set<int> ans;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (t[j] <= t[i]) continue;
            pair<int,int> p = query(rmq, t[i], t[j]);
            ans.insert(sum[i] + sum[j] - 2*sum[p.second] + v[p.second]);
            //cout << i << " " << j << " " << p.second << endl;
            //cout <<t[i] << " " << t[j] << endl;
            //cout << sum[i] + sum[j] - 2*sum[p.second] + v[p.second] << endl;
        }
    }
    return ans.size();
}   

int main()
{

    string inputString;
    getline(cin, inputString);

    int result = countUniqueSums(inputString);

    cout << result << "\n";

    return 0;
}
