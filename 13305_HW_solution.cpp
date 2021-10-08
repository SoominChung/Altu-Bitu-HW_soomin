//
// Created by kirin on 2021-10-08.
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

//주유소
/*
 * 자동차는 1km마다 1L의 기름 사용
 * 각 도시마다 기름 값 다를 때 제일 왼쪽 -> 제일 오른쪽 도시로 이동할 때 최소 비용 사용하기
 *
 * 1. 주유소와 차 연결하는 아주 긴 호스 있다고 가정하기 -> 이거 이해 못했었는데, 주유하고 그 도시 떠나서 빠이하는 게 아니라 이후의 도로 만나도 계속 이전 도시 주유값 사용하는 걸로 상상하면 됐음
 * 2. 지금까지 지나온 도시 중 가격이 가장 저렴한 주유소와 호스를 연결한다
 * 3. 이번에 도착한 도시의 기름값이 지금 호스에 연결된 주유소의 기름값보다 저렴하다면 호스 교체
 */

ll greedyOil(vector<pair<ll,ll>> &city, int n){
    ll cur_cost = city[0].second, tot_cost=0; //현재 기름값은 제일 처음 도시의 기름값으로 초기화. tot_cost는 최소 비용 값이므로 0으로 초기화

    //point: 복잡하게 생각할 거 없이 눈앞에 놓인 도로 갈 때 제일 싸게 갈 수 있는 값을 택하면 됐다..!
    for(int i=0; i<n; i++){ // n개의 도시 동안
        if(city[i].second < cur_cost) // 이 도시의 기름값이 더 저렴하면 교체
            cur_cost = city[i].second;
        tot_cost += (cur_cost * city[i].first); // 이동 비용 = 현재 기름 값 * 도로의 길이
    }
    return tot_cost;
}



int main(){
    int n;

    //입력
    cin>>n;
    vector<pair<ll,ll>> city(n,{0,0}); //city.first : 인접 도시 연결하는 도로 길이, city.second : 해당 도시의 기름값
    //10억 이하의 숫자들이므로 ll로 받아준다
    //point: 도로 길이와 비용 크기 다르다고 굳이 다른 vector로 만들 필요 없었음!
    for(int i=0; i<n-1; i++){ //두 도시 연결하므로 n-1개
        cin>>city[i].first;
    }
    for(int i=0; i<n; i++){ // 각 도시에 대한 기름값이니 n개
        cin>>city[i].second;
    }

    //연산 & 출력
    cout<< greedyOil(city, n);

    return 0;
}