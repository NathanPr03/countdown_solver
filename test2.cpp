#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(vector<double>& list, int answer, vector<int>& operators, vector<string>& operator_strings) {
    if(operators.size() + 1 < list.size()) {
        for(int i = 0; i < 4; i++) {
            operators.push_back(i);
            solve(list, answer, operators, operator_strings);
            operators.pop_back();
        }
        return;
    }
    double intermediate = list[0];
    for(int i = 0; i < operators.size(); i++) {
        switch(operators[i]) {
            case 0:
                intermediate += list[i+1];
                break;
            case 1:
                intermediate -= list[i+1];
                break;
            case 2:
                intermediate *= list[i+1];
                break;
            case 3:
                if(list[i+1] == 0) return;
                intermediate /= list[i+1];
                break;
        }
    }
    if(abs(intermediate - answer) < .00000001) {
        cout << "\t" << list[0];
        for(int i = 0; i < operators.size(); i++)
            cout << operator_strings[operators[i]] << list[i+1];
        cout << " = " << answer << endl;
    }
}

int main() {
    vector<string> operator_strings = {" + ", " - ", " * ", " / "};
    int answer;
    while(true) {
        vector<double> list;
        vector<int> operators;
        for(int i = 0; i < 6; i++) {
            int x;
            cin >> x;
            list.push_back((double)x);
        }
        cin >> answer;
        sort(list.begin(), list.end());
        do {
            solve(list, answer, operators, operator_strings);
        } while(next_permutation(list.begin(), list.end()));
    }
    return 0;
}