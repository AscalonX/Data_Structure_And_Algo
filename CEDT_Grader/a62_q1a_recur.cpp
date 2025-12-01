#include <iostream>
#include <vector>

using namespace std;

// int i = 0;
// int j = 0;

int i = 0;
vector<int> tmp;
vector<vector<int> > ans;
void recur(int a,int b){
    if(a == 0){
        i+=1;
        tmp.push_back(b);
        if(i % 4 == 0){
            ans.push_back(tmp);
            tmp.clear();
        }
        return ;
    }
    recur(a-1,b);
    recur(a-1,b-1);
    recur(a-1,b+1);
    recur(a-1,b);
}
int main(){

    int m,n;
    cin>>m>>n;

    recur(m,n);

    cout<<"Size : "<<ans.size();
}