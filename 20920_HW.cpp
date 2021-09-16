//
// Created by kirin on 2021-09-16.
//

//영어단어장 만들기

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n,m; // 단어 개수 & 암기 해야하는 단어 길이 기준
    map<string, int> words_number; // 단어와 나온 개수
    vector<string> words;
    vector<bool> flag; // 해당 단어가 나왔는지 안나왔는지 알기 위해
    // (map도 vector assign처럼 초기화 가능한가..? 초기화 하는 법 모르겠어서 vector 사용)

    //입력
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>words[i];
    }

    //초기화
    flag.assign(n,false);
    words.assign(n,{});

    //연산
    for(int i=0; i<n; i++){
        if(!flag[i]){ //false이면 한 번도 안나온 단어니까 새롭게 추가
            words_number[words[i]] = 1;
            flag[i] = true;
        }
        else{ // 이미 나온 단어는 개수만 추가
            words_number[words[i]] ++;
        }
    }

}