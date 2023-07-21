#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<int> v;
int target;
double best;
double ans;
string string_ans;

char op[] = {'+', '-', '*', '/'};

string cur = "";
int n;
vector<int> vis;


vector<string> split(string s) {

    vector<string> ret;

    size_t pos = 0;
    while ((pos = s.find(" ")) != string::npos) {
        if (s.substr(0, pos).size() > 0) {
            ret.push_back(s.substr(0, pos));
        }
        s.erase(0, pos + 1);
        
    }
    ret.push_back(s);
    return ret;
}

float evaluateExpression(string s) {
    vector<string> splitString = split(s);
    if (splitString.size() == 1) return stof(splitString[0]);
    
    bool opFinished = false;
    //Performs all multiplication and division (left to right)
    for (int i = 1 ; i < splitString.size()-1; i++) {
        if (splitString[i].size() == 1 && (splitString[i][0] == '*' || splitString[i][0] == '/')) {
            float res = stof(splitString[i-1]);
            if (splitString[i][0] == '*') {
                res *= stof(splitString[i+1]);
            } else {
                res /= stof(splitString[i+1]);
            }
            opFinished = true;

            splitString[i] = splitString[i-1] = "";
            splitString[i+1] = to_string(res);
        }
    }
    if (!opFinished) {
        for (int i = 1 ; i < splitString.size()-1; i++) {
            //cout << splitString[i-1] << " " << splitString[i] << " " << splitString[i+1] << endl;
            if (splitString[i].size() == 1 && (splitString[i][0] == '+' || splitString[i][0] == '-')) {
                float res = stof(splitString[i-1]);
                if (splitString[i][0] == '+') {
                    res += stof(splitString[i+1]);
                } else {
                    res -= stof(splitString[i+1]);
                }
                opFinished = true;

                splitString[i] = splitString[i-1] = "";
                splitString[i+1] = to_string(res);
            }
        }
    }
    

    //Create a new string for recursion
    string newString = "";
    for (int i = 0 ; i < splitString.size() ; i++) {
        if (splitString[i] == "") continue;

        //Append token to the newString
        newString += splitString[i];

        //Place a space after the current token, but
        //do not place a space after the last token
        if (i != splitString.size()-1) newString += " ";
    }

    //cout << newString << endl;
    return evaluateExpression(newString);

}
void dfs(int k)  {

    vis[k] = true;
    //cout << cur << endl;
    //cout << evaluateExpression(cur) << endl;
    float rn = evaluateExpression(cur);
    if (abs(rn - target) <= best) {
        if (abs(rn - target) == best) {
            if (string_ans.size() > cur.size()) {
                string_ans = cur;
            }
        }
        best = abs(evaluateExpression(cur) - target);
        //cout << cur << endl;
        ans = evaluateExpression(cur);

        string_ans = cur;
        
    }
    for (int i = 0 ; i < n ; i++) {
        if (vis[i]) continue;

        string temp = cur;
        for (int j = 0 ; j < 4 ; j++) {
            if (rn > target && (j == 1 || j == 3)) continue;
            cur = temp + " " + op[j] + " " + to_string(v[i]);
            dfs(i);
            cur = temp;
        }
    }
    vis[k] = false;

}

int main() {
    v = {8  ,    3  , 1   ,  7     , 40  ,    50};
    n = v.size();
    vis.resize(n, false);
    target = 703;
    best = 703;
    ans = 0;
    //cout << evaluateExpression("50 * 8 + 7 * 40 + 3 + 1") << endl;
    
    for (int i = 0 ; i < n ; i++) {
        cur = to_string(v[i]);
        cout << cur << endl;
        dfs(i);
    }
    cout << string_ans << endl;
    cout << best << endl;
    cout << ans << endl;

}