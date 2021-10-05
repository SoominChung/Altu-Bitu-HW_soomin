//
// Created by kirin on 2021-10-03.
//

#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

//할리갈리 게임
/* 1. 그라운드 시작: 처음엔 그라운드 빔. 인당 1 그라운드
 * 2. 가장 위 카드 도도->수연 순으로 그라운드에 내려놓음
 * 3. 종 치면 모든 그라운드 카드 가져감: 1) 숫자 합 5일 때 수연이(빈 그라운드 x) 2)숫자 5 등장하면 도도
 * 4. 종 친 후에는 상대 그라운드의 카드 더미 뒤집어서 자신의 덱 아래로 그대로 넣음. 자신의 그라운드 더미도 덱 아래에 넣음
 * 5. M번 진행 후 자신 덱에 더 많은 카드 지닌 사람이 승리. 덱 수 같으면 비긴거. 한 쪽 0되면 지는거
 * 6. 2~4 과정 = 1번 진행한 거
 *
 * [입력]
 * 카드의 개수 N(1~30,000) 게임 진행 횟수 M(1~2,500,000)
 * N개의 줄에는 덱의 맨 아래부터 맨 위에 위치한 카드까지 차례대로 주어짐(1~5사이의 수)
 */
/*
void push_card(string winner){
    if(winner == "do"){
        for (int i = 0; i < do_ground.size(); i++) { //do의 ground deck 뒤집어서 수연이가 가져감
            su_deck.push_back(do_ground.front());
            do_ground.pop();
        }
        for(int i=0; i< su_ground.size(); i++){ //su의 ground deck도 뒤집어서 수연이가 가져감
            su_deck.push_back(su_ground.front());
            su_ground.pop();
        }
    }
    else{
        for (int i = 0; i < su_ground.size(); i++) { //su의 ground deck 뒤집어서 도도가 가져감
            do_deck.push_back(su_ground.front());
            su_ground.pop();
        }
        for(int i=0; i< do_ground.size(); i++){ //do의 ground deck도 뒤집어서 도도가 가져감
            do_deck.push_back(do_ground.front());
            do_ground.pop();
        }
    }
}
*/
string haligarli(int m, deque<int> do_deck, deque<int> su_deck, queue<int> do_ground, queue<int> su_ground){
    int cnt=0; // 몇 번의 그라운드 진행했는지 count

    while(cnt < m){
        if(do_deck.empty() || su_deck.empty()) { // 둘 중 덱이 다 떨어지면 m라운드 이전이어도 게임 종료됨
            cout<<"empty";
            return (do_deck.empty()) ? "su" : "do";
        }

        do_ground.push(do_deck.back()); // do가 그라운드에 카드 냄
        do_deck.pop_back(); // ground에만 push하고 deck에서 pop하는 거 까먹었음ㅠ
        su_ground.push(su_deck.back()); //su가 그라운드에 카드 냄
        su_deck.pop_back();
        // do 이후에 종 칠 기회 -> su 이후에 종 칠 기회 이렇게 나눠야하는데,,
        if(!su_ground.empty()) { //수연이 종치는 조건
            if(do_ground.back()+su_ground.back() == 5) {
                for (int i = 0; i < do_ground.size(); i++) { //do의 ground deck 뒤집어서 수연이가 가져감
                    su_deck.push_front(do_ground.front());
                    do_ground.pop();
                }
                for (int i = 0; i < su_ground.size(); i++) { //su의 ground deck도 뒤집어서 수연이가 가져감
                    su_deck.push_front(su_ground.front());
                    su_ground.pop();
                }
                cnt++;
            }
        }
        if(do_ground.back() ==5 || su_ground.back() ==5){ //do의 종치는 조건
            for (int i = 0; i < su_ground.size(); i++) { //su의 ground deck 뒤집어서 도도가 가져감
                do_deck.push_front(su_ground.front());
                su_ground.pop();
            }
            for(int i=0; i< do_ground.size(); i++){ //do의 ground deck도 뒤집어서 도도가 가져감
                do_deck.push_front(do_ground.front());
                do_ground.pop();
            }
            cnt ++;
        }


        deque<int>::iterator iter;
        cout<<"[ "<<cnt<<" ]\n";
        cout<<"do deck\n";
        for(iter = do_deck.begin(); iter != do_deck.end(); iter++){
            cout<<*iter<<' ';
        }
        cout<<'\n';

        cout<<"su deck\n";
        for(iter = su_deck.begin(); iter != su_deck.end(); iter++){
            cout<<*iter<<' ';
        }
        cout<<'\n';

        //cnt++;
        //cout<<do_ground.front();

    }
    if(cnt == m){ //m만큼의 그라운드 진행 했다면 끝내야지
        if(do_deck.size() > su_deck.size())
            return "do";
        if(do_deck.size() < su_deck.size())
            return "su";
        return "dosu";
    }


}

int main(){

    deque<int> do_deck; //카드 더미는 deque(deck)으로 구현한다.
    deque<int> su_deck;

    queue<int> do_ground; //ground는 queue으로 구현한다.
    queue<int> su_ground;


    int n,m; // 카드 개수, 끝나는 그라운드
    int do_tmp, su_tmp; //각 덱 받기 위한 tmp 변수

    //입력
    cin>> n >> m;
    for(int i=0; i<n; i++){
        cin>>do_tmp>>su_tmp;
        do_deck.push_back(do_tmp);
        su_deck.push_back(su_tmp);
    }

    /*
    deque<int>::iterator iter;
    cout<<"first su deck\n";
    for(iter = su_deck.begin(); iter != su_deck.end(); iter++){
        cout<<*iter<<' ';
    } */


    //연산+출력
    cout<<haligarli(m,do_deck,su_deck,do_ground,su_ground);

    return 0;

}