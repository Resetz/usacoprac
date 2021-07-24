/******************************************************************************
 * Assignment: N/A
 * Directory: test/
 * Program Name: driver.cpp
 * Author: Vincent Tran
 * Date: 6/27/2021
 ******************************************************************************
 * Purpose: A test programs that tests the limits of input streams.
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    /* Varaible Declaration */
    
    // For example one.
    double d;
    double i;

    // For example two
    int n;
    int m;
    char c;
    char c1;


    cout << "Input \"1.2.3\": ";
    cin >> d >> i;
    cout << "d = " << d << " i = " << i << endl;
    cout << "cin reads 1.2 for a double but reaches . and can't read it and \
           \ntherefore sets d to 1.2. After this, .3 is read and sets the \
           \ndouble i to it, therefore, making it .3 or 0.3" << endl;

    cout << "Input \"1 2 3, 4 5 6: ";
    cin.ignore(100, ',');
    cin >> n >> m;
    cout << "After using cin for n and m: n = " << n << " m = " << m << endl;
    cin.ignore(5);
    cin.get(                              c);
    cin.get(c1);
    cout << "The next two characters are (after another ignore): " << c << ", and" <<  c1;
}