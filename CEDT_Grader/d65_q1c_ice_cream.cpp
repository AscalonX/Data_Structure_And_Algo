#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    int n,m,start;

    vector<ll> p(100030);

    cin>>n>>m>>start;

    p[1] = start;
    for(int i =0;i<n;i++){
        int a,s;
        cin>>a>>s;

        p[a+1] = s;
    }

    for(int i = 1;i<100030;i++){
        if(p[i] == 0){
            p[i] = p[i-1];
        }
    }

    for(int i = 1;i<100030;i++){
        p[i] += p[i-1];
    }

    // for(int i =1;i<15;i++){
    //     cout<<p[i]<<" ";
    // }

    for(int i = 0;i<m;i++){
        int icecream_price,scam;
        cin>>icecream_price>>scam;
        

        if(p[scam+1] < icecream_price){
            int x = distance(p.begin(),lower_bound(p.begin(),p.end(),icecream_price+p[scam+1]));
            cout<<x-1<<" ";
        }
        else{
            int b = distance(p.begin(),lower_bound(p.begin(),p.end(),icecream_price));
            cout<<b-1<<" ";
        }

        
    }

}