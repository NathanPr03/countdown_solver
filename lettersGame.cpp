#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;

void permute(string a, int current_letter_index, int end, vector<string> &a_permutations){
    //Base case
    if (current_letter_index == end){
        a_permutations.push_back(a);
    }else{
        //Permutations made
        for (int i = current_letter_index; i <= end; i++){
            //Swapping done
            swap(a[current_letter_index], a[i]);
 
            //Recursive call
            permute(a, current_letter_index+1, end, a_permutations);
 
            //Backtrack
            swap(a[current_letter_index], a[i]);
        }
    }
}

void shorten(vector<string> permuations, vector<string>& eightlongperms, int word_size){
    int shorten_by = 9 - word_size;
    for(auto a_permutation : permuations){
        for(int i=0; i<shorten_by; i++){
            a_permutation.erase(a_permutation.end()-1);
        }
        eightlongperms.push_back(a_permutation);
    }
}

void remove_duplicates(vector<string>& shorterperms){
    sort(shorterperms.begin(), shorterperms.end());
    shorterperms.erase(unique(shorterperms.begin(), shorterperms.end()), shorterperms.end());
}

void read_file(vector<string>& dictionary, string str, int word_size){
    
    string word;

    char str_one = str.at(0);
    char str_two = str.at(1);
    char str_three = str.at(2);
    char str_four = str.at(3);
    char str_five = str.at(4);
    char str_six = str.at(5);
    char str_seven = str.at(6);
    char str_eight = str.at(7);
    char str_nine = str.at(8);

    switch(word_size){
        case 9:{
            ifstream input("dictionary9.txt");
            if(input.is_open()){
                while(getline(input, word)){
                    if(word.at(0)==str_one || word.at(0)==str_two || word.at(0)==str_three || word.at(0)==str_four || word.at(0)==str_five || word.at(0)==str_six || word.at(0)==str_seven || word.at(0)==str_eight || word.at(0)==str_nine){
                        dictionary.push_back(word);
                    }
                }
            }
            break;
        }
        case 8:{
            ifstream input("dictionary8.txt");
            if(input.is_open()){
                while(getline(input, word)){
                    if(word.at(0)==str_one || word.at(0)==str_two || word.at(0)==str_three || word.at(0)==str_four || word.at(0)==str_five || word.at(0)==str_six || word.at(0)==str_seven || word.at(0)==str_eight || word.at(0)==str_nine){
                        dictionary.push_back(word);
                    }
                }
            }
            break;
        }
        case 7:{
            ifstream input("dictionary7.txt");
            if(input.is_open()){
                while(getline(input, word)){
                    if(word.at(0)==str_one || word.at(0)==str_two || word.at(0)==str_three || word.at(0)==str_four || word.at(0)==str_five || word.at(0)==str_six || word.at(0)==str_seven || word.at(0)==str_eight || word.at(0)==str_nine){
                        dictionary.push_back(word);
                    }
                }
            }
            break;
        }
        case 6:{
            ifstream input("dictionary6.txt");
            if(input.is_open()){
                while(getline(input, word)){
                    if(word.at(0)==str_one || word.at(0)==str_two || word.at(0)==str_three || word.at(0)==str_four || word.at(0)==str_five || word.at(0)==str_six || word.at(0)==str_seven || word.at(0)==str_eight || word.at(0)==str_nine){
                        dictionary.push_back(word);
                    }
                }
            }
            break;
        }
        case 5:{
            ifstream input("dictionary5.txt");
            if(input.is_open()){
                while(getline(input, word)){
                    if(word.at(0)==str_one || word.at(0)==str_two || word.at(0)==str_three || word.at(0)==str_four || word.at(0)==str_five || word.at(0)==str_six || word.at(0)==str_seven || word.at(0)==str_eight || word.at(0)==str_nine){
                        dictionary.push_back(word);
                    }
                }
            }
            break;
        }
        case 4:{
            ifstream input("dictionary4.txt");
            if(input.is_open()){
                while(getline(input, word)){
                    if(word.at(0)==str_one || word.at(0)==str_two || word.at(0)==str_three || word.at(0)==str_four || word.at(0)==str_five || word.at(0)==str_six || word.at(0)==str_seven || word.at(0)==str_eight || word.at(0)==str_nine){
                        dictionary.push_back(word);
                    }
                }
            }
            break;
        }
        case 3:{
            ifstream input("dictionary3.txt");
            if(input.is_open()){
                while(getline(input, word)){
                    if(word.at(0)==str_one || word.at(0)==str_two || word.at(0)==str_three || word.at(0)==str_four || word.at(0)==str_five || word.at(0)==str_six || word.at(0)==str_seven || word.at(0)==str_eight || word.at(0)==str_nine){
                        dictionary.push_back(word);
                    }
                }
            }
            break;
        }
    }
}

bool compare(vector<string> permutations, vector<string> shorterperms, vector<string> dictionary, int word_size){
    int upper_limit =dictionary.size();
    int lower_limit =0;
    char last_perm = 'a';
    unsigned int loop_count =0;
    if(word_size == 9){
        for(int i=0; i<permutations.size(); i++){
            if(permutations[i].at(0) != last_perm && i >1){
                lower_limit = upper_limit;
                upper_limit = dictionary.size();
            }
            for(int n=lower_limit; n<upper_limit; n++){
                loop_count ++;
                if(dictionary[n].at(0) > permutations[i].at(0)){
                    upper_limit = n;
                    break;
                }
                if (permutations[i] == dictionary[n]){
                    cout << permutations[i] << endl;
                    cout << "Loops count: " << loop_count << endl;
                    return true;
                }
            }
            last_perm = permutations[i].at(0);
        }
        cout << "Loops count: " << loop_count << endl;
        return false;
    }else{
        for(int i=0; i<shorterperms.size(); i++){
            if(shorterperms[i].at(0) != last_perm && i >1){
                lower_limit = upper_limit;
                upper_limit = dictionary.size();
            }
            for(int n=lower_limit; n<upper_limit; n++){
                loop_count ++;
                if(dictionary[n].at(0) > shorterperms[i].at(0)){
                    upper_limit = n;
                    break;
                }
                if (shorterperms[i] == dictionary[n]){
                    cout << shorterperms[i] << endl;
                    cout << "Loops count: " << loop_count << endl;
                    return true;
                }
            }
            last_perm = shorterperms[i].at(0);
        }
        cout << "Loops count: " << loop_count << endl;
        return false;
    }
    return false;
}

int main(){
    //Start measuring time
    auto begin = chrono::high_resolution_clock::now();
    string str = "ijbtdhaug";    

    int n = str.size();
    int word_size = 9;
    unsigned long int total_calcs =0;
    bool word_found =0;

    vector<string> permutations;
    vector<string> shorterperms;
    vector<string> dictionary;

    permute(str, 0, n-1, permutations); 
    std::cout << "Size of permutations vector: " << permutations.size() << endl;

    read_file(dictionary, str, word_size);
    std::cout << "Size of dictionary vector: " << dictionary.size() << endl;

    sort(permutations.begin(), permutations.end()); 
    std::cout << "Stage " << word_size << " started" << endl;

    total_calcs += permutations.size() * dictionary.size();
    if(compare(permutations, shorterperms, dictionary, word_size)){
    }else while(word_found == false){
        word_size--;
        std::cout << "Stage " << word_size << " started" << endl;

        dictionary.clear();
        shorterperms.clear();

        shorten(permutations, shorterperms, word_size);
        remove_duplicates(shorterperms);
        
        std::cout << "Size of permutations vector: " << shorterperms.size() << endl;
        read_file(dictionary, str, word_size);
        std::cout << "Size of dictionary vector: " << dictionary.size() << endl;
        total_calcs += shorterperms.size() * dictionary.size();
        sort(shorterperms.begin(), shorterperms.end());
        if(compare(permutations, shorterperms, dictionary, word_size)){
            word_found = true;
        }
    }
    
    //Stop measuring time and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::seconds>(end - begin);

    std::cout << "This program ran in: " << elapsed.count() << " seconds" << endl;
    std::cout << "Total number of calculations: " << total_calcs << endl;

    return 0;
}