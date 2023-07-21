#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;

int main(){
    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                  "Sed laoreet sem leo,    in posuere orci elementum.";
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        if (text.substr(0, pos).size() > 0) {
            words.push_back(text.substr(0, pos));
        }
        text.erase(0, pos + space_delimiter.length());
    }
    for (const auto &str : words) {
        cout << str << endl;
    }

    return EXIT_SUCCESS;
}