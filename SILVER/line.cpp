/*
Cow Line
========

The N (1 <= N <= 20) cows conveniently numbered 1...N are playing
yet another one of their crazy games with Farmer John. The cows
will arrange themselves in a line and ask Farmer John what their
line number is. In return, Farmer John can give them a line number
and the cows must rearrange themselves into that line.

A line number is assigned by numbering all the permutations of the
line in lexicographic order.

Consider this example:
Farmer John has 5 cows and gives them the line number of 3.
The permutations of the line in ascending lexicographic order:
1st: 1 2 3 4 5
2nd: 1 2 3 5 4
3rd: 1 2 4 3 5

Therefore, the cows will line themselves in the cow line 1 2 4 3 5.

The cows, in return, line themselves in the configuration "1 2 5 3 4" and 
ask Farmer John what their line number is.

Continuing with the list:
4th : 1 2 4 5 3
5th : 1 2 5 3 4

Farmer John can see the answer here is 5

Farmer John and the cows would like your help to play their game.
They have K (1 <= K <= 10,000) queries that they need help with.
Query i has two parts: C_i will be the command, which is either 'P'
or 'Q'.

If C_i is 'P', then the second part of the query will be one integer
A_i (1 <= A_i <= N!), which is a line number. This is Farmer John
challenging the cows to line up in the correct cow line.

If C_i is 'Q', then the second part of the query will be N distinct 
integers B_ij (1 <= B_ij <= N). This will denote a cow line. These are the 
cows challenging Farmer John to find their line number.

PROBLEM NAME: line

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..2*K+1: Line 2*i and 2*i+1 will contain a single query.

Line 2*i will contain just one character: 'Q' if the cows are lining
up and asking Farmer John for their line number or 'P' if Farmer
John gives the cows a line number.

If the line 2*i is 'Q', then line 2*i+1 will contain N space-separated
integers B_ij which represent the cow line. If the line 2*i is 'P',
then line 2*i+1 will contain a single integer A_i which is the line
number to solve for.

SAMPLE INPUT:

5 2
P
3
Q
1 2 5 3 4

OUTPUT FORMAT:

* Lines 1..K: Line i will contain the answer to query i.

If line 2*i of the input was 'Q', then this line will contain a
single integer, which is the line number of the cow line in line
2*i+1.

If line 2*i of the input was 'P', then this line will contain N
space separated integers giving the cow line of the number in line
2*i+1.

SAMPLE OUTPUT:

1 2 4 3 5
5
*/

#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<unsigned long long> comb;
void solveq() {
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    vector<bool> used(n, false);
    unsigned long long ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int loc = 0;
        for (int j = 0 ; j < n ; j++) {
            if (!used[j]) {
                if (v[i] == j+1) {
                    break;
                }
                loc++;
            }
        }
        //cout << v[i] << " is " << loc << endl;
        
        ans += comb[n-1-i] * loc;
        used[v[i]-1] = true;
    }
    cout << ans+1 << endl;
}
void solvep() {
    unsigned long long p;
    vector<bool> used(n, false);
    cin >> p;
    p--;
    for (int i = n-1 ; i >= 0 ; i--) {
        int lookingfor = p / comb[i];
        //cout << p << " " << comb[i] << " - " << lookingfor << endl;
        for (int j = 0 ; j < n ; j++) {
            //cout << j << " " <<  lookingfor << " " << comb[i] << " " << used[j] << endl;
            if (!used[j]) {
                if (lookingfor == 0) {
                    cout << j+1 << " ";
                    used[j] = true;
                    //cout << endl;
                    break;
                }
                lookingfor--;
            }
        }
        //cout << " - ";
        p %= comb[i];
    }
    cout << endl;
}
int main() {
    cin >> n >> k;
    comb.resize(n+1, 1);
    for (unsigned long long i = 1 ; i < n ; i++) {
        comb[i] = comb[i-1] * i;
    }

    for (int i = 0 ; i < k ; i++) {
        char c;
        cin >> c;
        if (c == 'Q') {
            solveq();
        } else {
            solvep();
        }
    }
    
}