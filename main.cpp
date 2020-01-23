//
//  main.cpp
//  training01
//
//  Created by Apple on 2020/1/23.
//  Copyright © 2020 Apple. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,num;
    scanf("%d %d\n",&n,&num);
    for(int i=0;i<n;i++){
        int m,l,circles;
        scanf("%d %d %d",&m,&l,&circles);
        vector<int> v;
        for(int j=0;j<m;j++){
            int vt;
            scanf("%d ",&vt);
            v.push_back(vt);
        }
        sort(v.begin(),v.end());
//        for(int j=0;j<v.size();j++){
//            printf("%d ",v[j]);
//        }
//        printf("\n");
//
        int max_v=v[v.size()-1];
        double time=(double)(l*circles)/max_v;
        int res=0;
        for(int i=m-1;i>0;--i){
            for(int j=i-1;j>=0;--j){
                int gap = v[i]-v[j];
                res+=(time*gap)/l;
            }
        }
        printf("%d\n",res);
    }
}
