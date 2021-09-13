//
// Created by kirin on 2021-09-13.
//

//듣보잡

#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<string,int> name_number; //각 이름이 몇 번 나왔는지 정보를 담은 map
//vector<vector<pair<string,int>>> name_number;

int main(){

    vector<string> no_listen; //듣지 못한 사람 이름 vector
    vector<string> no_see; //보지 못한 사람 이름 vector

    int n,m;

    //입력
    cin>>n>>m;

    for(int i=0; i<n;i++){
        cin>>no_listen[i];
    }
    for(int i=0; i<m; i++){
        cin>>no_see[i];
    }

    //연산
    for(int i=0; i<no_listen.size();i++){
        name_number[no_listen[i]]=1;
    }
    for(int i=0; i<no_see.size();i++){
        if(name_number[no_see[i]]==1){
            name_number[no_see[i]] =2;
        }
        else{
            name_number[no_see[i]] = 1;
        }
    }
    for (auto it = name_number.begin(); it != name_number.end(); ++it) {
        cout << it->first;
        cout << '\n';
        if (it->second == 2) {
            cout << it->first;
        }
    }
}