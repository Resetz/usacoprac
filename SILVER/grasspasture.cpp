#include <iostream>
#include <vector>
#include <set>
#include <queue>


using namespace std;

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        return a.first > b.first;
    }
};

vector<int> v;
int n;
int t;

bool go(int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

    for (int i = 0; i < k; i++) {
        pq.push(pair<int,int>{v[i], i+k});
    }

    int lastpopped = 0;
    int count = 0;
   // cout << " - " << k << endl;
    while (count < n) {
    
        pair<int,int> p = pq.top();
        lastpopped = max(lastpopped, p.first);
        //cout << "a " << p.first << endl;
        pq.pop();

        if ( k+count < n ) {
            pq.push(pair<int,int>{p.first+v[k+count], p.second+k});
        }
        count++;
    }
   // cout << k << "  " << lastpopped << endl;
    return lastpopped <= t;
}

int main() {
    cin >> n >> t;
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    int high = n;
    int low = 1;
    int ans = 0;
    while ( high >= low) {
        //cout << "hl " << high << " " << low << endl;
        int middle = low + (high - low)/2;
        if (go(middle)) {
            ans = middle;
            high = middle-1;
        } else {
            low = middle+1;
        }
    }
    cout << ans << endl;
}