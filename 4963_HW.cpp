//
// Created by kirin on 2021-10-23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> ci; //row, col 저장하기 위한 pair

int visited[50][50]; //방문 체크
//int map[50][50];
/*
 * 섬의 개수
 * 섬 : 한 정사각형과 가로, 세로, 대각선으로 연결되어 있는 사각형
 *
 * in : 여러 개의 테스트 케이스. 첫째 줄에 지도의 너비 w와 높이 h
 * 입력 마지막 줄에는 0 0
 *
 * out : 각 테스트 케이스에 대해 섬의 개수 출력하기
 */

// 참고 : https://romanceboong.tistory.com/entry/%EB%B0%B1%EC%A4%80-4963%EB%B2%88-%EB%AC%B8%EC%A0%9C-%EC%84%AC%EC%9D%98-%EA%B0%9C%EC%88%98

void dfsRecur(int i, int j, int n, int m,vector<vector<int>> &map){
    visited[i][j]=1; //방문한 곳 표시하기

    int dr[8] = {-1,1,0,0,-1,-1,1,1};
    int dc[8] = {0,0,-1,1,-1,1,-1,1};
    int nr, nc; //next row, next column

    for(int k=0; k<8; k++) { //상하좌우대각선 탐색
        nr = i + dr[k];
        nc = j + dc[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == 1 && visited[nr][nc] == 0) {
            //노드가 범위 안에 있고 땅이고 방문한 적 없다면
            dfsRecur(nr, nc, n, m, map);
        }
    }
}



int islandNum(int n, int m, vector<vector<int>> &map, queue<ci> q){
    // 한 번 탐색 진행하면 그게 하나의 섬임.
    // 상하좌우대각선
    int dr[8] = {-1,1,0,0,-1,-1,1,1};
    int dc[8] = {0,0,-1,1,-1,1,-1,1};
    int cnt=0;

    /*
     * BFS 말고 DFS 써야할듯
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){ // 상하좌우대각선 방향 탐색 (인접한 노드)
            int nr = cr + dr[i]; // 방문하려는 노드
            int nc = cc + dc[i]; // 방문하려는 노드
            if(nr>0 && nr<=n && nc>0 && nc<=m && matrix[nr][nc] ==1){
                //노드가 범위 안에 있고 땅이라면
                matrix[nr][nc] = matrix[cr][cc]+1; //
                q.push(ci(nr,nc));
            }
        }

    } */

    return cnt;
}

int main(){

    int n,m;
    while(1) {
        int cnt =0; //섬 개수
        cin >> m >> n;
        if(n==0 && m==0) //입력 종료를 뜻하는 시그널
            break;
        vector<vector<int>> map(n, vector<int>(m, 0));

        for(int i=0; i<50; i++){ //어차피 최대 크기가 50x50이니까 이렇게 초기화 하기
            for(int j=0; j<50; j++){
                visited[i][j]=0; // visited 여부 초기화
           }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j]; // map 정보 입력
                //if(map[i][j] ==1) //땅 바로 삽입 (시작 노드)
                //    q.push(ci(i,j));
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j]==1 && visited[i][j]==0){ //땅이고, 방문하지 않았다면
                    dfsRecur(i,j,n,m,map);
                    //cout<<"i: "<<i<<' '<<"j: "<<j<<" \n";
                    cnt++;
                }
            }
        }
        //cout<<islandNum(n,m,map,q)<<'\n';
        cout<<cnt<<'\n';
    }
    return 0;
}
