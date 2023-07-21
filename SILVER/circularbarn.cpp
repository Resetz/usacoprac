#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

bool marked[100];
int main() {

    int N; cin >> N; // N < 1000 : N < 1000000
    vector<long long> A(N);

    
    int c = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long ans = -1;
    for (int i = 0 ; i < N ; i++) {
        rotate(A.begin(), A.begin() + 1, A.end());
        queue<int> last;
        long long total = 0;

        for (int k = 0 ; k < N ; k++) {
            if (A[k] >= 1) {
                if (last.size() == 0) {
                    for (int j = 0 ; j < A[k]-1 ; j++)
                        last.push(k);
                } else {
                    total += (k - last.front()) * (k - last.front());
                    last.pop();
                    for (int j = 0 ; j < A[k] ; j++)
                        last.push(k);
                }
            } else {
                if (last.size() != 0) {
                    total += (k - last.front()) * (k - last.front());
                    last.pop();
                }
            }
        }
        if (last.size() == 0) {
            ans = ans == -1 ? total : min(ans, total);
        }
    }
    cout << ans << endl;
}