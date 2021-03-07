#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include "lib.cpp"
using namespace std;
using namespace filesystem;


void do_the_stuff(ifstream &current_file, vector <Country> &countries);
int number(ifstream &current_file);
string word_before_comma(string &word);
Country work_with_line(string current_line);
void points_adder(vector <Country> &countries);
void sort_struct(vector <Country> &countries);
void write_in_file(ofstream &result_file, vector <Country> &countries);
