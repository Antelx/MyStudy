#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> res;
    void fun(string a, string b, int c){
        cout<<a<<"\t"<<b<<"\t"<<c<<endl;
        if(c>4){return;}
        if(b.size()>12-3*c){return;}
        if(b==""){
            if(c==4){
                cout<<a<<endl;
                res.push_back(a.substr(0,a.size()-1));
            }
            return;
        }
        if(b.size()<11-c*3)
        fun(a+b.substr(0,1)+".",b.substr(1,b.size()), c+1);
        if(b.size()>1 && b[0] != '0' && b.size()<12-c*3)
        {fun(a+b.substr(0,2)+".",b.substr(2,b.size()), c+1);}
        if(b.size()>2 && b[0] != '0' && b.substr(0,3)<="255")
        {fun(a+b.substr(0,3)+".",b.substr(3,b.size()), c+1);}
    }
    vector<string>restoreIpAddresses(string s) {
        fun("",s,0);
        return res;
    }
};

int main(){
    Solution sol;
    string s = "25525511135";
    // cout<<s.substr(0,3)<<endl;
    sol.restoreIpAddresses(s);

    getchar();
    return 0;
}