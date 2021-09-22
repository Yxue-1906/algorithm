#include<iostream>
#include<algorithm>
#include<cstring>

int hash[10005][10005];

int main(){
    int a,b,c;
    int tmpA,tmpB;
    bool getC=false,ans=true;
    for(;std::cin>>a>>b;getC=false,ans=true){
        hash[std::min(a,b)][std::max(a,b)]++;
        for(int i=0;i<5;++i){
            std::cin>>tmpA>>tmpB;
            if(ans){
                if(!getC){
                    if(tmpA!=a&&tmpA!=b)c=tmpA,getC=true;
                }else{
                    if(tmpA!=a&&tmpA!=b&&tmpA!=c){
                        ans=false;
                    }
                }
                if(!getC){
                    if(tmpB!=a&&tmpB!=b)c=tmpB,getC=true;
                }else{
                    if(tmpB!=a&&tmpB!=b&&tmpB!=c){
                        ans=false;
                    }
                }
                hash[std::min(tmpA,tmpB)][std::max(tmpA,tmpB)]++;
            }
        }
        if(!getC)c=a;
        if(ans){
            hash[std::min(a,b)][std::max(a,b)]-=2;
            hash[std::min(a,c)][std::max(a,c)]-=2;
            hash[std::min(b,c)][std::max(b,c)]-=2;
            ans=(!hash[std::min(a,b)][std::max(a,b)]&&
                 !hash[std::min(a,c)][std::max(a,c)]&&
                 !hash[std::min(b,c)][std::max(b,c)]);
#ifdef DEBUG
            std::cout<<hash[std::min(a,b)][std::max(a,b)]<<std::endl
                     <<hash[std::min(a,c)][std::max(a,c)]<<std::endl
                     <<hash[std::min(b,c)][std::max(b,c)]<<std::endl;
#endif
        }
        if(ans)std::cout<<"POSSIBLE"<<std::endl;
        else {
            std::cout<<"IMPOSSIBLE"<<std::endl;
            hash[std::min(a,b)][std::max(a,b)]=0;
            hash[std::min(a,c)][std::max(a,c)]=0;
            hash[std::min(b,c)][std::max(b,c)]=0;
        }
    }
    return 0;
}

