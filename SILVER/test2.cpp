/* Operator Precedence */
/* [::] -> [()] -> [[]] -> [., ->] -> [++, --] -> [any cast] -> [deref. *, &] ->
          [*,/,%] -> [+,-] -> [>>, <<] -> [<, >, <=, >=] -> [==, !=] -> [=] */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#define divider "--------------------------------------------------------------------------------\n"

using namespace std;
/* Awkward but portable way to initialize variables */
size_t a{0};
size_t b{0};
size_t i{0};
size_t j{0};

size_t twod[10][10];

string s;
int main() {
    /****** Pre-initialization ******/
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            twod[i][j] = i*10+j;
        }
    }

    /****** Chapter 2 7/16/21 *****/
    /* You cannot assign variables using the {} operator, however */
    for (i = 0; i < 5; i++) {
        cout << i << endl;
    }

    /* size_t is a typedef that is specific for some systems */
    /* on this system, size_t is defined as a unsigned long long */

    cout << divider;
    cout << "Please enter two positive numbers: ";
    /* This is called cascaded stream extraction */
    cin >> a >> b;
    /* Note that it has no real benefit over using multiple stream
       extraction statments other than the fact that it looks cleaner. */
    
    cout << "Using cascaded stream extraction: " << a << ", " << b << endl;
    
    /* The single equal sign and the double equal sign are completely
       different. The single equal sign offers assignment while the 
       double equal sign offers comparison                           */
    /* Single equal sign */
    cout << divider;
    a = 0;
    b = 1;
    i = 1;

    /* Double equal sign */
    if (b == i) {
        cout << "b and i are equal" << endl;
    }

    /* A use of the curly brackets is to combine multiple statements 
       of code together so that it is possible for them to run in
       the same if/for/while statement. This is called a block of
       code or a compound statement. While they are mostly used for
       combining statements together, they can also be used for 
       declaring scopes.                                 */
    cout << divider;
    {
        size_t a{2};
        cout << "Scope a: " << a << endl;
        cout << "Global a: " << ::a << endl;
    }

    /* Every operator has both precedence and association:
       * Precedence:  The order in which the computer should
                      evaluate the expression compared to other
                      expressions.
       * Association: Which side of the operator the computer 
                      should evaluate first before executing the operator.
    */
    
    /* The "=" operator has right to left association and the lowest
       precdence.                                                     */
    /* Almost all other operators have left to right association */
    cout << divider;
    cout << "Accessing array value *twod[1]: " << *twod[1] << endl; /* the [] evaluates first, then the deref. */
    
    /* Trying to get data into as string works differently depending 
       on the purpose of the program.                                */
    /* Excluding white space */
    cout << divider;
    cout << "Enter a single word: ";
    cin >> s;
    cout << "Word entered = " << s << endl;
    
    cout << "Enter a sentence with spaces: ";
    /* Ignore the previous \n */
    cin.ignore(1000, '\n');
    getline(cin, s); /* This excludes '\n' */
    cout << "Sentence entered = " << s << endl;

    /****** Chapter 3 7/16/21 ******/
    /* All integral and floating point types are what are called
       fundamental types and don't have any member functions    */
    

}