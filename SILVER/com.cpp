#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        return a.first > b.first;
    }
};

int main() 
{

  priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
  pq.push({0, 1});
  pq.push({1, 2});
  pq.push({2, 3});
  pq.push({3, 4});
  cout << pq.top().first << endl;
}