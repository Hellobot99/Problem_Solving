#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int refresh(int cacheSize, string new_city, vector<string>& cache){
    
    auto a = find(cache.begin(),cache.end(),new_city);
   
    if(cacheSize == 0 )
        return 5;
    
    if(cache.size() < cacheSize && a == cache.end()){
        cache.push_back(new_city);
        return 5;
    }
    
    
    if(a == cache.end()){
        cache.erase(cache.begin());
        cache.push_back(new_city);
        return 5;
    }
    else{        
        cache.erase(a);
        cache.push_back(new_city);
        return 1;
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for(auto iter = cities.begin();iter!=cities.end();iter++){
        for(int i = 0;i<(*iter).size();i++){
            if((*iter)[i] > 'Z')
                (*iter)[i] = (*iter)[i] + 'A' - 'a';
        }
    }
    
    for(auto iter = cities.begin();iter!=cities.end();iter++)
        answer += refresh(cacheSize,*iter,cache);
    
        
    
    return answer;
}