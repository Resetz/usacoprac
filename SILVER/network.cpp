// IT"S SO CRAZY IT MIGHT WORK
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

long long n;
long long num;
int grid[9][9];

bool changed[9][9];

set<long long> v;

queue<pair<long long, long long>> q;

int valid(int number) {
    int ret = 0;
    int total = 1;

    for (int i = 0 ; i < n-1 ; i++) {
        total = 0;
        for (int j = 0 ; j < n-1 ; j++) {
            total += ((number & (1 << (j + i * n))) > 0);
        }
        

     
        if (total%2 == (((number & (1 << (i+1)*n-1))) > 0)) ret++;
        //else {cout << 0 << endl;}
    }
    //cout << endl;
    for (int i = 0 ; i < n-1 ; i++) {
        total = 0;
        for (int j = 0 ; j < n-1; j++) {
            total += ((number & (1 << (i + j * n))) > 0);
        }
        if (total%2 == (((number & (1 << ((n-1)*n+i)))) > 0)) ret++;
        //else {cout << 1 << endl;}
    }

    total = 0;
    for (int i = 0 ; i < n-1 ; i++) {
        total += ((number & (1 << ((n-1)*n+i))) > 0);
    }
    if (total%2 == (((number & (1 << (n*n-1))) > 0))) ret++;
    //else {cout << 2 << endl;}

    total = 0;
    for (int i = 1 ; i < n ; i++) {
        total += ((number & (1 << (n*i-1))) > 0);
    }
    if (total%2 == (((number & (1 << (n*n-1))) > 0))) ret++;
    //else {cout << 3 << endl;   
    return ret;
}

int main() {
    cin >> n;
    string s;
    cin >> s;

    num = 0;
    long long pow = 1;
    for (int i = 0 ; i < n*n ; i++) {
        if (s[i] == '1') {
            num += pow;
        }
        pow = pow * 2;
    }

    //cout << valid(num) << endl;
    q.push({num, 0});

    int found = false;
    int go = 0;

    vector<int> ans;

    while (!q.empty()) {
        pair<long long,long long> p = q.front();
        q.pop();
        if (found) {
            if (p.second != go) {
                break;
            } else if (valid(p.first) == n*2) {
                ans.push_back(p.first);
            }
        } else {
            if (valid(p.first) == n*2) {
                go = p.second;
                found = true;
                ans.push_back(p.first);
            }
        }

        for (int i = 0 ; i < n*n ; i++) {
            long long newn = p.first ^ (1 << i);
            /*
            for (int i = 0 ; i < n*n; i++) {
                cout << ((newn & (1 << i)) > 0);
            }
            cout << endl;*/
            if(valid(newn) > valid(p.first) && v.insert(newn).second) {q.push({newn, p.second+1});}
        }
    }
    if (ans.size() == 1) {
        cout << "ACK";
        cout << endl;
        cout << go << endl;
        for (int i = 0 ; i < n*n; i++) {
            cout << ((ans[0] & (1 << i)) > 0);
        }
        cout << endl;
    } else {
        cout << "NACK";
        cout << endl;
        cout << go << endl;
        cout << ans.size() << endl;
        for (int i = 0 ; i < ans.size() ; i++) {
            for (int j = 0 ; j < n*n ; j++) {
                cout << ((ans[i] & (1 << j)) > 0);
            }
            cout << endl;
        }
    }
}