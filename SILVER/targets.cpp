#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int di[] = { 0,-1, 0, 1, -1,-1, 1,  1};
int dj[] = {-1, 0, 1, 0, -1, 1, 1, -1};

/*
 * Complete the 'missingArrow' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER size
 *  2. STRING targets
 *  3. STRING numbers
 *  4. STRING arrows
 */

string missingArrow(int size, string targets, string numbers, string arrows) {
    //cout << "here" << endl;
    int n = size;

    stringstream ss(targets);

    vector<vector<bool>> v(size, vector<bool>(size));
    int tot = 0;
    while (true) {
        string s;
        ss >> s;
        if (ss.fail()) break;
        tot++;
        //cout << " - " << s << " " << s[0] << " " << s[1] << endl;
        pair<int,int> p = {stoi(string{s[0]}), stoi(string{s[1]})};
        v[p.first][p.second] = true;        
    }

    //cout << "here" << endl;
    ss = stringstream(numbers);
    vector<int> vert(n);
    vector<int> hori(n);
    string vs, hs;
    ss >> vs >> hs;

    for (int i = 0 ; i < n ; i++) {
        vert[i] = stoi(string{vs[i]});
        hori[i] = stoi(string{hs[i]});
    }
    ss = stringstream(arrows);
    for (int i = 0 ; i < tot-1 ; i++) {
        string s;
        ss >> s;
        pair<int,int> pos = {stoi(string{s[0]}), stoi(string{s[1]})};
        //cout << pos.first << " " << pos.second << " " << s[2] << endl;
        vert[pos.first]--;
        hori[pos.second]--;
        int dir = s[2] - 'A';
        while (!v[pos.first][pos.second]) {
            pos.first += di[dir];
            pos.second += dj[dir];
        }
        v[pos.first][pos.second] = false;
    }
    pair<int,int> good;
    pair<int,int> arro;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (v[i][j]) good = {i,j};
            if (vert[i] && hori[j]) arro = {i,j};
        }
    }
    pair<int,int> pos = arro;
    arro = {good.first - arro.first, good.second - arro.second};
    if (arro.first != 0) {
        arro.second /= abs(arro.first);
        arro.first /= abs(arro.first);
    } else {
        arro.second /= abs(arro.second);
    }
    int ans = 0;
    //cout << arro.first << " " << arro.second << endl;
    for (int i = 0 ; i < 8 ; i++) {
        if (di[i] == arro.first && dj[i] == arro.second) {
            ans = i;
        }
    }
    stringstream ret;
    ret << pos.first << pos.second << (char)('A' + ans);
    return ret.str();

}

int main()
{
    string size_temp;
    getline(cin, size_temp);

    int size = stoi(ltrim(rtrim(size_temp)));

    string targets;
    getline(cin, targets);

    string numbers;
    getline(cin, numbers);

    string arrows;
    getline(cin, arrows);

    string result = missingArrow(size, targets, numbers, arrows);

    cout << result << "\n";

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
