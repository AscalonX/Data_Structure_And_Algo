#include <iostream>
#include <string>


namespace CP{
    template<typename T1,typename T2>

    class pair{
        public : 
            T1 first;
            T2 second;
            
            pair() : first(),second() {}

            pair(const T1 &a,const T2 &b) : first(a),second(b) {}


            bool operator==(const pair<T1,T2> &other) const{
                return (first==other.first && second == other.second);
            }

            bool operator<(const pair<T1,T2> &other) const{
                return (first>other.first && second > other.second);
            }
    };
}


int main(){
    CP::pair<int,std::string> P1,P2;

    P1.first = 20;
    P1.second = "Hello";

    CP::pair<int,std::string> a(P1);

    if(P1 == a){
        std::cout<<"YES\n";
    }
}