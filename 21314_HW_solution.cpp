//
// Created by kirin on 2021-10-12.
//

#include <iostream>

using namespace std;

//민겸 수
/**
 * 0이상의 정수 N에 대해 10^N 또는 5x10^N꼴의 십진수를 M,K로 이루어진 문자열로 표기한다.
 * 10^N꼴의 십진수는 N+1개의 M으로, 5x10^N꼴의 십진수는 N개의 M 뒤에 1개의 K를 이어붙이 문자열
 * 민겸수 -> 십진수 다양하고 : 1개 이상의 민겸 숫자로 문자열 분리한 뒤, 각각의 민겸 숫자를 십진수로 변환해서 순서대로 이어붙이면 됨.
 * 그 때의 최댓값 , 최솟값
 */

/**
 * SOL
 * [가장 큰 값]
 * 민겸수에서 마지막이 K일 때, K까지 포함하여 십진수로 변환한다
 * K로 끝나지 않는다면 각 M을 모두 하나로 처리한다 (ex. MMM -> 111)
 *
 * [가장 작은 값]
 * K는 무조건 단독으로 변환
 * 나머지 M묶음들은 같이 변환한다.
 * ex. MM/K/MM -> 10510
 */

string maxNum(string s){
    string ans = "";
    string temp = "";
    for(int i=0; i<s.length(); i++){ // s 하나하나 돌면서
        temp += '0'; //K나오기 전까지는 0으로 충전
        if(s[i] == 'K'){ //K가 마지막으로 끝나는 십진수 변환
            temp[0] = '5'; //K를 찾으면 맨 앞(왼쪽) 자리수가 1->5
            ans += temp; //ans에는 iter한 번에서 만들어진 tmp 값을 넣어주고
            temp = ""; //다음 iter 위해 비운다
        }
    }
    if(temp.length() >= 1){ //K로 끝나지 않았다면 마지막 M모두 1로 변환
        for(int i=0; i<temp.length(); i++){ //맨 앞부터 temp 끝까지
            temp[i] = '1';
        }
        ans += temp; //마지막으로 temp ans에 더해주고
    }
    return ans; //ans return
}

string minNum(string s){
    string ans = "";
    string temp = "";
    char first = '1'; //M묶음은 같이 변환할 것이므로
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'M'){ //M 처음 나오면
            temp += first; //1 넣어준 후
            first = '0'; //그 다음부터는 M은 묶어줄거라 0만 나올 것
        }else{ // 'K' -> 그 전까지 M묶음 변환 더하고, K는 따로 변환
            ans += temp + '5';
            temp = "";
            first = '1'; // 그 이후는 1로 다시 바꿔줌
        }
    }
    if(temp.length() >= 1){ //K로 안끝났다면
        ans += temp; //나머지 다 더해줌
    }
    return ans;

}


int main(){
    string s;

    //입력
    cin >> s; //민겸수 입력받기

    //출력
    cout << maxNum(s) << '\n' << minNum(s) << '\n'; // max10진수 다음칸 min10진수
    return 0;
}