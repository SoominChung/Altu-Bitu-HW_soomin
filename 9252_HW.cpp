//
// Created by kirin on 2021-11-15.
//

//
// Created by kirin on 2021-11-10.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * LCS : 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 거 찾기
 *
 * LCS 길이 찾기 까지는 pdf의 점화식 보고 코드 완성하였고,
 * 역추적 부분에서 힌트에 위치 외에 다른 값 저장하는 거 고민해보라고 쓰여있었는데, 고민해봐도 모르겠어서 아래 링크 참고함.
 * https://ongveloper.tistory.com/116?category=854013
 * string으로 path를 구현하는 방법!
 *
 */

typedef pair<int, int> ci;

/*
vector<int> back(int n, int m, vector<int> &path){
    vector<int> result(0);
    ci x ={n,m};
    while(x.first != -1 && x.second != -1){
        //cout<<x<<' ';
        result.push_back(x.first);
        x = path[x.first][x.second]; //다음 경로
    }

    return result;
}
 */

int lis(int n,int m, string s1, string s2, vector<vector<string>> &path){
    vector<vector<int>> dp(n+1, vector<int>(m+1,0)); //최소 길이인 0으로 초기화 (겹치는게 1도 없을지도)
    //ci ans = {0,0}; //자기자신 포함된 최장 길이, 마지막 원소의 idx

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) {
            if (s1[i - 1] == s2[j - 1]) { //문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1; //해당 문자들 포함되기 전 길이+1
                // 그 전은 좌상향 대각선
                //path[i][j] = {i-1,j-1};
                path[i][j] = path[i - 1][j - 1] + s1[i - 1]; //이전 알파벳 바로 덧붙임
            }
            else{ //문자 서로 다르다면
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //그전의 최댓값 그대로 가져온다
                //그 전은 위쪽, 왼쪽. 둘 중에 더 큰 값
                path[i][j] = (path[i - 1][j].length() > path[i][j - 1].length()) ? path[i - 1][j] : path[i][j - 1];
                //dp와 같은 맥락으로 큰 값을 선택해서 넣어줌
            }
        }
    }

    //ans = {dp[n][m],};
    return dp[n][m];

}

int main(){

    string s1, s2;

    //입력
    cin>>s1>>s2;
    int n = s1.size(), m=s2.size();
    vector<vector<string>> path(n+1,vector<string> (m+1)); //경로 저장 배열, 경로 없는 {-1,-1}로 초기화
    //string path[n+1][m+1];

    //연산
    int ans = lis(n, m,s1, s2, path);
    //vector<int> result = back(n,m,path);

    //출력
    cout<<ans<<'\n';
    if(ans != 0) {
        cout<<path[n][m]; //따로 back function을 사용하지 않고 바로 구현 가능했음
        /*for (int i = result.size() - 1; i >= 0; i--) {
            cout << s1[result[i]];
        }*/
    }


    return 0;
}