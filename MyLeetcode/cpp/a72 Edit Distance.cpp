#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(!(word1.size()&&word2.size())){return(word1.size() + word2.size());}
        cout<<word1.size()<<endl;
        cout<<word2.size()<<endl;
        int r[word1.size()][word2.size()];
        for(int i=0;i<word1.size();i++){
            for(int j = 1;j<word2.size();j++){
               r[i][j] = 0;         
            }
        }
        bool con = word1[0] == word2[0];
        r[0][0] = 1 - con;
        for(int i=1; i<word1.size();i++){
            if(word2[0] == word1[i]){con = true;}
            r[i][0] = i + 1 - con;
        }

        con = word1[0] == word2[0];
        for(int j=1; j<word2.size();j++){
            if(word1[0] == word2[j]){con = true;}
            r[0][j] = j + 1 - con;
        }

        for(int i=1;i<word1.size();i++){
            for(int j = 1;j<word2.size();j++){
                if(word1[i]==word2[j]){r[i][j] = r[i-1][j-1];}
                else{
                    r[i][j] = 1 + min(min(r[i-1][j], r[i][j-1]), r[i-1][j-1]);
                }
            }
        }        

        return r[word1.size()-1][word2.size()-1];


    }
};

int main(){
    string word1 = "ros", word2 = "horse";
    Solution sol;
    sol.minDistance(word1, word2);


    getchar();
    return 0;
}