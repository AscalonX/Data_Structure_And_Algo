#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    set<pair<int,int> > s;
    while(n--){
        int y,m;
        cin>>y>>m;
        s.insert(make_pair(y,m));
    }
    while(k--){
        int y,m;
        cin>>y>>m;
        auto sth = make_pair(y,m);
        if(s.find(make_pair(y,m)) != s.end()){
            cout<<"0 0 ";
        }
        else if(sth < *s.begin()){
            cout<<"-1 -1 ";
        }
        else{
            auto it = s.lower_bound(make_pair(y,m));
            it--;
            cout<<it->first<<" "<<it->second<<" ";
        }
    }
}