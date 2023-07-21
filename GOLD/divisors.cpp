#include <iostream>
#include <math.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
 
// Function to print the divisors
void printDivisors(int n)
{
    int i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0);
            //cout<<i<<" ";
    }
    if (i - (n / i) == 1) {
        i--;
    }
    for (; i >= 1; i--) {
        if (n % i == 0);
            //cout<<n / i<<" ";
    }
}
 
// Driver code
int main()
{
    cout << "The divisors of 100 are: \n";
    //auto start = high_resolution_clock::now();
    for (int i = 0 ; i < 100 ; i++)
    printDivisors(84);
    //auto stop = high_resolution_clock::now();

    //auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << " ms" << endl;
 
    return 0;
}
 