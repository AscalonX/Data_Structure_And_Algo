#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

bool cmp(const std::pair<std::string,int> &a,const std::pair<std::string,int> &b){
    return a.second > b.second;
}

int main(){
    int n,k;
    std::cin>>n>>k;

    std::map<std::string,int> mp;
    for(int i =0;i<n;i++){
        std::string tmp;
        std::cin>>tmp;
        mp[tmp] += 1;
    }


    std::vector<std::pair<std::string,int> > vec;

    for(auto &it : mp){
        // std::cout<<it.first<<" | "<<it.second<<"\n";
        vec.push_back(it);
    }

    // for(auto &it : vec){
    //     std::cout<<it.first<<" | "<<it.second<<"\n";
    // }

    std::sort(vec.begin(),vec.end(),cmp);
    // std::cout<<"--------\n\n\n";
    // for(auto &it : vec){
    //     std::cout<<it.first<<" | "<<it.second<<"\n";
    // }

    size_t that_last_position = k-1;
    // std::cout<<vec[that_last_position].second;

    if(that_last_position >= vec.size()){
        that_last_position = vec.size()-1;
    }
    if(vec[that_last_position].second > 1){
        std::cout<<vec[that_last_position].second<<"\n";
    }
    else{
        while(vec[that_last_position].second < 1){
            that_last_position -= 1;
        }
        std::cout<<vec[that_last_position].second<<"\n";
    }
}