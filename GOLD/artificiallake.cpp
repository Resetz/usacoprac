#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int main() {
    int n; cin >> n;
    int last = 0;
    vector<pair<int,int>> v(n+1);
    v[0] = {0, INT_MAX};
    int lowest = 1;
    for (int i = 0 ; i < n ; i++) {
        int l;
        cin >> l >> v[i+1].second;
        last += l;
        v[i+1].first = last;
        if (v[i+1].second < v[lowest].second) {
            lowest = i+1;
        }
    }

    v.push_back({last, INT_MAX});
   // cout << endl;
    long long time = 0;
    vector<long long> ans(n);
    
    int l = lowest-1;
    int r = lowest+1;
    stack<pair<int,pair<int,int>>> left;
    stack<pair<int,pair<int,int>>> right;
   // int level = v[lowest].second;
    //cout << "here " << lowest << endl;

    ans[lowest] = v[r].first - v[l].first;
    left.push({l,v[l]});
    right.push({r,v[r]});

    ans[lowest-1] = v[lowest].first - v[l].first;
    //time += min(v[r].second, v[l].second) * (v[lowest].first - v[l].first);
    int level = v[lowest].second;
    while (l > 0 || r <= n) {
        bool goingRight = v[l].second > v[r].second;
        //cout << l << " " << r << " " << goingRight << endl;
        stack<pair<int,pair<int,int>>> go = goingRight ? right : left;
        int last = goingRight ? v[r].second : v[l].second;
        int *cur = (goingRight ? &r : &l);
        time += abs(v[r-1].first - v[l].first) * (last - level);
        level = last;
       // cout << "before " << time << endl;
    
        //cout << go.top().second.second << " " << *cur << " " << last << endl;
        do {
            *cur += goingRight ? 1 : -1;
            //cout << "cur" << *cur << endl;
            pair<int,pair<int,int>> temp = go.top();
            go.pop();
            pair<int,int> farthest = go.top().second;
            go.push(temp);
            while (go.size() > 1 && go.top().second.second < v[*cur].second) {
                int ind = go.top().first;
                pair<int,int> prev = go.top().second;
                go.pop();
                ans[ind-1] = time + abs(prev.first - go.top().second.first);
                time += (min(v[*cur].second, go.top().second.second) - prev.second) * abs(prev.first - go.top().second.first); 
               // cout << "pour " << time << endl;
            }
            go.push({*cur, v[*cur]});
        } while (*cur > 0 && *cur <= n && go.top().second.second < last);

        //cout << "time " << time << " " << go.top().second.first << endl;
        pair<int,pair<int,int>> temp = go.top();
        go.pop();
       // cout << go.size() << endl;
        ans[go.top().first-1] = time + abs(temp.second.first - v[l].first);
        go.pop();
        go.push(temp); 
       // cout << go.size() << endl;
    }
    //cout << "finish" << endl;
    /*
    for (int i = 1 ; i <= n ; i++) {
        //cout << v[i].first << " " << v[i].second << endl;
        while (cur.size() > 1 && v[i].second > cur[cur.size()-1].second.second) {
           //cout << " - " << cur[cur.size()-1].second.first << " " << cur[cur.size()-1].second.second << endl;
            ans[cur[cur.size()-1].first] = time + v[i-1].first - cur[cur.size()-2].second.first;
            time += (min(v[i].second, cur[cur.size()-2].second.second) - cur[cur.size()-1].second.second) * (cur[cur.size()-1].second.first - cur[cur.size()-2].second.first);
            cur.pop_back();
        }
        cur.push_back({i,v[i]});
    }
    */
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << endl;
    }
}