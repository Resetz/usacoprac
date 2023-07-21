#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <functional>

using namespace std;



/*
 * Complete the 'getTraversals' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING input as parameter.
 */

typedef struct {
    char c;
    int l,r;
} node;

string getTraversals(string input) {
    int n = input.size();
    vector<pair<char,int>> v(n);
    for (int i = 0 ; i < n; i++) {
        v[i] = {input[i], i};
    }
    //sort(v.begin(), v.end());
    //vector<int> pos(26, -1);
    //for (int i = 0 ; i < n ; i++) {
    //    pos[v[i].first-'A'] = v[i].second;
    //}
    vector<node> nodes;
    nodes.push_back({v[0].first, -1, -1});
    for (int i = 1 ; i < n ; i++) {
        int curnode = 0;
        nodes.push_back({v[i].first, -1, -1});
        while (true) {
            if (v[i].first <= nodes[curnode].c) {
                if (nodes[curnode].l == -1) {
                    nodes[curnode].l = i;
                    break;
                } else {
                    curnode = nodes[curnode].l;
                }
            } else {
                if (nodes[curnode].r == -1) {
                    nodes[curnode].r = i;
                    break;
                } else {
                    curnode = nodes[curnode].r;
                }
            }
        }
    }

    stringstream ans;
    
    std::function<void(int)> trava;
    trava = [nodes, &ans, &trava](int cur) -> void {
        if (cur == -1) return;
        ans << nodes[cur].c;
        trava(nodes[cur].l);
        trava(nodes[cur].r);
    };
    trava(0);
    ans << " ";

    trava = [nodes, &ans, &trava](int cur) -> void {
        if (cur == -1) return;
        trava(nodes[cur].l);
        trava(nodes[cur].r);
        ans << nodes[cur].c;
    };
    trava(0);
    return ans.str();
}

int main()
{
    string input;
    cin >> input;

    string result = getTraversals(input);

    cout << result << "\n";

    return 0;
}
