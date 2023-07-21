#include <set>
#include <iostream>

using namespace std;

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        if (a.second > b.second) {
            return a.first > b.first;
        } else {
            return false;
        }
    }
};
int main() {
    set<pair<int,int>, Compare> s;
    s.insert({1,0});
    s.insert({2,0});
    s.insert({3,0});
    s.insert({2,0});
    cout << s.size() << endl;
}