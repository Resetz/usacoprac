    /*
    Cow IDs
    =======

    Being a secret computer geek, Farmer John labels all of his cows with
    binary numbers.  However, he is a bit superstitious, and only labels 
    cows with binary numbers that have exactly K "1" bits (1 <= K <= 10).  
    The leading bit of each label is always a "1" bit, of course.  FJ 
    assigns labels in increasing numeric order, starting from the smallest 
    possible valid label -- a K-bit number consisting of all "1" bits.
    Unfortunately, he loses track of his labeling and needs your help: 
    please determine the Nth label he should assign (1 <= N <= 10^7).

    PROBLEM NAME: cowids

    INPUT FORMAT:

    * Line 1: Two space-separated integers, N and K.

    SAMPLE INPUT:

    7 3

    INPUT DETAILS:

    Among all binary numbers containing exactly 3 "1" bits, FJ wants 
    to output the 7th in increasing sorted order.

    OUTPUT FORMAT:

    * Line 1: Only a single line; the binary number that is Nth in 
    increasing order among the numbers with K "1" bits.

    SAMPLE OUTPUT:

    */


    #include <iostream>
    #include <vector>

    using namespace std;

    vector<int> ans;
    int n, k;
    unsigned long long comb(int a, int b) {
        if (b == 0) return 1;
        unsigned long long ans = 1;
        for (int i = 0; i < b ; i++) {
            ans *= a-i;
        } 
        for (int i = 1; i <= b ; i++) {
            ans /= i;
        }
        return ans;
    }


    int main() {
        cin >> n >> k;
        unsigned long long prev = 0;
        unsigned long long curnum = 0;
        unsigned long long curi = k-1;
        while (n > curnum) {
            prev = curnum;
            curnum += comb(curi, k-1);
            curi++;
        }
        //cout << curnum << " " << curi << endl;
        n -= prev;
        vector<char> ans(1, '1');
        int curpos = curi-1; int remainingones = k-1;
        while (curpos > 0) {
            //choose if current is 0;
            //cout << n << " " << comb(curpos-1, remainingones) << "(" << curpos-1 << ", " << remainingones << ")" << endl;
            if (n <= comb(curpos-1, remainingones)) {
                ans.push_back('0');
                curpos--;
            } else {
                ans.push_back('1');
                n -= comb(curpos-1, remainingones);
                curpos--;
                remainingones--;
            }
        }
        for (int i = 0 ; i < ans.size() ; i++) {
            cout << ans[i];
        }
        cout << endl;
        

    }