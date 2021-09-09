//
// Created by kirin on 2021-09-09.
//

//보물찾기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int makeS(vector<int> A, vector<int> B, int n){
    long long int S=0;

    //vector<int> AxB;
    //AxB.assign(n,0);

    vector<int> sortedB;
    sortedB.assign(n,0);
    for(int i=0; i<n; i++){
        sortedB[i]= B[i];
    }
    sort(A.begin(),A.end());
    sort(sortedB.begin(),sortedB.end());

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ //이렇게 되면 B 중복될 경우에 여러번 돈다ㅠ
            if(B[i]==sortedB[j]){
                S += A[n-1-j]*B[i];
                cout<<S<<'\n';
            }
        }
    }

    return S;
}

int main(){
    int n;
    long long S;
    vector<int> A;
    vector<int> B;

    //입력
//    cin>>n;
    n= 50;
    A.assign(n,0);
    B.assign(n,0);

    for(int i=0; i<n; i++){
        //cin>>A[i];
        A[i] = 1;
    }
    for(int i=0; i<n; i++){
        //cin>>B[i];
        B[i] = 100;
    }

    //연산
    S = makeS(A,B,n);

    //출력
    cout<<S;

}
