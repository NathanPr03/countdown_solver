/**
 * Implementation file for permutations library
 * Author: Nathan Pringle
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

#include "permutations.h"

using namespace std;

/**
 * Loops over every index of every string and removes it, then stores the modified string. This gives us all the possible permutations of the countdown string of a given size
 * @param strings_vec The vector used to store the strings we want to shorten
 * @param word_size The current size of word we are looking for
 * @param shortened_strings_vec The vector that stores the shortened strings
 */
void shorter(vector<string>& strings_vec, int word_size, vector<string>& shortened_strings_vec){
    for(string word : strings_vec){
        for(int i=0; i<=word.size(); i++){
            string str2 = word;
            str2.erase(str2.end()-i);
            if(str2.length() == word_size){
                shortened_strings_vec.push_back(str2);
            }
        }
    }
}

/**
 * Will read in a dictionary file, and will only add words which start with letters from the countdown string
 * @param hash_dictionary A hash-map that stores the current dictionary file (the word as the data, and the word, sorted alphabetically as the ID)
 * @param input The input file which dictates what dictionary to use
 * @param str The string of letters from the countdown game
 */
void hash_map(unordered_map<string, string>& hash_dictionary, ifstream &input, string str){
    string word;
    if(input.is_open()){
        while(getline(input, word)){
            if(word.at(0)==str.at(0) || word.at(0)==str.at(1) || word.at(0)==str.at(2) || word.at(0)==str.at(3) || word.at(0)==str.at(4) || word.at(0)==str.at(5) || word.at(0)==str.at(6) || word.at(0)==str.at(7) || word.at(0)==str.at(8)){
                string word_sorted = word;
                sort(word_sorted.begin(), word_sorted.end());
                hash_dictionary.insert({word, word_sorted});
            }
        }
    }
}
/**
 * Reads in a specified dictionary file, and calls another function to store words that start with a letter that is also in the countdown string
 * @param hash_dictionary A hash-map that stores the current dictionary file (the word as the data, and the word, sorted alphabetically as the ID)
 * @param str The string of letters from the countdown game
 * @param word_size The current size of word we are looking for
 */ 
void dictionary_read(unordered_map<string, string>& hash_dictionary, string str, int word_size){
    //word_size will dictate which dictionary file we read in, as they are split by length
    switch(word_size){
        case 9:{
            ifstream input("dictionary9.txt");
            hash_map(hash_dictionary, input,str);
            break;
        }
        case 8:{
            ifstream input("dictionary8.txt");
            hash_map(hash_dictionary, input, str);
            break;
        }
        case 7:{
            ifstream input("dictionary7.txt");
            hash_map(hash_dictionary, input, str);
            break;
        }
        case 6:{
            ifstream input("dictionary6.txt");
            hash_map(hash_dictionary, input, str);
            break;
        }
        case 5:{
            ifstream input("dictionary5.txt");
            hash_map(hash_dictionary, input, str);
            break;
        }
        case 4:{
            ifstream input("dictionary4.txt");
            hash_map(hash_dictionary, input, str);
            break;
        }
        case 3:{
            ifstream input("dictionary3.txt");
            hash_map(hash_dictionary, input, str);
            break;
        }
    }   
}

/**
 * Compares a given permutation with a given word from the dictionary file
 * @param shortened_strings_vec The vector that stores the shortened strings
 * @param hash_dictionary A hash-map that stores the current dictionary file (the word as the data, and the word, sorted alphabetically as the ID)
 */
bool comparison(vector<string>& shortened_strings_vec, unordered_map<string, string>& hash_dictionary){
    for(auto perm : shortened_strings_vec){
        sort(perm.begin(), perm.end());
        for(auto word : hash_dictionary){
            if(perm == word.second){
                cout << "The longest word we could find is: " << word.first << "!"  << endl;
                return true;
            }      
        } 
    }
    return false;   
}