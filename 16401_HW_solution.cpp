//
// Created by kirin on 2021-10-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//과자 나눠주기
/**
* M명의 조카에게 젤 길고 동일한 길이의 막대 과자 나눠주기 (과자 N개)
 * 과자는 여러 조각으로 나눠질 수 있음.
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left : 과자 길이의 최솟값 -> 1
 * right : 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 미리 해주면 좋음
*/

int childNum(vector<int> & snacks, int len){
    int cnt = 0; //몇 명에게 나누어주는지
    for(int i=snacks.size()-1; i>=0; i--){ //가장 긴 과자부터 검사
        if(snacks[i] < len){ //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break;
        }
        cnt += (snacks[i]/len); // i번째 과자를 len길이로 나눈다면 몇 명에게 줄 수 있을지
    }

    return cnt;
}

int upperSearch(vector<int> &snacks, int left, int right, int target){
    int ans= 0;
    while(left <= right){ //left가 right의 오른쪽을 넘지 않을 동안
        int mid = (left+right)/2; //과자의 길이
        int cnt = childNum(snacks, mid); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if(cnt >= target){ //target(m)보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid+1; //찾는 숫자가 커졌으므로 left를 오른쪽으로 옮긴다
            ans = mid; //제일 근접한 답은 mid
        }else{
            right = mid -1; //해당 길이로는 m명의 아이들 모두에게 나눠줄 수 없으므로 과자 길이를 줄인다.
        }
    }

    return ans;
}

int main(){
    int m,n,left=1,right=0;

    //입력
    cin>>m>>n;
    vector<int> snacks(n,0);
    for(int i=0; i<n; i++){
        cin >> snacks[i];
    }

    //연산
    sort(snacks.begin(), snacks.end()); //과자 크기 순으로 정렬
    right = snacks[n-1]; // 오른쪽 맨 끝 값이 제일 긴 과자 길이

    //연산 + 출력
    cout << upperSearch(snacks, left, right, m); //target:m (아이들 수)

    return 0;
}
