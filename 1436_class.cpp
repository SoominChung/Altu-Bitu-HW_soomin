//
// Created by kirin on 2021-09-22.
//

#include <iostream>

using namespace std;

// n번째 종말 숫자 (666 세 번이상 연속) n ~ 10,000
// 6,660,000~ 6,669,999 : 1만개이므로 브루트포스 사용해도 된다!

//n번째 종말의 숫자 리턴
int endNumber(int n){
    int cnt = 0;//종말의 숫자 카운트
    //666(1번째 종말의 숫자)부터 차례로 모두 검사해보기
    for(int i=666;;i++){
        string s = to_string(i); //숫자 -> 문자열로 치환
        if(s.find("666") != s.npos){ //npos = 문자열의 끝. "666"존재한다ㅕㅁㄴ
            cnt++;
        }
        if(cnt == n){
            return i;
        }
    }
}

int main(){
    int n;
    //입력
    cin>>n;

    //연산+출력
    cout<<endNumber(n)<<'\n';
}
