//
// Created by kirin on 2021-09-07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dot{
    int x, y;
};

//비교함수
bool cmp(const dot &d1, const dot &d2){
    if(d1.y != d2.y){
        return d1.y < d2.y;
    }
    if(d1.x != d2.x){
        return d1.x < d2.x;
    }
    return d1.y < d2.y;
}

int main(){
    int n;
    vector<dot> dots;

    //입력
    cin >> n;
    dots.assign(n,{});
    for(int i=0; i<n; i++){
        cin>> dots[i].x>> dots[i].y;
    }

    //연산
    sort(dots.begin(), dots.end(),cmp);

    //출력
    for(int i=0; i<n; i++){
        cout<<dots[i].x<<' '<<dots[i].y<<'\n';
    }
}