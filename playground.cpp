#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> n = {0,1,2,3,4,5};

    vector<int> b;
    b.insert(b.begin(),n.begin()+2,n.end());

    for(int x : b){
        cout<<x<<" ";
    }
    return 0;
}