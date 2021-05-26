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
    string str;
    cout << "Please enter the letters: ";
    cin >> str;

    //Input validation
    while(str.length() != 9){
        cout << "Please make sure you enter 9 letters" << endl;
        cout << "Please enter the letters: ";
        cin >> str;
    }
    
    
    //Start measuring time
    auto begin = chrono::high_resolution_clock::now();

    int word_size = 9;
    bool word_found =0;

    vector<string> strings_vec; //Stores the current string(s) that we are going to shortened
    vector<string> shortened_strings_vec; //Stores the current string(s) that we are comparing against the dictionary

    /**
     * Stores a given dictionary file in a hash-map
     * Stores a given word as the data 
     * Stores a given word, sorted alphabetically, as the ID 
     */
    unordered_map<string, string> hash_dictionary;       
    
    shortened_strings_vec.push_back(str);

    //Loops while we havent found a word and are looking for a word thats at least 3 letters long
    while(word_found == false && word_size>=3){
        cout << "Looking for " << word_size << " letter words!" << endl;
        dictionary_read(hash_dictionary, str, word_size);

        if(comparison(shortened_strings_vec, hash_dictionary)){
            word_found = true;
        }
        
        word_size--;

        strings_vec = shortened_strings_vec; //Sets the new strings that we want to shorten

        shortened_strings_vec.clear();
        hash_dictionary.clear();

        shorter(strings_vec, word_size, shortened_strings_vec);
    }
    
    //Stop measuring time and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "This program ran in: " << elapsed.count() << " milliseconds" << endl;

    return 0;
}