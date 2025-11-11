#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    public :
        int grade;
        int grade2;
        string name;
};


bool cmp(const student &a,const student &b){
    if(a.grade == b.grade){
        return a.grade2 > b.grade2;
    }
    else{
        return a.grade > b.grade;
    }

}
int main(){

    vector<student> s;

    sort(s.begin(),s.end(),cmp);
}