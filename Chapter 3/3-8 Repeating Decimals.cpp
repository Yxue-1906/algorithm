#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<int,int>nums;
    while(true)
    {
        int a,b;
        if(!(std::cin>>a>>b))
            return 0;
        std::string ans;
        ans+=std::to_string(a/b)+".";
        std::cout<<a<<'/'<<b<<" = ";
        a%=b;
        a*=10;

        while(nums.end()==nums.find(a))
        {
            nums.emplace(a,ans.size());
            ans+=std::to_string(a/b);
            a%=b;
            a*=10;
        }
        auto tmp=nums.find(a);
        int count=0;
        int indexOfDecimal=0;
        for(int i=0;i<ans.length();++i){
            if(i-indexOfDecimal>50){
                std::cout<<"...";
                break;
            }
            if(i==tmp->second){
                std::cout<<'(';
                count=ans.length()-i;
            }
            if(ans[i]=='.')
            {
                indexOfDecimal=i;
            }
            std::cout<<ans[i];
        }
        std::cout<<')'<<std::endl;
        std::cout<<"   "<<count<<" = number of digits in repeating cycle"<<std::endl;
        std::cout<<std::endl;
        nums.clear();
    }
    return 0;
}
