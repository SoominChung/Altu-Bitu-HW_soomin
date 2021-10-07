//
// Created by kirin on 2021-10-05.
//

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

/*
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0,0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0,2)~(2,2)에 걸쳐 있고, 사과는 (1,1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치 알기 위해 덱 사용
 * -> 덱의 front : 머리, back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */

typedef pair<int, int> ci;

ci dir[4]= { {0,1}, //우
             {-1,0}, //상
             {0,-1}, //좌
             {1,0} //하
};

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>> &board, map<int,char> &cmd){
    //뱀 초기화
    deque<ci> snake; // front는 머리, back는 꼬리
    snake.push_front(ci(0,0)); // (0,0)부터 시작한다.
    board[0][0] = 1; //뱀의 위치는 보드에서 1로 표현. 처음엔 (0,0)에 위치하므로

    int t=0, head = 0; // 시작한지 t초 후의 시간 표현, 뱀의 머리 방향
    while(true){
        t++; //loop 한 번 돌 때 마다 1초씩 증가
        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dir[head].first; //first는 x좌표를 나타냄. snake 원래 머리의 x좌표 + head로 향할 x좌표 (head 초기값 =0이므로 우측 이동으로 시작)
        int nc = snake.front().second + dir[head].second; //seconde는 y좌표 나타냄.

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
        if(nr<0 || nr>= n || nc<0 || nc >=n || board[nr][nc] ==1) //board[][] =1 이 뱀 존재한다는 뜻이므로
            break;

        if(board[nr][nc] != 2){ //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0; //snake의 back은 꼬리 부분이고, 보드에서 해당 위치를 0으로 변환
            snake.pop_back(); //꼬리 이동했으니까 pop해줌
        }
        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr,nc)); //front는 머리부분이므로 nr,nc가 향한 방향을 front에 push
        board[nr][nc] = 1; //뱀이 이동한 곳을 board에 표시

        //이번에 방향을 변환하는지 확인
        if(cmd[t] == 'L')//왼쪽 회전
            head = (head+1) %4; // 우->상, 상->좌, 좌->하, 하->우
        if(cmd[t] == 'D')//오른쪽 회전
            head = (head+3) %4; // 우->하, 하->좌, 좌->상, 상->우
    }
    return t;
}

int main(){
    int n,k,row,col,l,x;
    char c;

    //입력
    cin>>n>>k;
    vector<vector<int>> board(n, vector<int>(n)); //nxn짜리 보드 array로 표현.
    for(int i=0; i<k; i++){
        cin >> row >> col;
        board[row-1][col-1] = 2; //사과 위치를 2로 표시
        //내가 풀 때는 사과 array를 만들었는데 board array 만들어서 사과 위치를 2로 표시하는 방법 생각 못했었음
    }
    cin>>l; //회전 갯수
    map<int,char> cmd; // x초 이후, L/D 중 방향 char로 입력되는 회전 정보는 map으로 받음
    for(int i=0; i<l; i++){ //회전 정보
        cin >> x >> c;
        cmd[x] = c;
    }

    //연산 + 출력
    cout << playGame(n, board, cmd);

    return 0;

}