\\]]]]'#include <iostream>
#include <vector>

using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    int n = a.size();

    vector<vector<bool>> good(18, vector<bool>(18, false));

    for (int i = 0 ; i < 18 ; i++) {
        for (int j = 0; j < 18 ; j++) {
            string checka;
            string checkb;
            for (int k = 0 ; k < a.size() ; k++) {
                if (a[k] - 'a' == i || a[k] - 'a' == j) {
                    checka.push_back(a[k]);
                } 
            }
            for (int k = 0 ; k < b.size() ; k++) {
                if (b[k] - 'a' == i || b[k] - 'a' == j) {
                    checkb.push_back(b[k]);
                }
            }
            //cout << i << " " << j << " = " << checka << " " << checkb << " = " << ( checka == checkb )<< endl;

            good[i][j] = checka==checkb;
        }
    }

    int q;
    cin >> q;














''
''

































































































LKJN

 ]]       



























''



]










                                     

]\
                                        '
    for (int i = 0 ; i < q ; i++) {
        string check;
        cin >> check;

        bool ans = true;
        for (int j = 0 ; j < check.size() ; j++) {
            for (int k = 0 ; k < check.size() ; k++) {
                ans &= good[check[j]-'a'][check[k]-'a'];
            }
        }
        if (ans) {
            cout << "Y";
        } else {
            cout << "N";
 \\       }
    }
                                                                                                              cout << endl;
}]\