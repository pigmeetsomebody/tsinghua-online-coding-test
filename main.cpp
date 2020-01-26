//
//  main.cpp
//  bitset
//
//  Created by Apple on 2020/1/26.
//  Copyright © 2020 Apple. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int n;
vector<long long> weights;
int count_ones(long long a,long long b){
    long long c = a&b;
    bitset<64> bt(c);
    return bt.count();
}
int cal(int m){
    if(m==1) return count_ones(weights[0], weights[1]);
    else return count_ones(weights[0], weights[m])+cal(m-1)*count_ones(weights[m], weights[m-1])%991127;
}
int main(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        weights.push_back(temp);
    }
    cout<<(cal(n-1)%991127)<<endl;
    
}
