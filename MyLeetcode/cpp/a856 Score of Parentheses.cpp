#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include <stack>
// # S = "((())())"
// S = "(()(()))"
// s = []
// for i in S:
//     if i == ")":
//         if s[-1] == "(":
//             s[-1] = 1
//         else:
//             s[-1] *= 2
//             s.pop(-2)
//         if len(s) > 1:
//             if str(s[-2]).isnumeric():
//                 s[-2] += s[-1]
//                 s.pop()
//     else:
//         s.append("(")
// s
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> r;
        for(int i=0; i<S.size();i++){
            cout<<S[i]<<endl;
            if(S[i] == '('){
                r.push(0);   
            }
            else{
                if(r.top()==0){
                    r.pop();
                    r.push(1);
                }
                else{
                    int top = r.top();
                    r.pop();
                    r.pop();
                    r.push(top*2);
                }
                if(r.size()>1){
                    int top1 = r.top();
                    r.pop();
                    if(r.top()>0){
                        int top2 = r.top();
                        r.pop();
                        r.push(top1 + top2);
                    }
                    else{
                        r.push(top1);
                    }

                }
                
            }
            cout<<r.top()<<endl;
        
        }
        return r.top();
    }
           
};


int main(){
    // string S = "((())())";
    string S ="(()(()))";


    Solution sol;
    cout<< sol.scoreOfParentheses(S)<<endl;

    getchar();
    return 0;
}