#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m,q;

    cin >> n >> m >> q;

    vector<int> swap(m);
    for (int i = 0 ; i < m ; i++) {
        int num;
        cin >> num;
        
        num--;
        swap[num] = i;
        /*
        num--;
        swap[i] = num;*/
    }

    for (int i = 0 ; i < q ; i++) {
        int num;
        cin >> num;
        num = n-num;
        int val = min(num, n-m);
        //cout << num << " " << num - val << endl;
        num = num-val;
        while (val >= 0) {
            //cout << "- " << num << "->" << swap[num] << " " << val << endl;
            num = swap[num];
            if (num == m-1) break;
            num++;
            val--;
        }
        cout << num+val+1 << endl;
    }
}