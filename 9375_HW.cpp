//
// Created by kirin on 2021-09-13.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int MAX_SIZE = 30;

int main(){
    int test_case,n;
    string cloth, category;
    vector<vector<pair<string,string>>> clothes;
    clothes.assign(MAX_SIZE, vector<pair<string,string>>);

    //in
    cin>> test_case;
    for(int i=0; i<test_case;i++){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>cloth>>category;
            clothes[category].push_back(cloth);
        }
    }

}