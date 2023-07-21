#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<bool> visited;
vector<int> target;
int targetnum;
vector<int> pow8;
string db = "ABCCB";

int encode(vector<int> e) {
    int ret = 0;
    for (int i = 0 ; i < 8 ; i++) {
        ret += e[i] * pow8[i];
    }
    return ret;
}

int op(int num, int o) {
    vector<int> cur(8);
    for (int i = 0 ; i < 8 ; i++) {
        cur[i] = num % 8;
        num/=8;
    }
    if (o == 0) {
        for (int i = 0 ; i < 4; i++) {
            int temp = cur[i];
            cur[i] = cur[i+4];
            cur[i+4] = temp;
        }// end
        num = 0;
        for (int i = 0 ; i < 8 ; i++) {
            num += pow8[i]*cur[i];
        }
        return num;
    } else if (o == 1) {
        int temp = cur[3];
        cur[3] = cur[2];
        cur[2] = cur[1];
        cur[1] = cur[0];
        cur[0] = temp;

        temp = cur[7];
        cur[7] = cur[6];
        cur[6] = cur[5];
        cur[5] = cur[4];
        cur[4] = temp;
        num = 0;
        for (int i = 0 ; i < 8 ; i++) {
            num += pow8[i]*cur[i];
        }
        return num;
    } else {
        int temp = cur[1];
        cur[1] = cur[5];
        cur[5] = cur[6];
        cur[6] = cur[2];
        cur[2] = temp;
        num = 0;
        for (int i = 0 ; i < 8 ; i++) {
            num += pow8[i]*cur[i];
        }
        return num;
    }
}

int main() {
    pow8.resize(8);
    pow8[0] = 1;
    for (int i = 1; i < 8 ; i++) {
        pow8[i] = pow8[i-1]*8;
    }

    vector<int> cur;
    cur = {0,1,2,3,7,6,5,4};
    visited.resize(134217728);
    target.resize(8);
    cin >> target[0];
    cin >> target[1];
    cin >> target[2];
    cin >> target[3];
    cin >> target[7];
    cin >> target[6];
    cin >> target[5];
    cin >> target[4];
    for (int i = 0 ; i < 8 ; i++) target[i]--;

    targetnum = encode(target);
    queue<pair<int, string>> q;

    q.push({encode(cur),""});
    string done;
    while (!q.empty()) {
        pair<int, string> p = q.front();
        q.pop();
        if (visited[p.first]) continue;
        bool yes = true;
        visited[p.first] = true;
        if (p.first == targetnum) {
            done = p.second;
            break;
        }
        for (int i = 0 ; i < 3 ; i++) {
            if (!visited[op(p.first,i)]) q.push({op(p.first,i), p.second + (char)('A'+i)});
        }
    }

    cout << done.size() << endl;
    for (int i = 0 ; i < done.size() ; i++) {
     
        cout << done[i];
        if (i+1%60 == 0) cout << endl;
    }
}