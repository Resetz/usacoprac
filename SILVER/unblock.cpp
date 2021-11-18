#include <vector>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

bool visited[40][40][40][40];
vector<pair<int,int>> blocks[3];

//bounding box
pair<int,int> box1[3];
pair<int,int> box2[3];
pair<int,int> refp[3];

int local_offset[4] = {0,0,0,0}; // used to store some values locally.


int a,b,c;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

typedef struct node {
    int pos[4];
    int time;
} node_t;

bool overlap(pair<int,int> l1, pair<int,int> r1, pair<int,int> l2, pair<int,int> r2) {
    if (l1.first == r1.first || l1.second == r1.second || l2.first == r2.first || l2.second == r2.second) return false;
    if (l1.first >= r2.first || l2.first >= r1.second) return false;
    if (r1.second >= l2.second || r2.second >= l1.second) return false;
    return true;
}

bool overlap(int a, int b) {
    int x1,y1;
    int x2,y2;
    if (a == 0) { //first block is static 
        x1 = box1[a];
        y1 = box2[a];
    } else {
        x1 = 
    }
}

bool check(node_t node) {
    set<pair<int,int>> s;
    for (int i = 0 ; i < a ; i++) {
        if (!s.insert(blocks[0][i]).second) return false;
    }
    for (int i = 0 ; i < b ; i++) {
        int x, y;
        x = blocks[1][i].first + local_offset[0];
        y = blocks[2][i].second + local_offset[1];
        if (!s.insert({x,y}).second) return false;
    }
    for (int i = 0 ; i < b ; i++) {
        int x, y;
        x = blocks[1][i].first + local_offset[2];
        y = blocks[2][i].second + local_offset[3];
        if (!s.insert({x,y}).second) return false;
    }
    return true;
}


int main() {
    //read in data

{
    cin >> a >> b >> c;

    blocks[0].resize(a);
    blocks[1].resize(b);
    blocks[2].resize(c);
    
    int bot = INT_MAX;
    int top = 0;
    int left = INT_MAX;
    int right = 0;


    for (int i = 0 ; i < a ; i ++) {
        int x, int y;
        cin >> x >> y;
        if (i == 0) refp[0] = {x, y};
        x -= refp[0].first;
        y -= refp[0].first;
        blocks[0][i].first = x;
        blocks[0][i].second = y;
        bot = min(bot, y);
        top = max(top, y);
        left = min(left, x);
        right = max(right, x);
    }
    box1[0] = {top, left};
    box2[0] = {bot, right};

    bot = INT_MAX;
    top = 0;
    left = INT_MAX;
    right = 0;
    for (int i = 0 ; i < b ; i ++) {
        int x, int y;
        cin >> x >> y;
        if (i == 0) refp[1] = {x, y};
        blocks[1][i].first = x;
        blocks[1][i].second = y;
        bot = min(bot, y);
        top = max(top, y);
        left = min(left, x);
        right = max(right, x);
    }
    box1[1] = {top, left};
    box2[1] = {bot, right};

    bot = INT_MAX;
    top = 0;
    left = INT_MAX;
    right = 0;
    for (int i = 0 ; i < c ; i ++) {
        int x, int y;
        cin >> x >> y;
        if (i == 0) refp[2] = {x, y};
        blocks[2][i].first = x;
        blocks[2][i].second = y;
        bot = min(bot, y);
        top = max(top, y);
        left = min(left, x);
        right = max(right, x);
    }

    box1[2] = {top, left};
    box2[2] = {bot, right};
}


    node_t o = {20,20,0,0, 0};
    queue<node_t> q;
    while (!q.empty()) {
        node_t t = q.front();
        q.pop();
        if (t.pos == 0)
        if (visited[t.pos[0]][t.pos[1]][t.pos[2]][t.pos[3]]) continue;
        visited[t.pos[0]][t.pos[1]][t.pos[2]][t.pos[3]] = true;
        if (!overlap(box1[0], box2[0], box1[1], box2[1]) 
         && !overlap(box1[1], box2[1], box1[2], box2[2]) 
         && !overlap(box1[2], box2[2], box1[0], box2[0])) {
             cout << t.time << endl;
             return;
         }

        //check if any blocks overlap.
    
        if (!check(t)) continue;

        //add to the queue
        for (int i = 0;  i < n ; i++) {

        }
        
        
    }
}