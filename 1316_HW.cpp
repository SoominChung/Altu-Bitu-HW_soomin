//
// Created by kirin on 2021-09-08.
//

// 그룹 단어 체커

#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int groupChecker(string word){

    char word_array[word.length()];
    strcpy(word_array, word.c_str());

    // alphabet map 생성
    map<char, int> repeat_alphabet;
    for(char ch1 = 97; ch1 < 123; ch1++){
        repeat_alphabet[ch1] =200;
    }

//    for(char ch1 = 65; ch1<91; ch1++){
//        cout<<ch1<<' '<<repeat_alphabet[ch1]<<'\n';
//    }

    // map의 int 부분엔 해당 char가 등장한 인덱스를 넣을 것임
    for(int i=0;i< word.length();i++){
        if(repeat_alphabet[word[i]] == 200){
            repeat_alphabet[word[i]] = i;
        }
        else{
            if(i - repeat_alphabet[word[i]] > 1){
                return 0;
                //break;
            }
            else{
                repeat_alphabet[word[i]] = i;
            }
        }

    }
    return 1;

}

int main(){
    int n;
    int group_words=0;
    vector<string> words;

    //입력
    cin>>n;
    words.assign(n,{});
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    for(int i=0; i<n; i++){
        group_words +=groupChecker(words[i]);
    }
    cout<<group_words;

}