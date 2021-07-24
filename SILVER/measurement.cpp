//gamemode creatve
#include <vector>
#include <set>
#include <climits>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct three {
    int time;
    int tag;
    int amount;
};

vector<three> a;
unordered_map<int, int> umap;
unordered_map<int, int> milk;
unordered_map<int, int> amount;

struct less_than_key
{
    inline bool operator() (const three& struct1, const three& struct2)
    {
        return (struct1.time < struct2.time);
    }
};

int n;
int i, j;
int garb = 0;
int maxi = 0;
int amt = 0;
int main() {
    cin >> n;
    cin >> garb;
    for (int i = 0; i < n; i++) {
        int time;
        int tag;
        int amount;
        cin >> time >> tag >> amount;
        three nt;
        nt.time = time;
        nt.tag = tag;
        nt.amount = amount;
        a.push_back(nt); 
    }

    std::sort(a.begin(), a.end(), less_than_key());
    int ans = 0;
    int highest = 0;
    for (int i = 0;i < a.size(); i++) {
        bool prevIsZero = false;
        int prev = milk[a[i].tag];
        int prevAmount = amount[milk[a[i].tag]];
        amount[milk[a[i].tag]]--;
        if (amount[milk[a[i].tag]] == 0) {
            amount.erase(amount.find(milk[a[i].tag]));
        }

        milk[a[i].tag] += a[i].amount;
        amount[milk[a[i].tag]]++;
        if (milk[a[i].tag] >= highest) {
            if (a[i].amount > 0) {
                ans++;
                if (prevAmount == 1) {
                    if (prev == highest) {
                        ans--;
                    }
                }
                highest = milk[a[i].tag];
            }
        } else if (prev >= highest) {
            ans++;
            if (prevAmount == 1) {
                highest = INT_MIN;
                int check = 0;
                for (pair<int, int> k : amount) {
                    if (k.second >= 1 && k.first < prev && k.first > highest) {
                        highest = k.first;
                        check = k.second;
                    }
                } 
                if (highest == milk[a[i].tag] && check == 1) {
                    ans--;
                }
            }
        }
    }
    cout << ans;
    
}