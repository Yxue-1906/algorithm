#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>

void calc(std::string s1,std::string s2){
    if(s1.size()<s2.size())std::swap(s1,s2);
    const int max=std::max(s1.size(),s2.size());
    int n1[2*max]={0},n2[2*max]={0},n3[2*max]={0};

    for(int i=0;i<s1.size();++i){
        if(s1[i]=='1')n1[i+s2.size()]=1;
        else n1[i+s2.size()]=2;
    }
    for(int i=0;i<s2.size();++i){
        if(s2[i]=='1')n2[i]=1;
        else n2[i]=2;
    }
    for(int i=0;i<s2.size();++i){
        if(s2[s2.size()-1-i]=='1')n3[i]=1;
        else n3[i]=2;
    }
    
    int i=-s2.size(),ans=s1.size()+s2.size()+1;
    for(;i<max;++i){
        int j=0;
#ifdef DEBUG
        if(i<0)for(int k=i;k!=0;++k)std::cout<<0;
        std::cout<<s1;
        if(i>0)for(int k=0;k<i;++k)std::cout<<0;
        std::cout<<std::endl;
        for(int k=0;k<i;++k){
            std::cout<<0;
        }
        std::cout<<s2<<std::endl;
        for(int k=0;k<i;++k){
            std::cout<<0;
        }
#endif
        while(j<s2.size()){
#ifdef DEBUG
            std::cout<<n1[i+j+s2.size()]+n2[j];
#endif
            if(n1[i+j+s2.size()]+n2[j]==4)break;
            j++;
        }
        int now=i<0?-i+s1.size():std::max(max,(int)(i+s2.size()));
        if(now==ans)break;
        if(j==s2.size()&&now<ans)ans=now;
#ifdef DEBUG
        std::cout<<std::endl<<ans;
        std::cout<<std::endl<<std::endl;
#endif
    }

    for(i=-s2.size();i<max;++i){
        int j=0;
#ifdef DEBUG
        if(i<0)for(int k=i;k!=0;++k)std::cout<<0;
        std::cout<<s1;
        if(i>0)for(int k=0;k<i;++k)std::cout<<0;
        std::cout<<std::endl;
        for(int k=0;k<i;++k){
            std::cout<<0;
        }
        for(auto ite=s2.rbegin();ite!=s2.rend();++ite){
            std::cout<<*ite;
        }
        std::cout<<std::endl;
        for(int k=0;k<i;++k){
            std::cout<<0;
        }
#endif
        while(j<s2.size()){
#ifdef DEBUG
            std::cout<<n1[i+j+s2.size()]+n3[j];
#endif
            if(n1[i+j+s2.size()]+n3[j]==4)break;
            j++;
        }
        int now=i<0?-i+s1.size():std::max(max,(int)(i+s2.size()));
        if(now==ans)break;
        if(j==s2.size()&&now<ans)ans=now;
#ifdef DEBUG
        std::cout<<std::endl<<ans;
        std::cout<<std::endl<<std::endl;
#endif
    }

    std::cout<<ans<<std::endl;
}
int main(){
    std::string s1,s2;
    for(;std::cin>>s1>>s2;){
        calc(s1,s2);
    }
    return 0;
}
