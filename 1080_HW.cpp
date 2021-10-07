//
// Created by kirin on 2021-10-06.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/** 행렬
 * 0과 1로만 이루어진 행렬 A, B.
 * A -> B로 바꾸는데 필요한 연산 횟수의 최솟값 구하기
 *
 * [입력]
 * 행렬 크기 NxM (N,M <50)
 * A
 * B
 *
 * [출력]
 * 정답. 바꿀 수 없으면 -1
 */

vector<vector<int>> a;
vector<vector<int>> b;

bool findDifference(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] != b[i][j]){
                return true; //하나라도 다르면 true return
            }
        }
    }

    return false; //모든 원소 동일하면 false return
}

int changeMatrix(int n, int m) {
    // 최선 : 두 행렬의 문자가 다를경우 바로 바꿔주는 것
    int cnt = 0; // 연산 실행 횟수
    for (int i = 0; i < n - 2; i++) { //3x3의 부분 수열을 변환시키는 것이므로 i= 0 ~ n-3까지임
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) { //(i,j) 원소가 다르다면 해당원소를 0,0으로 위치한 3x3 부분배열을 바꿔준다
                for (int k = i; k < i + 3; k++) {
                    for (int t = j; t < j + 3; t++) {
                        a[k][t] = !(a[k][t]); //a의 원소를 0/1 반대로 넣는다.
                    }
                }
                cnt++;
            }
            /*
             * //각 행 갈 때마다 검사하면 -1인 경우는 빨리 걸러내지 않을까 하는 마음에 작성해본 코드
            if(j==(m-3)){ //각 행의 맨 오른쪽 모서리에 왔을 때
                if(a[i][j+1]!=b[i][j+1] || a[i][j+2]!=b[i][j+2]){ //j=m-2, m-1 부분은 다르면 가망이 없으므로 -1을 리턴
                    return -1;
                }
            }
            if(i==(n-3)){ //matrix의 맨 우측 하단 도착했을 때
                for(int k=i;k<i+3;k++){ // 3x3 영역 전체 확인하기
                    for(int t=j; t<j+3; t++){
                        if(a[k][t] != b[k][t]){ //하나라도 다르면 return -1
                            return -1;
                        }
                    }
                }
            }
             */
        }
    }

    if (!findDifference(n, m)) // a와 b의 모든 원소 같다면 cnt return
        return cnt;

    return -1; //하나라도 다르다면 -1 return

}

int main(){
    int n,m;
    string row;

    ios::sync_with_stdio(false); //입출력 속도 향상
    cin.tie(NULL);

    //입력
    cin >> n >> m;
    a.assign(n, vector<int>(m,0));
    b.assign(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        cin >> row;
        for(int j=0; j<m; j++){
            a[i][j] = (int)(row[j]-'0');
        }
    }
    for(int i=0; i<n; i++){
        cin >> row;
        for(int j=0; j<m; j++){
            b[i][j] = (int)(row[j]-'0');
        }
    }


    //연산+출력
    cout<<changeMatrix(n, m)<<'\n';

    return 0;
}