#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<string> answer(3);
    vector<string> guess(3);
    vector<char> visited;
    for(int i=0;i<3;i++){
        cin >> answer[i];
    }
    for(int i=0;i<3;i++){
        guess[i];
    }

    int yellow=0,green=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(answer[i][j]==guess[i][j]) green++;
            else if(find(visited.begin(),visited.end(),guess[i][j])==visited.end()){
                yellow+=count(answer.begin(),answer.end(),guess[i][j]);
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if (guess[i][j]==answer[i][ j]) yellow--;
                    }
                }
                visited.push_back(guess[i][j]);
            }
        }
    }
    cout << green << endl;
    cout << yellow << endl;
}