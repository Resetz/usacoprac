#define _CRT_SECURE_NO_WARNINGS false
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
using std::string;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define ITERL(it, arr) for (it = arr.begin(); it < arr.end(); it++)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef unsigned long long ll;
typedef unsigned char u8;
typedef char s8;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T& x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T& x, U y) { if (x < y) x = y; }
/**********************************************/

/****** Commonly Used Variables *****/
/* Iterator Variables */
int i, j, k;

/* Input Variables */
int n, m, o, p, a, b;
/**********************************************/


/* MAIN FUNCTION */

bool toggle[200000];
int ones, zeroes, onesLeft, onesRight;

int main() {
    fast;

    cin >> n;
    REP(i, n) {
        int l;
        string s;
        cin >> l >> s;

        zeroes = 0;
        onesLeft = 0;
        onesRight = 0;
        ones = 0;

        if (l % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }

        

        REP(j, l) {
            if (s[j] == '1') {
                toggle[j] = true;
                ones++;
            } else {
                toggle[j] = false;
                zeroes++;
            }
        }


        if ( ones % 2 != 0 || zeroes % 2 != 0 || (!toggle[0] || !toggle[l-1])) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int counter = 0;
        bool alternate = true;
        // true -> "("
        REP(j, l) {

            if (toggle[j]) {
                if (counter < ones/2) {
                    counter++;
                    cout << "(";
                } else {
                    cout << ")";
                }
            } else {
                if (alternate) {
                    cout << ")";
                    alternate = !alternate;
                } else {
                    cout << "(";
                    alternate = !alternate;
                }
            }
        }
        cout << endl;
        counter = 0;
        alternate = false;
        REP(j, l) {

            if (toggle[j]) {
                if (counter < ones/2) {
                    counter++;
                    cout << "(";
                } else {
                    cout << ")";
                }
            } else {
                if (alternate) {
                    cout << ")";
                    alternate = !alternate;
                } else {
                    cout << "(";
                    alternate = !alternate;
                }
            }
        }
        cout << endl;

        

        
    }
}
