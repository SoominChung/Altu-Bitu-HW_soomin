//
// Created by kirin on 2021-10-05.
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
 * 각 집들을 각각 세 가지 색으로 칠했을 때의 최솟값 모두 구해보며 풀어보기
*/

int calcMin(int n, vector<vector<int>> cost){
    vector<vector<int>> dp(n+1, vector<int>(3,0));
    // 굳이 초기화 안해도 dp[0]에는 0 들어있으므로 괜찮음.
    // 즉 dp[1]에는 cost[1]값이 그대로 들어가는 것  
    for(int i=1; i<=n;i++){ //2번째 집부터 시작
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) +cost[i][0]; //현재 집을 r로 칠하고, 그 전 집은 g or b 중 싼 걸로 칠함
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) +cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) +cost[i][2];
    }

    return min(min(dp[n][0],dp[n][1]),dp[n][2]); //n칠한 색 r,g,b 중 제일 작은 값 선택
}

int main(){
    int n;

    //입력
    cin>>n;
    vector<vector<int>> cost(n+1, vector<int>(3,0)); //r,g,b value
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin>>cost[i][j];
        }
    }

    //연산+출력
    cout<<calcMin(n, cost);

    return 0;
}