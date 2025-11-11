#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

int main(){
    std::queue<int> q;
    std::map<int,int> mp;

    int target = 30;

    q.push(1);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        if(v == target){
            std::cout<<"Found it !\n";
            break;
        }

        int v2 = v/2;
        int v3 = v*3;

        if(mp[v2] == 0){
            q.push(v2);
            mp[v2] = v;
        }
        if(mp[v3] == 0){
            q.push(v3);
            mp[v3] = v;
        }
    }


    // show solution

    int start = target;
    while(true){

        if(target == 1){
            break;
        }
        std::cout<<target<<" ";
        target = mp[target];
    }
    std::cout<<1<<" ";
}