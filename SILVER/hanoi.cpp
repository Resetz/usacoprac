#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


vector<int> towers[3];

void print_hanoi(int indent) {
    for (int j = 0 ; j < indent ; j++) {
        cout << setw(3) << " ";
    }
    cout << "________________________" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0 ; j < indent ; j++) {
            cout << setw(3) << " ";
        }
        cout << "> ";
        for (int j = 0 ; j < towers[i].size() ; j++) {
            cout << towers[i][j] << " ";
        }
        cout << endl;
    }
}

void move_hanoi(int from, int to, int it) {
    if (towers[from].size() != 0) {
        print_hanoi(it);
        int moving = towers[from][towers[from].size()-1];
        towers[to].push_back(moving);
        towers[from].erase(towers[from].end()-1);
    }
}

void hanoi(int disks, int from, int to, int temp, int it) {
    int moving;
    
    if (disks == 1) {
        move_hanoi(from, to, it+1);
    } else {
        hanoi(disks-1, from, temp, to, it+1);
        move_hanoi(from, to, it+1);
        hanoi(disks-1, temp, to, from, it+1);
    }
}

int main() {
    for (int i = 4 ; i > 0 ; i--) {
        towers[0].push_back(i);
    } 
    print_hanoi(0);
    hanoi(4, 0, 2, 1, 0);
    print_hanoi(0);
}