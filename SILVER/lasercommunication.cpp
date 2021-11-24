#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, a, b;

struct mirror {
    int x, y;
    int up, down, left, right;
    int type;
};

vector<pair<pair<int,int>, int>> v;

vector<mirror> mirrors;

int visited[200] = {-1};

int main() {
    cin >> N >> a >> b;

    for (int i = 0 ; i < N ; i++) {
        int x, y;
        char t;
        cin >> x >> y;
        cin >> t;
        mirrors.push_back({x,y, -1, -1, -1, -1, t == '/'});
    }
    mirrors.push_back({0, 0, -1, -1, -1, -1, 2});
    mirrors.push_back({a, b, -1, -1, -1, -1, 3});
    for (int i = 0 ; i < N+2 ; i++) {
        for (int j = 0 ; j < N+2 ; j++) {
            if (mirrors[i].x == mirrors[j].x) {
                if (mirrors[j].y > mirrors[i].y) {

                    if (mirrors[i].up == -1) mirrors[i].up = j;
                    if (mirrors[j].y < mirrors[mirrors[i].up].y) {
                        mirrors[i].up = j;
                    }

                } else if (mirrors[j].y < mirrors[i].y) {

                    if (mirrors[i].down == -1) mirrors[i].down = j;
                    if (mirrors[j].y > mirrors[mirrors[i].down].y) {
                        mirrors[i].down = j;
                    }

                }
            } else if (mirrors[i].y == mirrors[j].y) {

                if (mirrors[j].x > mirrors[i].x) {

                    if (mirrors[i].right == -1) mirrors[i].right = j;
                    if (mirrors[j].x < mirrors[mirrors[i].right].x) {
                        mirrors[i].right = j;
                    }

                } else if (mirrors[j].x < mirrors[i].x) {

                    if (mirrors[i].left == -1) mirrors[i].left = j;
                    if (mirrors[j].x > mirrors[mirrors[i].left].x) {
                        mirrors[i].left = j;
                    }

                }
            }
        } 
    }
    for (int i = 0 ; i < N ; i++) {
        visited[i] = -1;
    }
    int current = N;
    int direction = 0;
    while (current != -1) {
        //cout << mirrors[current].x << " " << mirrors[current].y << endl;
        if (current < N) {
            visited[current] = direction;
        } else if (mirrors[current].type == 3) {
            cout << 0 << endl;
            return 0;
        }
        
        int prev = direction;
        int ptype = mirrors[current].type;
        if (direction == 0) {
            current = mirrors[current].right;
        } else if (direction == 1) {
            current = mirrors[current].left;
        } else if (direction == 2) {
            current = mirrors[current].up;
        } else if (direction == 3) {
            current = mirrors[current].down;
        }
        if (mirrors[current].type == 1) {
            direction = (prev + 2) % 4;
        } else {
            /* \ */
            if (prev == 0) {
                direction = 3;
            } else if (prev == 1) {
                direction = 2;
            } else if (prev == 2) {
                direction = 1;
            } else if (prev == 3) {
                direction = 0;
            }
        }
    }

    //cout << "traversed first" << endl;

    int ans = -1;
    for (int i = 0 ; i < 4; i++) {
        int current = N+1;
        int direction = i;
        cout << direction << endl;
        while (current != -1) {
            cout << current << " " << mirrors[current].type << " " << mirrors[current].x << " " << mirrors[current].y << " " << direction;
            if (current < N) {
                if (visited[current] != -1) {
                    if (!(visited[current] == 1 && direction == 0 ||
                        visited[current] == 0 && direction == 1 ||
                        visited[current] == 2 && direction == 3 ||
                        visited[current] == 3 && direction == 2)) {
                        if (ans == -1) {
                            ans = current+1;
                        } else {
                            ans = min(current+1, ans);
                        }
                        break;      
                    }
                }
            }
            
            int prev = direction;
            int ptype = mirrors[current].type;
            if (direction == 0) {
                current = mirrors[current].right;
            } else if (direction == 1) {
                current = mirrors[current].left;
            } else if (direction == 2) {
                current = mirrors[current].up;
            } else if (direction == 3) {
                current = mirrors[current].down;
            }
            if (mirrors[current].type == 1) {
                direction = (prev + 2) % 4;
            } else {
                /* \ */
                if (prev == 0) {
                    direction = 3;
                } else if (prev == 1) {
                    direction = 2;
                } else if (prev == 2) {
                    direction = 1;
                } else if (prev == 3) {
                    direction = 0;
                }
            }
            cout << " -> " << direction << endl;
        }
    }
    cout << ans << endl;
}