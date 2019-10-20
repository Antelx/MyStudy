#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    unsigned int a = 1;
    int b = 4294967295;
    cout << a - 2 << b <<endl;
    if(a - 2 == b){
        cout << "y" << endl;
    } 
    else
    {
        cout << "n" << endl;
    }
    
    getchar();
    return 0;
}
