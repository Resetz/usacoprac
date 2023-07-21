#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'findModeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER num
 *  2. INTEGER base
 *  3. STRING start
 */

int findModeCount(int num, int base, string start) {
    vector<int> v(start.size());
    map<int,int> m;
    for (int i = 0 ; i < start.size() ; i++) {
        if (start[i] >= '0' && start[i] <= '9') {
            v[i] = start[i]-'0';
        } else {
            v[i] = start[i]-'A' + 10;
        }
        //cout << (int) v[i] << " " << endl;
    }

    reverse(v.begin(), v.end());
    vector<int> count(base, 0);
    for (int i = 0 ; i < num ; i++) {
        //n solution
        //log(n) with dp
        
        bool nxt = false;
        for (int j = 0 ; j < v.size() ; j++) {
            //nxt &= v[j] == base-1;
            count[v[j]]++;
            if (j == 0) {
                v[j] = (v[j] + 1) % base;
                if (v[j] == 0) nxt = true;
            } else {
                if (nxt) {
                    v[j] = (v[j] + 1) % base;
                }
                if (v[j] != 0) {
                    nxt = false;
                }
            }
        }
        if (nxt) v.push_back(1);
    }
    int ans = 0;
    for (int i = 0 ; i < base ; i++) {
        ans = max(ans, count[i]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string num_temp;
    getline(cin, num_temp);

    int num = stoi(ltrim(rtrim(num_temp)));

    string base_temp;
    getline(cin, base_temp);

    int base = stoi(ltrim(rtrim(base_temp)));

    string start;
    getline(cin, start);

    int result = findModeCount(num, base, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
