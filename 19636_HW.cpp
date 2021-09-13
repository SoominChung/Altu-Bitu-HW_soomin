//
// Created by kirin on 2021-09-13.
//

//요요 시뮬레이션

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <tuple>

using namespace std;

int noConsiderDefaultConsumeDiet(int W0,int I0,int T,int D,int I,int A){
    int default_consume,energy_output,dW,W;

    default_consume = I0; //기초 대사량 고려 안하는 버전이라 다이어트 전과 동일
    energy_output = default_consume + A; // 에너지 소비량
    dW = I-energy_output; //체중 변화 : 에너지 섭취량 - 에너지 소비량
    W = W0 + D*dW; // D일 동안 dW만큼 매일 변화하면 W가 됨

    if(W<=0){
        return -1;
    }
    else{
        return W;
    }
}

tuple<int,int> ConsiderDefaultConsumeDiet(int W0,int I0,int T,int D,int I,int A){
    int default_consume,energy_output,dW;
    int W= W0;

    default_consume = I0; //기초 대사량 우선 I0로 초기화
    for(int i=0; i<D; i++){
        energy_output = default_consume+A; // 에너지 소비량
        dW  = I-energy_output; //체중 변화 : 에너지 섭취량 - 에너지 소비량
        W += dW; //D일 동안 매일 체중 변화량이 달라질 것이므로
        if(abs(dW) > T){
            if(dW<0){
                default_consume += floor(dW/2)-1;
            }
            else{
                default_consume += floor(dW/2);
            }
        }
    }

    if(W<=0 || default_consume<=0){
        return tuple<int,int>(-1,-1);
    }
    else{
        return tuple<int,int>(W, default_consume);
    }
}

string predictYOYO(int default_consume,int energy_input,int A0){
    int result; // 다이어트 마친 후 기존 활동량, 섭취량 & 변화한 기초대사량일 때 요요 올지
    result = energy_input - (A0+default_consume);
    if(result>0){
        return "YOYO";
    }
    else{
        return "NO";
    }
}

int main(){
    int W0, I0, T, D, I, A;
    int A0 = 0; //운동을 안함
    int default_consume, energy_input, energy_output;
    tuple<int,int> result; // Consider Default는 tuple이 return 되므로 출력에 필요

    //입력
    cin>>W0>>I0>>T;
    //cout<<'\n';
    cin>>D>>I>>A;
    //cout<<'\n';

    //첫 번째 줄 출력 ( 기초대사량 변화 고려 않는 경우 )
    if(noConsiderDefaultConsumeDiet(W0,I0,T,D,I,A) == -1){
        cout<<"Danger Diet"<<'\n';
    }
    else{
        cout<<noConsiderDefaultConsumeDiet(W0,I0,T,D,I,A)<<' '<<I0<<'\n';
    }

    //두 번째 줄 출력 ( 기초대사량 변화 고려 경우 )
    result = ConsiderDefaultConsumeDiet(W0,I0,T,D,I,A);
    if(get<0>(result) == -1){
        cout<<"Danger Diet";
        cout<<'\n';
    }
    else{
        cout<<get<0>(result)<<' '<<get<1>(result)<<' ';
        cout<<predictYOYO(get<1>(result),I0,A0);
        cout<<'\n';
    }

}