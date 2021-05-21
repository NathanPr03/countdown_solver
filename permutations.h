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

void permute(string a, int current_letter_index, int end, vector<string> &a_permutations);

void shorten(vector<string> permuations, vector<string>& eightlongperms, int word_size);

void remove_duplicates(vector<string>& shorterperms);

void shorter(string str, int word_size, vector<string>& shortened_sorted_string);

void dictionary_read(unordered_map<string, string>& hash_dictionary, string str, int word_size, vector<string> dictionary);

bool comparison(vector<string>& strings_vec, unordered_map<string, string>& hash_dictionary);

void read_file(vector<string>& dictionary, string str, int word_size);

bool compare(vector<string> shorterperms, vector<string> dictionary, int word_size);
