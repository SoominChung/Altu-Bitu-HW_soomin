//
// Created by kirin on 2021-10-04.
//

#include <iostream>
#include <vector>

using namespace std;

//RGB 거리
/*
 * N개의 집. 거리는 선분으로 나타낼 수 있고, 1번집~ N번집 순서대로 있음
 * 1번 집 != 2번 집
 * N번 집 != N-1번 집
 * i(2~N-1)번 집 != i-1번 != i+1번 (양 옆의 집과 다르다)
 *
 * [in]
 * N(2~1000)
 * 각 집을 RGB 각각으로 칠할 때 드는 비용(<=1000)
 *
 * [out]
 * 모든 집 칠하는 비용의 최솟값
 *
 * [풀이]
 * 각 집들을 각각 세 가지 색으로 칠했을 때의 최솟값 모두 구해보며 풀어보기기
*/
struct rgb{
    int r,g,b;
};
int calcMin(int n, vector<rgb> cost){
    vector<vector<int>> dp(n,vector<int>(3,0));
    dp[0][0] = cost[0].r;
    dp[0][1] = cost[0].g;
    dp[0][2] = cost[0].b;

    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i].r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i].g;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i].b;
    }

    return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]); // min 인자 최대 개수는 2개이므로, 3개 비교하려면 두 개 묶어야함
}

int main(){
    int n;
    vector<rgb> cost; //각 집을 RGB 각각으로 칠했을 때의 가격

    //입력
    cin>>n;

    cost.assign(n,{0,0,0});
    for(int i=0; i<n; i++){
        cin>>cost[i].r >>cost[i].g >> cost[i].b;
    }

    //연산 + 출력
    cout<<calcMin(n, cost);

    return 0;
}