#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using std::string;

using namespace std;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{

    // cout<<"\n------\n";
    std::vector<std::vector<std::queue<int> > > vec;

    while (!a.empty())
    {
        vec.push_back(a.top());
        a.pop();
    }
    

    //vec is vector of vector
    for(auto &it : vec){
        //it is vector of queue
        //q is queue
        for(auto &q : it){
            for(int i =0;i<q.size();i++){
                int fr = q.front();
                // cout<<fr<<" ";
                if(fr == from){
                    // cout<<"Same ya : "<<fr<<" = "<<from<<"\n";
                    q.pop();
                    q.push(to);
                }
                else{
                    q.pop();
                    q.push(fr);
                }
            }
            // cout<<"\n";
        }
    }

    reverse(vec.begin(),vec.end());

    for(auto &it : vec){
        a.push(it);
    }

    // cout<<"\n------\n";
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    //map<string,pair>
    //pair<pq<int>,int>


    for(auto &it : a){
        std::pair<std::priority_queue<int>, int> &temp = it.second;

        std::priority_queue<int> &pq = temp.first;

        int &x = temp.second;
        if(x == from){
            x = to;
        }
        
        vector<int> pqvec;

        while(!pq.empty()){
            pqvec.push_back(pq.top());
            pq.pop();
        }

        std::replace(pqvec.begin(),pqvec.end(),from,to);

        for(int x : pqvec){
            pq.push(x);
        }
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    //set<pair<list<int>,map>
    //map<int,pair<int,string>
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> new_set;
    //it is now a pair
    for(auto it : a){
        std::pair<std::list<int>, std::map<int, std::pair<int, string>>> temp = it;
        std::list<int> &ls = temp.first;
        std::map<int, std::pair<int, string>> &mp = temp.second;

        replace(ls.begin(),ls.end(),from,to);

        std::map<int, std::pair<int, string>> new_mp;
        for(auto it_map : mp){
            if(it_map.second.first == from){
                it_map.second.first = to;
            }
            if(it_map.first == from){
                new_mp[to] = it_map.second;
            }
            else{
                new_mp[it_map.first] = it_map.second;
            }
        }
        new_set.insert(make_pair(ls,new_mp));
    }

    a = new_set;
}

#endif