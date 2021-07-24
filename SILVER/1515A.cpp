#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using std::sort;
int n, x, i, j, t, k;

int main() {
    
    cin >> t;

    vector<int> nums;
    
    int sum = 0;
    bool fix;
    int broken;
    for (i = 0; i < t; i++) {
        cin >> n >> x;
        broken = 0;
        fix = false;
        int fixI = 0;
        nums.clear();
        for (j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        std::sort(nums.begin(), nums.end());
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += nums[j];
            if (nums[j] == x && j == 0) {
                fix = true;
                fixI = j;
            } else if (sum == x) {
                fixI = j;
                fix = true;
            }
        }

        if (fix) { 
            if (n <= 2) {
                if (n == 2) {
                    if (nums[0] == x) {cout << "YES\n" << nums[1] << " " << nums[0] << endl;
                     } else {cout << "NO\n";}
                    continue;
                }
                cout << "NO\n";
            } else {
                
                
                if (fixI != n-1) {
                    cout << "YES\n";
                    if (fixI == 0) {
                        cout << nums[n-1] << " ";
                        for(j=0;j<n;j++) {
                            if (j != n-1) {
                                cout << nums[j] << " ";
                            }
                        }
                        cout << endl;
                        continue;
                    }
                    int temp = nums[n-1];
                    nums[n-1] = nums[fixI];
                    nums[fixI] = temp;
                    for(j=0;j<n;j++) {
                        cout << nums[j] << " ";
                    }
                    cout << "\n";
                } else {
                    cout << "NO\n";
                }
            }
        } else {
            cout << "YES\n";
            for(j=0;j<n;j++) {
                    cout << nums[j] << " ";
                } 
            cout << endl;
        }

        
    }

}