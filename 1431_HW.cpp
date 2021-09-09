//
// Created by kirin on 2021-09-09.
//

//다솜이 기타

//하나의 예제는 괜찮았는데 어디가 문제인지 모르겠습니다 ㅠㅠ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(const string &s1, const string &s2){
    if(s1.length() != s2.length()){
        return s1.length() < s2.length();
    }
    //아스키 코드로 비교하기 위해서 string to char
    char s1_serial_char[s1.length()];
    char s2_serial_char[s2.length()];
    strcpy(s1_serial_char, s1.c_str());
    strcpy(s2_serial_char, s2.c_str());

    int s1_sum=0; int s2_sum=0;
    for(int i=0; i<s1.length();i++){
        if(48<=s1_serial_char[i]<=57){ //isDigit
            int tmp = s1_serial_char[i]-'0';
            s1_sum += tmp;
        }
    }
    for(int i=0; i<s2.length();i++){
        if(48<=s2_serial_char[i]<=57){
            int tmp = s2_serial_char[i]-'0';
            s2_sum += tmp;
        }
    }
    if(s1_sum != s2_sum){
        if(s1_sum < s2_sum){
            return 0;
        }
        else{
            return 1;
        }
    }
    return !(s1.compare(s2));
}

int main(){
    int n;
    vector<string> guitar;
    //입력
    cin>>n;
    guitar.assign(n,{});
    for(int i=0; i<n; i++){
        cin>>guitar[i];
    }

    //연산
    sort(guitar.begin(),guitar.end(),cmp);

    //출력
    for(int i=0; i<n; i++){
        cout<<guitar[i]<<'\n';
    }

}