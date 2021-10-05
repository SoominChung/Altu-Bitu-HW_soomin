//
// Created by kirin on 2021-10-04.
//

#include <iostream>
#include <vector>

using namespace std;

// 상담원 백준의 퇴사
/*
 * N+1일에 퇴사. N일까지 상담 가능함.
 * 최대 이익 구하기
 *
 * [in]
 * 1. N(1~1,500,000)
 * 2. Ti, Pi
 *
 * [풀이]
 * 현재 날짜부터 시작하는 상담 넣을지 / 말지
 * 1. 넣었을 때: 이전 최댓값 +
 * 2. 안넣었을 때: 다음날
 * */

struct info{
    int start, end, duration;
};

int maxP(int n, vector<info> t, vector<int> p){
    vector<vector<int>> dp(n,vector<int>(n,0)); //행: 당일에 시작하는 상담
    for(int i=1; i<=n; i++){ //i:상담 시작 날짜 j: 최대 이익
        if(dp[t[i].start+1] >0) { // i일에 상담 불가한 경우
            for(int j=1; j<=n; j++){ // 그 전의 상담 정보 불러온다
                dp[i][j] = dp[i-1][j];
            }
        }
        for(int j=1; j<=n; j++){ // i일에 상담 시작 x
            dp[i][j] = dp[i-1][j]; //이전 정보 불러옴
        }

        for(int j=t[i].start; j<=t[i].end;j++){ // i일에 상담 시작 o
            dp[i][j] = max(dp[i-1][j-t[i].end]+p[i], dp[i-1][j]);
        }
    }

    return dp[n][n];
}

int main(){
    int n; //남은 퇴사일 수
    vector<info> t; //회의의 시간 정보
    vector<int> p; // 회의의 이익 정보

    //입력
    cin>>n;
    t.assign(n+1,{0,0,0}); //인덱스 1부터 시작할 예정
    p.assign(n+1,0);
    for(int i=1; i<=n; i++){
        t[i].start = i;
        cin>>t[i].duration>>p[i];
        t[i].end = i+t[i].duration;
    }

    //연산
    cout<<maxP(n,t,p);

    return 0;
}