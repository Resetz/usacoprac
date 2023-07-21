#include <iostream>
#include <vector>


using namespace std;

int main() {
    for (int i = 'A' ; i <= 'Z' ; i++) {
        int temp = i;
        cout << (char) i << " ";
        char c[8];
        for (int j = 0 ; j < 8 ; j++) {
            c[j] = (temp & 1);
            temp = temp >> 1;
        }
        for (int j = 7 ; j >= 0 ; j--) {
            cout << (char)(c[j] + '0');
            if (j == 4) cout << " ";
        }
        cout << endl;

        cout << (char) (i | 32) << " ";
        temp = i | 32;
        for (int j = 0 ; j < 8 ; j++) {
            c[j] = (temp & 1);
            temp = temp >> 1;
        }
        for (int j = 7 ; j >= 0 ; j--) {
            cout << (char) (c[j] + '0');
            if (j == 4) cout << " ";
        }
        cout << endl;
        cout << endl;
    }
}