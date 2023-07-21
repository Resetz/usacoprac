#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int x1,y1,x2,y2;
} sq;

int contained(sq a, sq b) {
    return (b.x1 > a.x1 && b.y1 > a.y1 && b.x2 < a.x2 && b.y2 < a.y2);
}

int main() {
    int n;
    cin >> n;


    vector<sq> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    }

    //cout << contained(v[2], v[1]) << endl;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        bool good = true;
        for (int j = 0 ; j < n ; j++) {
            if (i == j) continue;
            if (!(good = !contained(v[j],v[i]))) break;
        }
        ans += good;
    }
    cout << ans << endl;
}