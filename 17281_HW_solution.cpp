//
// Created by kirin on 2021-10-12.
//

#include <iostream>
#include <vector>

using namespace std;

//야구게임
/**
 * N이닝 동안 게임 진행. (하나의 이닝 : 공격+수비)
 * 한 이닝에 3아웃이 발생하면 이닝 종료되고, 두 팀이 공격과 수비를 서로 바꾼다.
 * 두 팀 경기 시작 전에 타순 먼저 정함. 타순은 경기 내내 불변
 * 공격: 투수가 던진 공 타자가 치는 거. -> 안타: 타자, 모든 주자 한 루씩 진루, 2루타: "2루씩, 3루타:"세루씩, 홈런: "홈까지 진루, 아웃: 모든 주자 진루 못함
 *
 * 1번 선수만 4번 타자로 미리 결정돼있음. 최고득점 가능한 타순 정하기.
 *
 * [in]
 * N 이닝 수 (2~50)
 * 각 선수가 각 이닝에서 얻는 결과가 1번 이닝~N번 이닝까지 순서대로 주어짐.
 * (안타:1, 2루타:2, 3루타:3, 홈런:4, 아웃:0)
 * 각 이닝에는 아웃 기록하는 타자 적어도 한 명 존재
 *
 * [solution]: 구현+브루트 포스+백트래킹
 * 1. 우선 가능한 타순 모두 구한다. (4번 타자는 항상 1번 선수.) -> 브루트 포스, 백트래킹
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */
vector<vector<int>> innings;
vector<int> order(10,0); //타순
vector<bool> check(10,false); //각 선수 순서 정해졌는지 check
int n, ans;

//현재 배치의 점수
int calcScore(){
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for(int i=0; i<n; i++){ //i: 이닝
        vector<bool> baseman(4,0); // 각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while(out < 3){ //out 3번 되기 전 동안
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if(idx == 10) //9명 다 돌았으면
                idx = 1; //1번 선수로 다시 돌아감
            switch(state){ //공격상태에 따라 base내에서의 이동, 점수 획득 등 달라짐
                case 0:
                    out++;
                    break;
                case 1: //안타, 1루씩 진루
                    score += baseman[3]; //3루에 있는 선수 있다면 홈 도착
                    for(int i=3; i>0; i--){
                        baseman[i] = baseman[i-1]; // 이전 루에서 다음 루로 이동
                    }
                    baseman[1] = 1; //새로운 선수가 1루에 도착
                    break;
                case 2: //2루타, 2루씩 진루
                    score += baseman[3] + baseman[2]; //3루, 2루에 선수 있다면 홈 도착
                    baseman[3] = baseman[1]; //1루 -> 3루 이동
                    baseman[2] = 1; //새로운 선수 2루에 도착
                    baseman[1] = 0; //초기화
                    break;
                case 3: //3루타, 3루씩 진루
                    for(int i=3; i>0; i--){ //3루,2루,1루에 선수 있다면 홈 도착
                        score += baseman[i];
                        baseman[i] = 0;
                    }
                    baseman[3]= 1; //새로운 선수 3루에 도착
                    break;
                case 4: //홈런
                    for(int i=3; i>0; i--){ //3루,2루,1루에 선수 있다면 홈 도착
                        score += baseman[i];
                        baseman[i] = 0;
                    }
                    score++; // 새로운 선수도 홈 바로 도착
                    break;
            }
        }
    }

    return score;
}

//가능한 배치 모두 구하기
void array(int cnt){ //cnt : 타자 순서
    if(cnt == 4){ //4번타자는 정해져 있으므로
        array(cnt+1); //5번 타자 정하러 감
        return;
    }
    if(cnt == 10){ //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score); //지금까지 배치 중 젤 컸던 점수 값이랑 비교
        return;
    }
    for(int i=2; i<=9; i++){
        if(!check[i]){ //i선수 아직 타순 안정해졌다면
            order[cnt] = i; //cnt번 타자 : i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt+1); //다음 타자 순서 정하러 감
            check[i] = false; // 한 배치에 대한 거 모두 끝나면 다음 배치를 위해 원상복귀
        }
    }

}

int main(){
    //입력
    cin>>n;
    innings.assign(n,vector<int>(10,0)); //n:이닝 횟수, 9명의 선수 (1~9)
    for(int i=0; i<n; i++){
        for(int j=1; j<10; j++){
            cin>> innings[i][j];
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수로 고정
    check[1] = true; //1번 선수는 순서 정해짐
    array(1); //1번 타자부터 정해야 함 -> 모든 경우에 대한 타순 돌아가봄

    //출력
    cout<<ans<<'\n'; //최고득점 ans

    return 0;
}