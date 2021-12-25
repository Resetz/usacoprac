#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    int n = 10; //number of bots to be generated
    int m;
    int k = 2;
    int min_bot_power = 10;
    int max_bot_power = 100;

    std::ofstream outfile;
    outfile.open("combat.txt", std::ios::out);
    std::random_device dev;
    std::mt19937 rng(dev()); //rng device read here: https://www.cplusplus.com/reference/random/mt19937/
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,25);
    m = 5;
    outfile << n << " " << m << " " << k << std::endl;
    for (int i = 0 ; i < n ; i++) {
        int f, d;
        f = dist6(rng);
        d = dist6(rng)/2+1;
        outfile << f << " " << f+d << std::endl;
    }

    for (int i = 0 ; i < m ; i++) {
        outfile << dist6(rng) << std::endl;
    }

    outfile.close();
}