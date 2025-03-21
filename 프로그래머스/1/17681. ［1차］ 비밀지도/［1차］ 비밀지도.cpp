#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <cmath>

using namespace std;

void change1(unsigned int n, int num, string& s){
    if(num == 1){
        s.push_back('#');  
        return;
    }
         
    else if(num == 0){ 
        s.push_back(' '); 
        return;
    }
        
    else{
        if(num%2 == 1){
            s.push_back('#');
            change1(2*n,(num-1)/2,s);
        }            
        else{
            s.push_back(' '); 
            change1(2*n,num/2,s);
        }
            
    }
    
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string a;
    vector<int> arr3;
    for(int i=0;i<n;i++){
        change1(1,(arr1[i] | arr2[i]),a);
        while(size(a) < n )
            a.push_back(' ');
        reverse(a.begin(),a.end());
        cout<< (arr1[i] | arr2[i]) <<" " << a<<endl;
        
        answer.push_back(a);
        
        a.clear();
        //cout<<(arr1[i] | arr2[i])<<endl;
    }
    
    return answer;
}