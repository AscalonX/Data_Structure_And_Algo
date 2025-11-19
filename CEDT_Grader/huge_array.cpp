#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class segment{
    public:
        int value;
        int size;
        int start_index;
        int curr_index;

        segment(int value,int size){
            this->value = value;
            this->size = size;
        }

        void set_start_index(int index){
            this->start_index = index;
        }
        
};

bool cmp(segment &a, segment &b){
    return a.value < b.value;
}

bool cmp2(segment &a, int b){
    return a.start_index < b;
}
int main(){
    vector<segment> vec;

    int n,q;
    cin>>n>>q;
    while(n--){
        int num,amount;
        cin>>num>>amount;
        segment tmp(num,amount);
        vec.push_back(tmp);
    }


    sort(vec.begin(),vec.end(),cmp);

    // for(auto &it : vec){
    //     cout<<it.value<<" - "<<it.size<<"\n";
    // }

    int start_index = 0;

    segment tmp(1000000,1);
    vec.push_back(tmp);

    for(int i =0;i<vec.size();i++){
        vec[i].start_index = start_index;
        start_index += vec[i].size;
    }

    // cout<<"\n===========\n";

    // for(auto &it : vec){
    //     cout<<it.value<<" - "<<it.size<<" - start at : "<<it.start_index<<"\n";
    // }

    while(q--){
        int to_find;
        cin>>to_find;
        int x = distance(vec.begin(),lower_bound(vec.begin(),vec.end(),to_find,cmp2));

        // cout<<"Found at. : "<<x<<" the number is "<<vec[x-1].value<<"\n";
        cout<<vec[x-1].value<<"\n";
    }
}