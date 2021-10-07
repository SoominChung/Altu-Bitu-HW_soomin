//
// Created by kirin on 2021-10-05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 풀이 1. 1번 인덱스부터
 * 1번째 날부터 시작하여 i번째 날을 끝으로 하는 상담 최댓값 저장하기
 * 현재 날을 상담하는 걸 택하면 현재 날에 상담이 걸리는 날을 더한 날의 최댓값이 변경됨
 */
typedef pair<int,int> ci;

//1번 인덱스부터 계산
int maxMoney_1(int n, vector<ci> &counsel){
    vector<int> dp(n+2,0); //i날에 대한 금액을 저장함

    //i번째 날에 대한 상담 최댓값 구하기
    for(int i=1; i<=n; i++){
        dp[i] = max(dp[i], dp[i-1]); // 우선 i번째 상담 안하는 경우
        if(i+counsel[i].first <= n+1){ // i번째 상담이 가능한 경우
            //dp[i+duration]에는 두 가격 비교해서 저장함: i+duration날에 i상담 안했을 경우 금액 vs  i번째 날의 금액+counsel했을 때의 금액
            dp[i+counsel[i].first] = max(dp[i+counsel[i].first], dp[i]+counsel[i].second);
        }
    }
    return max(dp[n], dp[n+1]); //n-1과 n일 중 큰 금액의 날짜 값을 return
}

//n번 인덱스부터 계산
int maxMoney_n(int n, vector<ci> &counsel){
    vector<int> dp(n+2, 0);

    for(int i=n; i>=1; i--){
        dp[i] = dp[i+1]; //우선 i번째 상담 안하는 경우
        if(i+counsel[i].first <= n+1){ //i번째 상담이 가능한 경우
            dp[i] = max(dp[i], dp[i+ counsel[i].first]+counsel[i].second); //상담 하는 경우 vs 안하는 경우 중 큰 금액 넣음
        }
    }

    return dp[1]; //n번 인덱스부터 계산했으므로 1일차에 지금까지의 금액이 누적됨됨
}
int main(){
    int n;

    //입력
    cin>> n;
    vector<ci> counsel(n+1);
    for(int i=1; i<=n; i++){
        cin >> counsel[i].first >> counsel[i].second; //first: duration, second: money
    }

    //연산+출력
    cout<<maxMoney_1(n, counsel) << '\n';
    //cout << maxMoney_n(n, counsel) << '\n';

    return 0;
}