#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> factors(int target_number){ 
    vector<int> factors_vec;
    for(int i=1; i<target_number/2; i++){
        if(target_number % i == 0){
            factors_vec.push_back(i);
        }
    }
    return factors_vec;
}

int main(){
    int target_number = 100;
    int variable_numbers[] = {1,2,4,50,75};
    vector<int> factors_vec;
    factors_vec = factors(target_number);
    for(auto i : factors_vec){
        cout << i << endl;
    }
}