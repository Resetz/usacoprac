#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int n = 5;
vector<int> v;
vector<int> ans;

bool done = false;

int di[]  {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6};
    
    int grid[5][5];

    int m[6] = {1,3,4,5,26};
    int k[6] = {};
    copy_n(m, 6, k);
    for (int i = 0 ; i < 6 ; i++) {
        cout << k[i] << " ";
    }
    cout << endl;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0 ; i < nums.size() ; i++) {
        cout << nums[i] << endl;
    }
}
