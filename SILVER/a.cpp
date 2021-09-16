#include <stdio.h>
using namespace std;
long long arr[20][20];
long long arr2[20];
int
    count;
int main()
{
    scanf("\x25\x64", &count);
    arr2[0]= 1;
    for (int count = 1;
         count < 20; count++) {
        arr2[count] = arr2[count - 1] * count;
    }
    for (int count = 0;
         count < 20;
         count++) {
        arr[count][0] = 1;
        arr[0][count] = 1;
    }
    for (int i = 1;
         i < 20;
         i++) {
        for (int
                 j
             = 1;
             j < 20;
             j++) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    int ans = count / 2;
    printf("\x25\x6c\x6c\x64", arr[ans - 1][ans] * arr2[ans - 1] * arr2[ans - 1]);
}