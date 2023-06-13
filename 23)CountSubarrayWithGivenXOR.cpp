#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int> map;
    int ansXor=0;
    int ansCount=0;
    for(int i=0;i<arr.size();i++){
        ansXor=ansXor ^ arr[i];
        if(ansXor==x) ansCount++;
        
        int req=ansXor ^ x;
        if(map.find(req)!=map.end()) ansCount+=map[req];
   
        map[ansXor]++;
    }
    return ansCount;
    
}