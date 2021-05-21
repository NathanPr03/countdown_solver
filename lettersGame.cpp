/**
 * A program which will solve the letters game from the popular TV show Countdown
 * Author: Nathan Pringle
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include "permutations.h"

using namespace std;

int main(){
    //ofstream output("outputfile.txt");
    //ofstream output2("outputfile2.txt");
    string str;
    cout << "Please enter the letters: ";
    cin >> str;

    //Start measuring time
    auto begin = chrono::high_resolution_clock::now();

    int n = str.size();
    int word_size = 9;
    bool word_found =0;

    vector<string> permutations;
    vector<string> shorterperms;
    vector<string> dictionary;

    vector<string> strings_vec;
    unordered_map<string, string> hash_dictionary;

    strings_vec.push_back(str);
    while(word_found == false && word_size>0){
        cout << "Looking for " << word_size << " letter words!" << endl;
        dictionary_read(hash_dictionary, str, word_size, dictionary);

        if(comparison(strings_vec, hash_dictionary)){
            word_found = true;
        }
        hash_dictionary.clear();
        strings_vec.clear();

        word_size--;
        shorter(str, word_size, strings_vec);
    }
    
    /**
    //permute(str, 0, n-1, permutations); 
    
    //sort(permutations.begin(), permutations.end()); 

    read_file(dictionary, str, word_size);
    
    while(word_found == false){
        cout << "Starting stage " << word_size << "!" << endl;
        shorten(permutations, shorterperms, word_size);
        remove_duplicates(shorterperms);
        
        read_file(dictionary, str, word_size);

        if(compare(shorterperms, dictionary, word_size)){
            word_found = true;
        }
        word_size--;

        dictionary.clear();
        shorterperms.clear();
    }
    */
    //Stop measuring time and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::seconds>(end - begin);

    std::cout << "This program ran in: " << elapsed.count() << " seconds" << endl;
    return 0;
}