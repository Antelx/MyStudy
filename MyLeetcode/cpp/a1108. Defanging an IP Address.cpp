#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        char res[address.size() + 7];
        int i = 0, j = 0;
        while(i < address.size() + 7){
            if(address[j] == '.'){
                res[i] = '[';
                res[i+1] = '.';
                res[i+2] = ']';
                i += 3;
            }
            else{
                res[i] = address[j];
                i ++;
            }
            j ++;
        }  
        return res;      
    }
};

int main()
{
    Solution sol;
    string address = "202.118.98.117";
    cout << sol.defangIPaddr(address) << endl;

    getchar();
    return 0;
}