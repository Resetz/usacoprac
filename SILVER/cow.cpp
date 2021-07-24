#include <iostream>

using namespace std;

long n;
string s;
int main() {
    cin >> n;
    cin >> s;

    long long c = 0;
    long long co = 0;
    long long cow = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') {
            c++;
        } else if (s[i] == 'O') {
            co += c;
        } else if (s[i] == 'W') {
            cow += co;
        }
    }
    cout << cow;
}