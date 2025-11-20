#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;


list<pair<int,int> > get_input(vector<int> &x,int start,int end){

    list<pair<int,int> > l;

    int curr = x[start];
    int count = 0;


    int tmp;
    for(int i =start;i<=end;i++){
        // cin>>tmp;

        if(x[i] != curr || i == end){
            l.push_back(make_pair(curr,count));

            curr = x[i];
            count = 1;
        }
        else{
            count += 1;
        }
    }
    return l;
}
int main(){
    int n,k,v;
    cin>>n>>k>>v;

    list<pair<int,int > > first,second;

    vector<int> vec;
    for(int i =0;i<n;i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }

    first = get_input(vec,0,k);
    second = get_input(vec,k,n);


    // for(auto &it : first){
    //     cout<<it.first<<" "<<it.second<<"\n";
    // }
    // cout<<"====\n";
    // for(auto &it : second){
    //     cout<<it.first<<" "<<it.second<<"\n";
    // }
    // cout<<"====\n";

    cin>>k>>v;

    if(first.back().first == v && v == second.front().first){
        if(first.back().second + second.front().second >= 2){
            first.pop_back();
            second.pop_front();
        }
    }
    else if(first.back().first == v){
        if(first.back().second >= 2){
            first.pop_back();
        }
        first.back().second += 1;

    }
    // cout<<seo.back().first<<" "<<first.back().second<<"\n";
    else if(second.front().first == v){
        if(second.front().second >= 2){
            second.pop_front();
        }
        second.front().second += 1;
    }
    else{
        first.push_back(make_pair(v,1));
    }
    // cout<<"OLLOLOL\n";
    while(true && !first.empty() && !second.empty()){
        if(first.back().first == second.front().first){
            if(first.back().second + second.front().second >= 3){
                first.pop_back();
                second.pop_front();
            }
        }
        else{
            break;
        }
    }

    for(auto &it : first){
        for(int i =0;i<it.second;i++){
            cout<<it.first<<" ";
        }
    }

    for(auto &it : second){
        for(int i =0;i<it.second;i++){
            cout<<it.first<<" ";
        }
    }


    return 0;
}