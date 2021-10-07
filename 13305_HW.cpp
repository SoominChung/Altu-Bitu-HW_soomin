//
// Created by kirin on 2021-10-05.
//

#include <iostream>
#include <vector>

using namespace std;

//주유소
/*
 * 자동차는 1km마다 1L의 기름 사용
 * 각 도시마다 기름 값 다를 때 제일 왼쪽 -> 제일 오른쪽 도시로 이동할 때 최소 비용 사용하기
 */

//힌트: 주유소와 차 연결하는 아주 긴 호스 있다고 가정하기

int minCost(int n, vector<int> road, vector<int> oil){
    //road[i] : 이동할 때 최소 필요한 기름 양

}

int main(){
    int n;
    vector<int> road;
    vector<int> oil;

    //입력
    cin>>n;
    road.assign(n-1,0); //n-1개의 도로 길이
    oil.assign(n,0); //n개 도시별 주유소 기름 값
    for(int i=0; i<n-1; i++){
        cin>>road[i];
    }
    oil.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>oil[i];
    }

    //연산
    cout<<minCost(n,road,oil);

    return 0;
}