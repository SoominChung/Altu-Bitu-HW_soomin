//
// Created by kirin on 2021-10-19.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 비슷한 단어
/* 같은 구성 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐.
 * 2. 같은 문자는 같은 개수 만큼 있음.
 *
 * 비슷한 구성 조건
 * 1. 한 단어에서 한 문자 더하거나 빼거나
 * 2. 하나의 문자를 다른 문자로 바꾸어 나머지 한 단어랑 같은 구성 갖는 경우도!
 *
 * IN
 * 첫 줄 : 단어의 개수
 * 둘째 줄~ n번째 줄 : 각 단어 (100개 이하, 단어 길이는 10 이하)
 *
 * OUT
 * 첫 단어랑 비슷한 단어의 개수
 *
 */

int compareWord(string first, string cmp){ // 첫 번째 단어, 그와 비교할 단어들

    //각 알파벳 개수 세어줄 map
    map<char,int> first_alphabet; // 첫 단어의 알파벳 세어줌
    map<char,int> cmp_alphabet; // 두 번째 단어의 알파벳 세어줌
    for(char i='A'; i<='Z'; i++){ // 각 알파벳이 몇 번씩 나오는지
        cmp_alphabet[i]=0; // 따라서 처음에는 0으로 초기화
        first_alphabet[i]=0;
    }

    for(int i=0; i<first.length();i++){
        first_alphabet[first[i]] ++; //나온 알파벳의 숫자를 늘려준다.
    }

    for(int i=0; i<cmp.length();i++){
        cmp_alphabet[cmp[i]] ++;
    }

    int diff_count = 0; // 구성 다른 알파벳 개수 세기
    vector<int> check(2); int c_idx=0;// diff_count =2 일때 회생 가능한 경우인지 check
    for(int i='A'; i<='Z';i++){
        //cout<<i<<':'<<first_alphabet[i]<<' '<<cmp_alphabet[i]<<'\n';
        if(abs(first_alphabet[i]-cmp_alphabet[i])>=2){ //각 알파벳의 개수가 2개 이상 차이가 나면 무조건 안비슷한 단어
            return 0; // 비슷한 단어가 아니면 0을 return
        }
        if(abs(first_alphabet[i]-cmp_alphabet[i])==1){ // 1 차이나게 안비슷한 단어는 count해줌
            diff_count++;
            check[c_idx++] = first_alphabet[i]- cmp_alphabet[i]; //두 단어의 정확한 알파벳 개수 차이 담음
        }
        if(diff_count ==2){ //구성 다른 알파벳이 두 개 이상인 경우
            if((first.length() == cmp.length()) && (check[0]+check[1])==0 && i=='Z'){
                //만약 두 문자열의 길이가 같고, 두 알파벳의 차이가 -1, 1이면 하나의 알파벳을 대체하여 같게만들 수 있음
                return 1;
            }
            if(i=='Z')
                return 0;

        }
        if(diff_count>=3){
            return 0;
        }
    }

    return 1; // 비슷한 단어이면 1을 return

}

int main(){
    int n;

    //입력
    cin>>n;
    vector<string> words(n); //각 단어 담는 vector
    for(int i=0; i<n; i++){
        cin>>words[i];
    }

    //연산+출력
    int cnt=0;
    for(int i=1;i<n;i++){
        cnt += compareWord(words[0],words[i]);
    }

    cout<<cnt;

    return 0;
}