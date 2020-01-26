//
//  main.cpp
//  onion
//
//  Created by Apple on 2020/1/26.
//  Copyright © 2020 Apple. All rights reserved.
//



#include<cstdlib>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

struct onion{int id;int x;int y;int d;int f;bool alive;};
struct fight_id{int id;int f;};
vector<onion> onions;
int n,m,k;
int t;

void init(){
    scanf("%d %d %d\n",&n,&m,&k);
    for(int i=0;i<k;i++){
        int x,y,d,f;
        scanf("%d %d %d %d\n",&x,&y,&d,&f);
        onion oi={i,x,y,d,f,1};
        onions.push_back(oi);
    }
    scanf("%d\n",&t);
}

void move(onion& oi){
    if(oi.d==0) --oi.x;
    if(oi.d==1) ++oi.x;
    if(oi.d==2) --oi.y;
    if(oi.d==3) ++oi.y;
    if(oi.x<1) {oi.x=1;oi.d=1;}
    if(oi.x>n) {oi.x=n;oi.d=0;}
    if(oi.y<1) {oi.y=1;oi.d=3;}
    if(oi.y>m) {oi.y=m;oi.d=2;}
}
void fight(map<int,vector<fight_id>> f_map){
   // iterator<<#class _Category#>, <#class _Tp#>>
    map<int,vector<fight_id>>::iterator it = f_map.begin();
    while(it!=f_map.end()){
        //fight_id fi=(*it);
        if((*it).second.size()>1){
            int max_f=0,max_id=-1;
            for(vector<fight_id>:: iterator i=(*it).second.begin();i!=(*it).second.end();++i){
                if((*i).f>max_f) {max_f=(*i).f;max_id=(*i).id;}
            }
            for(vector<fight_id>:: iterator i=(*it).second.begin();i!=(*it).second.end();++i){
                if((*i).id!=max_id) {onions[(*i).id].alive=false;}
            }
        }
        ++it;
    }
}
int main(){
    init();
    while(t-->0){
        map<int,vector<fight_id>> fight_map;
        for(vector<onion>::iterator it = onions.begin();it!=onions.end();++it){
            if((*it).alive){
                move((*it));
                int key = ((*it).x*1000)+(*it).y;
                fight_id m_fi={(*it).id,(*it).f};
                fight_map[key].push_back(m_fi);
            }
        }
        fight(fight_map);
    }
    for(vector<onion>::iterator it = onions.begin();it!=onions.end();++it){
        printf("%d %d\n",(*it).x,(*it).y);
    }
}
