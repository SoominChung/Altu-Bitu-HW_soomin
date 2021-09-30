//
// Created by kirin on 2021-09-28.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; //양수의 최댓값

// 통계학
// 입력: N개의 숫자 (N: 1~500,000, 각 숫자: abs(4000)이하)
// 산술평균, 중앙값, 최빈값, 범위 출력

/**
* 1. 산술평균 계산 시 실수 자료형으로 맞춰준 후 반올림하는 거 주의
 * 2. n은 홀수이므로 중앙값은 항상 (n/2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값
 * 4. 최빈값이 유일하게 하나만 있는 경우 고려
*/

// mode를 계산해주는 함수
int calcMode(vector<int> &frequency){
    int max_value = 0; // 최빈값의 빈도수
    for(int i=0; i<=SIZE*2; i++){ // 최빈값의 빈도수 구하기
        if(frequency[i] > max_value){ // max_value에 저장해놓은 값보다 큰 값 나오면
            max_value = frequency[i]; // 대체하기
        }
    }
    //두 번째로 작은 최빈값 구하기
    int cnt = 0; //최빈값 개수
    int mode = 0;
    for(int i=0; i<=SIZE*2; i++){
        if(frequency[i] == max_value){ // 최빈값이 두 개 이상 있으면
            mode = i - SIZE; // SIZE를 더한 값으로 인덱스에 저장했으므로 실제 숫자는 SIZE 뺀 값
            cnt++;
            if(cnt == 2){ // 두 번째로 작은 최빈값 -> sort 했으므로 굳이 복잡하게 sort 고민 필요 없이 이렇게만 해주면 됐다..
                break;
            }
        }
    }

    return mode;
}

int main(){
    int n; //n은 홀수

    //입력
    cin>>n;

    vector<int> num(n); // 입력될 n개의 숫자 vector에 저장
    vector<int> frequency(SIZE*2+1,0); // 인덱스는 입력수+4000의 값. (음수도 존재하니까)
    // 따라서 0~8000에 각 수 얼마나 나왔는지 저장
    // frequency 어떻게 만들어야할지 vector<pair>, map 다 사용해봤는데 abs4000정도의 값이니 그냥 vector 8000으로 만들어도 넉넉했음ㅠ
    // 이것이 브루트포스구나,,

    double sum = 0; // 평균 구하기 위한 합 변수
    for(int i=0; i<n; i++){
        cin>> num[i]; // num array에 입력 받음
        sum += (double) num[i]; // 입력 받은 숫자 sum에 더해줌. 소숫점 두째자리 까지 나타내기 위해 double로 변환
        frequency[num[i] + SIZE ]++; // 해당 숫자의 빈도 frequency에서 올려줌
    }

    //연산
    sort(num.begin(),num.end()); // 중앙값 연산을 위한 sort

    //출력
    cout << round(sum / n) << '\n'; // 얘는 굳이 함수 만들 필요 없이 그냥 바로 계산해도 됐네
    cout << num[n/2] << '\n'; // 중앙값은 num sort했으니 n/2 idx 자리에 있다
    cout << calcMode(frequency) << '\n'; // mode 구하기
    cout << num[num.size() -1] - num[0] << '\n'; // sort 했으므로 맨 끝 값이 max, 맨 앞 값이 min

    return 0;
}