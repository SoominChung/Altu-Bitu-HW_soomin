//
// Created by kirin on 2021-09-23.
//

#include <iostream>
#include <vector>

using namespace std;

// 체스판 다시 칠하기
const int SIZE = 62; //체스판 칸 개수

//(row,col)에서 시작하는 8*8 체스판 만드는데 드는 최소 카운트 리턴
//B로 시작하는 체스판 기준으로 계산한 후, W로 시작하는 체스판 만드는 바꾸는 칸 수는 64에서 빼서 계산
int chessChange(int row, int cal, vector<vector<char>> &board){ //같은 보드니까 주소로 받아요
    int b_cnt = 0;//B로 시작하는 체스판 만들기 위한 카운트

    for(int i=0; i<8; i++){ //행 변화값
        for(int j=0; j<8; j++){ //열 변화값
            //행 변화값 + 열 변화값이 짝수면 시작색(B)과 동일해야함 -> 동일 안하면 카운트
            if((i+j)%2 == 0 && board[row+i][cal+j] != 'B'){
                b_cnt++;
            }
            // 변화값 합이 홀수면 시작색과 반대색(W)여야함 -> W아니면 카운트
            else if((i+j)%2 && board[row+i][cal+j] != 'W'){
                b_cnt++;
            }
        }
    }

    //최솟값 리턴
    if(b_cnt > SIZE/2){
        return SIZE - b_cnt;
    }
    return b_cnt;
}

int main(){
    int n,m;
    int ans = SIZE+ 1; //정답은 칸 개수 +1로 초기화

    //입력
    cin>>n>>m;
    vector <vector<char>> board(n, vector<char>(m)); //행 :n, 열:m
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    //연산
    for(int i=0; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            int cnt = chessChange(i,j,board);//시작 인덱스가 (i,j)인 체스판 만드는 최솟값
            ans = min(ans, cnt);//최솟값 갱신
        }
    }

    //출력
    cout << ans << '\n';

    return 0;
}