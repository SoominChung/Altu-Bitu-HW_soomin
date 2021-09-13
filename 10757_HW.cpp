//
// Created by kirin on 2021-09-13.
//

// big A+B

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeArray(string str, vector<int> arr){ //str로 받은 입력을 반대 방향으로 int array에 넣는다
    for(int i=0;i<str.length();i++){
        int tmp = str[str.length()-i-1] - '0';
        arr[i] = tmp;
    }
    return arr;
}

int main(){
    string strA,strB;
    vector<int> A,B,sum;

    // 더할 두 수 입력
    cin>>strA>>strB; //정수 범위가 너무 커서 string으로 받고 int로 변환할 것

    int max_length = max(strA.length(),strB.length());
    // 둘 중 더 큰 숫자 길이만큼 array 크기를 할당해야 각 자리 수 더할 때 오류 없지

    A.assign(max_length,0);
    B.assign(max_length,0);
    sum.assign(max_length+1,0); // 합의 경우 한 자리 더 늘어날 수 있으므로

    A = makeArray(strA,A);
    B = makeArray(strB,B);

    for(int i=0; i<sum.size()-1; i++){
        sum[i]+= A[i]+B[i]; //제일 처음 숫자가 1의 자리 숫자. 이후로 점점 커짐
        if(sum[i]>=10){
            sum[i] = sum[i]-10; //각 숫자 더한 게 10보다 클 경우에 윗 자리로 올리고 해당 자리는 10 빼줌
            sum[i+1] +=1;
        }
    }

    if(sum[sum.size()-1]==0){ //맨 끝 자리는 두 자리 더했을 때 max size보다 커질 경우를 대비한 것이므로 안커지면 0 없애
        for(int i=1; i<sum.size();i++){
            cout<<sum[sum.size()-i-1];
        }
    }
    else{
        for(int i=0; i<sum.size(); i++){
            cout<<sum[sum.size()-i-1];
        }

    }

}