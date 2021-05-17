/**
 * Implementation file for permutations library
 * Author: Nathan Pringle
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <chrono>
#include "permutations.h"
using namespace std;

/**
 * Takes a string and returns are possible permutations of it
 * 
 * @param str The string of letters from the countdown game
 * @param current_letter_index The index of the current letter you are working on from the string
 * @param permutations The vector used to store all possible permuations of the string
 */
void permute(string str, int current_letter_index, int end, vector<string> &permutations){
    //Base case
    if (current_letter_index == end){
        permutations.push_back(str);
    }else{
        //Permutations made
        for (int i = current_letter_index; i <= end; i++){
            //Swapping done
            swap(str[current_letter_index], str[i]);
 
            //Recursive call
            permute(str, current_letter_index+1, end, permutations);
 
            //Backtrack
            swap(str[current_letter_index], str[i]);
        }
    }
}

/**
 * Takes each string from the permutations vector and shortens it (removes the last character) by a specified size
 * 
 * @param permutations The vector used to store all possible permuations of the string
 * @param shorter_perms The vector that stores the shortened strings
 * @param word_size The current size of word we are looking for
 */
void shorten(vector<string> permuations, vector<string>& shorterperms, int word_size){
    int shorten_by = 9 - word_size;
    //Loops for each permutation and removes a specified amount off the end
    for(auto perm : permuations){
        for(int i=0; i<shorten_by; i++){
            perm.erase(perm.end()-1);
        }
        shorterperms.push_back(perm);
    }
}
/**
 * Removes the duplicates from the vector, also sorts the vector in alphabetical order
 * 
 * @param shorterperms The vector that stores the shortened strings
 */
void remove_duplicates(vector<string>& shorterperms){
    sort(shorterperms.begin(), shorterperms.end());
    shorterperms.erase(unique(shorterperms.begin(), shorterperms.end()), shorterperms.end());
}

/**
 * Will read in a dictionary file, and will only add words which start with letters from the countdown string
 * 
 * @param dictionary A vector that stores the current dictionary file
 * @param input The input file which dictates what dictionary to use
 * @param str The string of letters from the countdown game
 */
void letter_exists(vector<string>& dictionary, ifstream &input, string word, string str){
    if(input.is_open()){
        while(getline(input, word)){
            if(word.at(0)==str.at(0) || word.at(0)==str.at(1) || word.at(0)==str.at(2) || word.at(0)==str.at(3) || word.at(0)==str.at(4) || word.at(0)==str.at(5) || word.at(0)==str.at(6) || word.at(0)==str.at(7) || word.at(0)==str.at(8)){
                dictionary.push_back(word);
            }
        }
    }
}
/**
 * Reads in a specified dictionary file, and calls u another function to store words that start with a letter that is also in the countdown string
 * 
 * @param dictionary A vector that stores the current dictionary file
 * @param str The string of letters from the countdown game
 * @param word_size The current size of word we are looking for
 */ 
void read_file(vector<string>& dictionary, string str, int word_size){
    string word;

    //word_size wil dictate which dictionary file we read in, as they are split by length
    switch(word_size){
        case 9:{
            ifstream input("dictionary9.txt");
            letter_exists(dictionary, input, word, str);
            break;
        }
        case 8:{
            ifstream input("dictionary8.txt");
            letter_exists(dictionary, input, word, str);
            break;
        }
        case 7:{
            ifstream input("dictionary7.txt");
            letter_exists(dictionary, input, word, str);
            break;
        }
        case 6:{
            ifstream input("dictionary6.txt");
            letter_exists(dictionary, input, word, str);
            break;
        }
        case 5:{
            ifstream input("dictionary5.txt");
            letter_exists(dictionary, input, word, str);
            break;
        }
        case 4:{
            ifstream input("dictionary4.txt");
            letter_exists(dictionary, input, word, str);
            break;
        }
        case 3:{
            ifstream input("dictionary3.txt");
            letter_exists(dictionary, input, word, str);
            break;
        }
    }
}

/**
 * Compares a given permutation with a given word from the dictionary file
 * 
 * @param shorterperms The vector that stores the shortened strings
 * @param dictionary A vector that stores the current dictionary file
 * @param word_size The current size of word we are looking for
 */
bool compare(vector<string> shorterperms, vector<string> dictionary, int word_size){
    int upper_limit =dictionary.size();
    int lower_limit =0;
    int letter_search =0;

    char last_perm = 'a';

    //Loops over every permutation, optimised to only check permutations against words that start with the same letter
    for(int i=0; i<shorterperms.size(); i++){
        //If the first letter of the current perm doesnt match the first letter of the last permutation set the lower limit and reset upper limit
        if(shorterperms[i].at(0) != last_perm && i >1){
            lower_limit = upper_limit;
            upper_limit = dictionary.size();
        }
        //Loops for words in the dictionary that start with the same letter
        for(int n=lower_limit; n<upper_limit; n++){
            //If the first letter from the word in the dictionary is greater than that of the permutation, it means the permutation can no longer be in the dictionary.
            //All other permutations that start with the same letter can also be ruled out
            if(dictionary[n].at(0) > shorterperms[i].at(0)){
                letter_search = 0;
                upper_limit = n;
                break;
            }
            if (shorterperms[i] == dictionary[n]){
                cout << "The longest word we could find is: " << shorterperms[i] << endl;
                return true;
            }
        }
        last_perm = shorterperms[i].at(0);
    }
    return false;
}