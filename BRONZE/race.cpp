#include <iostream>
#include <vector>

using namespace std;

int go(int dist, int speed) {
    int cur = 0;
    int time = 0;
    
    cur += speed;
    time++;
    while (cur <= dist) {
        dist += speed + cur;
        time++;
        if (time % 2 == 0) cur++;
    }
    if (cur > dist) {
        
    }
    return time;
}

int main() {
    //freopen("race.in", "r", stdin);
    //freopen("race.out", "w", stdin);

    int k, n;
    cin >> k >> n;

    while (n--) {

        int s;
        cin >> s;

        int dist = 0;
        int speed =0;
        int time = 0;
        while (dist < k) {
            speed++;
            dist += speed;
            time++;
        }
        if (dist >= k) {
            cout << time << endl;
            continue;
        }
        
        cout << time + go(k-n, speed) << endl;
        
        //try to accel to speed
    }
}