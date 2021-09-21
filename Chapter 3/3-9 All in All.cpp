#include<iostream>

int main(){
    std::string s,t;
    for(;std::cin>>s>>t;)
    {
        auto ites=s.begin(), itet=t.begin();
        for(;ites!=s.end()&&itet!=t.end();)
        {
            if(*ites==*itet)++ites;
            if(ites==s.end()){
                std::cout<<"Yes"<<std::endl;
                break;
            }
            if(++itet==t.end())
            {
                std::cout<<"No"<<std::endl;
            }
        }
        s.clear(),t.clear();
    }
    return 0;
}
