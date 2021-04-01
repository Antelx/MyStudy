#include <iostream>
#include <vector>
#include <unordered_map>
#include<stack>
#include <string>
#include<algorithm>
#include<math.h>
#include "stringToIntegerVector.hpp"
using namespace std;
// 1268. Search Suggestions System
// Given an array of strings products and a string searchWord. 
// We want to design a system that suggests at most three product names from products after each character of searchWord 
// is typed. Suggested products should have common prefix with the searchWord.
// If there are more than three products with a common prefix return the three lexicographically minimums products.
// Return list of lists of the suggested products after each character of searchWord is typed. 
// Example 1:

// Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
// Output: [
// ["mobile","moneypot","monitor"],
// ["mobile","moneypot","monitor"],
// ["mouse","mousepad"],
// ["mouse","mousepad"],
// ["mouse","mousepad"]
// ]
// Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
// After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
// After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
// Example 2:

// Input: products = ["havana"], searchWord = "havana"
// Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
// Example 3:

// Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
// Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
// Example 4:

// Input: products = ["havana"], searchWord = "tatiana"
// Output: [[],[],[],[],[],[],[]]

// Constraints:
// 1 <= products.length <= 1000
// There are no repeated elements in products.
// 1 <= Σ products[i].length <= 2 * 10^4
// All characters of products[i] are lower-case English letters.
// 1 <= searchWord.length <= 1000
// All characters of searchWord are lower-case English letters


// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Search Suggestions System.
// Memory Usage: 28.2 MB, less than 72.07% of C++ online submissions for Search Suggestions System.
//别人的解法是用trie，惭愧,忘了什么是trie
class Solution {    
    int binary_search_l(vector<string>& products, string searchWord, int ind, int l, int r)
    {
        int mid;
        while (l <= r)
        
        {
            mid = (l+r)/2;
            if(ind < products[mid].size())
            {
                if(searchWord[ind] == products[mid][ind])
                {
                    //如果前一个也是的话就继续
                    if(mid-1>=l && ind < products[mid-1].size() && searchWord[ind] == products[mid-1][ind])
                    {
                        r = mid-1;
                    }
                    else
                    {
                        return mid;
                    }                    
                }
                else if(searchWord[ind] < products[mid][ind])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else //感觉只会在mid是最左边的时候出现，因为这已经匹配全了
            {
                l = mid + 1;
            }
            
        }
        return -1;        
    }
    int binary_search_r(vector<string>& products, string searchWord, int ind, int l, int r)
    {
        int mid;
        while (l <= r)
        {
            mid = (l+r)/2;

            if(ind < products[mid].size())
            {
                if(searchWord[ind] == products[mid][ind])
                {
                    //如果后一个也是的话就继续
                    if(mid+1<=r && ind < products[mid+1].size() && searchWord[ind] == products[mid+1][ind])
                    {
                        l = mid+1;
                    }
                    else
                    {
                        return mid;
                    }                    
                }
                else if(searchWord[ind] < products[mid][ind])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else //感觉只会在mid是最左边的时候出现，因为这已经匹配全了
            {
                l = mid + 1;
            }
            
        }
        return -1;        
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        // for(auto i:products)
        // {
        //     cout << i << endl;
        // }
        
        vector<vector<string>> res;
        int l = 0, r=products.size()-1;

        for(int i=0; i<searchWord.size();i++)
        {
            vector<string> new_res;
            res.push_back(new_res);    
        }
        for(int i=0; i<searchWord.size();i++)
        {   
            // cout<<searchWord[i] <<"\t" <<l <<"\t"<<r<<"\t"<<endl;
            if(l<0)
            break;
            l = binary_search_l(products,  searchWord,  i,  l, r);
            // cout << l <<"\t"<<r<<"\t"<<endl;
            if(l<0)
            break;
            r = binary_search_r(products,  searchWord,  i,  l, r);
            // cout << l <<"\t"<<r<<"\t"<<endl;

            for(int tmp=0; tmp<3; tmp++)
            {
                if(l+tmp<=r)
                {
                    res[i].push_back(products[l+tmp]);
                }
            } 
        }

        return res;        
    }
};

// Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
// Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
int main(){
    Solution sol;

    vector<string> products;
    products.push_back("bags");
    products.push_back("baggage");
    products.push_back("banner");
    products.push_back("box");
    products.push_back("cloths");
    string searchWord = "bags";

    vector<vector<string>> res = sol.suggestedProducts(products, searchWord);
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout <<j <<",";
        }
        cout<<endl;
    }  

    
    return 0;
}
