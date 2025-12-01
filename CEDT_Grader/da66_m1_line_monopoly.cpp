#include <iostream>
#include <set>

using namespace std;

class range{
    public:
        int start;
        int end;

        range(int start,int end){
            this->start = start;
            this->end   = end;
        }
};

bool sort_by_start(range &A,range &B){
    if(A.start != B.start){
        return A.start < B.start;
    }
    else{
        return A.end < B.end;
    }
}
        
int main(){

    set<range,sort_by_start()> s;
    int n;
    cin>>n;
    int tmp,a,b;
    int cnt = 0;
    while (n--)
    {
        cin>>tmp;
        if(tmp == 1){
            cin>>a>>b;
            cnt+=1;
        }
        else{
            cout<<cnt;
        }
    }
    
}