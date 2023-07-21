#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    multiset<long long> highest;
    highest.insert(4);
    highest.insert(4);
    cout << highest.size() << endl;
    highest.erase(highest.lower_bound(4));
    cout << highest.size() << endl;

}