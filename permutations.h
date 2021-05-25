/**
 * Header file, for permutations library
 * Author: Nathan Pringle
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <chrono>

using namespace std;

//Loops over every index of every string and removes it, then stores the modified string. This gives us all the possible permutations of the countdown string of a given size
void shorter(vector<string>& strings_vec, int word_size, vector<string>& shortened_strings_vec);

//Will read in a dictionary file, and will only add words which start with letters from the countdown string
void hash_map(unordered_map<string, string>& hash_dictionary, ifstream &input, string str);

//Reads in a specified dictionary file, and calls another function to store words that start with a letter that is also in the countdown string
void dictionary_read(unordered_map<string, string>& hash_dictionary, string str, int word_size);

//Compares a given permutation with a given word from the dictionary file
bool comparison(vector<string>& strings_vec, unordered_map<string, string>& hash_dictionary);



