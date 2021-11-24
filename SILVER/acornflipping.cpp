
/*
Acorn Flipping
Feeling bored, Harry decides to play a game with his acorns. In this game, 
he has an N x N grid of acorns (2 <= N <= 1000), all of which are either 
facing left or right. For example:

RRL
RLR
LLR
Here, an 'R' means an acorn is facing right, and an 'L' means an acorn 
facing left. The goal of the game is to make all of the acorns facing
the same direction. However, Harry cannot just flip each acorn individually 
(that would be too easy); instead, he must flip an entire row or column of acorns at a time. While this game is normally solvable, Harry’s naughty friend, Barry, decided to secretly flip one of the acorns while Harry wasn’t looking, making it impossible to make all of the acorns facing the same direction. 

As such, the best Harry can do is make all but one acorn face the same 
direction. Please help Harry determine the identity of this acorn. 

INPUT FORMAT

The first line contains N. The next N lines describe rows 1..N in the 
grid of acorns, each containing a string of length N.

OUTPUT FORMAT

Print the row and column index of the acorn such that if it were flipped, 
Harry would be able to make all his acorns point in the same direction. If
no such acorn exists, print -1. If multiple possible acorns exist, print 
the acorn with the smallest row index, or if multiple of the possible acorns
have the same smallest row index, print the one with the smallest column index.

SAMPLE INPUT

3
RRL
RLR
LLR
SAMPLE OUTPUT

2 1
In the example above, the acorn in row 2, column 1 (the upper-left corner) is the out of place acorn, since Harry can flip row 1 and column 3 to make all other acorns point left, with just this acorn pointing right.
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int arr[1000][1000];


int main() {
    int n;
    cin >> n;
    

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n; j++) {
            char c;
            cin >> c;
            arr[i][j] = c == 'R';
        }
    }
    bool check[1000] = {false};
    bool check2[1000] = {false};
    for (int i = 0; i < n ;i++) {
        for (int j = 0 ; j < n ; j++) {
            check[j] ^= arr[i][j];
            check2[i] ^= arr[i][j];
        }
    }

    int x, y;
    vector<int> t;
    vector<int> f;
    for (int i = 0 ; i < n ; i++) {
        if (check[i]) t.push_back(i);
        else f.push_back(i);
    }
    if (t.size() == 1) {x = t[0] + 1;}
    else if (f.size() == 1) {x = f[0] + 1;}
    else {
        cout << "-1" << endl;
        return 0;
    }

    t.clear();
    f.clear();
    for (int i = 0 ; i < n ; i++) {
        if (check2[i]) t.push_back(i);
        else f.push_back(i);
    }

    if (t.size() == 1) {y = t[0] + 1;}
    else if (f.size() == 1) {y = f[0] + 1;}
    else {
        cout << "-1" << endl;
        return 0;
    }
    //if (x <= 3) { x--, y--;}
    cout << y << " " << x;
}
