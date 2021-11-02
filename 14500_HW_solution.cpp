//
// Created by kirin on 2021-11-02.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * <테트로미노>
 * 정사각형 4개 이어붙인 폴리오미노 = 테트로미노 (총 5종류)
 * 폴리오미노의 조건
 * 1. 정사각형 서로 겹치면 안 됨
 * 2. 도형은 모두 연결되어 있어야 함
 * 3. 정사각형의 변끼리 연결 되어있어야 함. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 됨.
 *
 * NxM 크기 종이에 테트로미노 하나 놓으려 하는데, 종이는 1x1로 나누어져 있고 각 칸에는 정수 쓰여있음.
 * 테트로미노 하나를 적절히 놓아서 테트로미노 놓인 칸에 쓰인 수 합을 최대로 하는 프로그램 작성하기.
 * 테트로미노 회전이나 대칭 시켜도 됨.
 *
 * [in]
 * 1. 세로 크기 N, 가로 크기 M (4<=N, M<=500)
 * 2. 이후에는 각 칸에 쓰인 숫자 (<=1000)
 * */
int ans, n, m;
vector<vector<int>> board;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

//board[row][col]을 가운데로 하는 +모양 만들기 -> 보라색 블럭 처리하기 위해
int horn(int row, int col){
    int cnt = 0, min_block = 1001, sum = board[row][col];
    // min_block은 각 칸에 쓰인 숫자 중 젤 작은 값. 1000이하의 값이기 때문에 1001로 초기화.
    // sum에 우선 중심 블럭의 값 더해놓음

    for(int i=0; i<4; i++){ //상하좌우 방향 둘러볼 것임
        int nr = row + dr[i]; //다음에 볼 row 값
        int nc = col + dc[i]; //다음에 볼 col 값

        if(nr <0 || nr >=n || nc<0 || nc >= m)//범위를 벗어나면 무시
            continue;
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc]; // sum에 nr,nc 블럭의 값 더함
        cnt++;
    }
    if(cnt<3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0; //모퉁이에 있는 블럭 돌아보는 경우 등이겠지
    if(cnt ==3) //ㅗㅏㅜㅓ
        return sum; //애초에 둘러보기가 가능한 가장자리가 3개밖에 없다면 바로 3개 더한 값 return하면 되지
    //+
    return sum - min_block; //일단 4개 다 더하고 그 중 젤 작은 모퉁이 하나 뺌
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum){
    if(cnt == 4){ //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans,sum); //기존 최댓값이랑 현재 탐색한 sum 값이랑 비교해서 큰 값 넣음
        return;
    }

    for(int i=0; i<4; i++){ //상하좌우 방향으로 탐색
        int nr = row+dr[i];
        int nc = col+dc[i];

        if(nr<0 || nr>=n || nc<0 || nc>=m || !board[nr][nc]) //범위를 벗어났거나, 이미 방문했다면
            continue;

        int save = board[nr][nc]; //우선 현재 블럭 값 저장해놓고
        board[nr][nc] =0; // 탐색한거니까 0으로 만들음
        backtracking(nr,nc,cnt+1,sum+save); //nr,nc로부터 또 다음 방향의 블럭을 탐색해봄
        board[nr][nc] = save; // backtraking 모두 끝나면 다음번 탐색을 위해 0이었던 값 되돌려 놓는다.

    }
}

/*
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나눈다.
 *   -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능, 아니라면 불가능
 *   -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *   -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 */
int main(){
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    //연산
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, horn(i,j)); //보라색 블럭 처리
            //기존에 저장된 ans 값보다 보라색 블럭으로 탐색한 값이 더 크다면 대체
            int save = board[i][j]; //다음 번에 탐색할 때 0으로 만든 값 다시 되돌려놓기 위해 저장해 놓음

            board[i][j] = 0; //탐색한 블럭은 0을 넣음
            backtracking(i,j,1,save); //나머지 모양 처리
            board[i][j] = save; //다시 되돌려 놓음
        }
    }

    //출력
    cout<<ans;
}