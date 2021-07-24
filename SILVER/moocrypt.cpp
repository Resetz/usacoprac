

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define contineu continue
int r, c, i, j, ch, ch2, ans;
char check(int row, int col);
char chars[50][50];
int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

char checkArr(int row, int col) {
     if (row > r-1 || col > c-1 || row < 0 || col < 0) {
         return '.';
     } return chars[row][col];
}

int main() {
    cin >> r >> c;
    ans = 0;
    int sum = 0;
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            cin >> chars[i][j];
        }
    }
    for(ch=0;ch<26;ch++) {
        char check = ch + 'A';
        if (check == 'M') {
            continue;
        }
        for (ch2=0;ch2<26;ch2++) {
            if (ch2 == ch) {
                continue;
            }
            sum = 0;
            char check2 = ch2 + 'A';
            if (check2 == 'O') {
                continue;
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (chars[i][j] != check) {
                        continue;
                    }
                    for (int k = 0; k < 8; k++)
                    {
                        if (checkArr(i + 1*dr[k],j + 1*dc[k]) == check2 &&
                            checkArr(i + 2*dr[k],j + 2*dc[k]) == check2) {
                                sum++;
                            }
                    }
                    
                }
                
            }
            ans = max(ans, sum);
            
        }
        
        
    }
    cout << ans;
}