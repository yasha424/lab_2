#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;
namespace fs = std::filesystem;

struct Country{
  string name;
  int marks[20];
  int points;
};

void do_the_stuff(ifstream &current_file);
int number(ifstream &current_file);
string word_before_comma(string &word);
Country work_with_line(string current_line);
void sort();
void cout_all_struct();
void sort_last_time();
void write_in_file(ofstream &result_file);


vector <Country> countries;

int main()
{
  ifstream current_file;
  ofstream result_file;
  string path;
  cin >> path;
  result_file.open(path + "result.csv");
  vector <string> file_names;
  for (const auto & entry : fs::directory_iterator(path))
    if (entry.path().extension() == ".csv"){
      //cout << entry.path() << endl;
      file_names.push_back(entry.path());
    }
  for (size_t i = 0; i < file_names.size(); i++) {
    current_file.open(file_names[i]);
    if (!current_file.is_open()) {
      cout << "File isn't open!" << endl;
    }
    do_the_stuff(current_file);
    current_file.close();
  }
  sort();
  sort_last_time();
  cout_all_struct();
  write_in_file(result_file);
}

void do_the_stuff(ifstream &current_file){
  int numb = number(current_file);
  string current_line;
  for (size_t i = 0; i < numb; i++) {
    getline(current_file, current_line);
    //cout << str << endl;
    // string country_name = current_line.substr(0, current_line.find(','));
    // cout << country_name << endl;
    countries.push_back(work_with_line(current_line));
  }
}
string word_before_comma(string &word) {
    int pos = word.find(",");
    string subword = word.substr(0, pos);
    word = word.substr(pos+1);
    return subword;
}
Country work_with_line(string current_line) {
    Country currCountry;
    currCountry.name = word_before_comma(current_line);
    currCountry.points = 0;
    for (int i = 0; i < 20; i++) {
        string word = word_before_comma(current_line);
        currCountry.marks[i] = atoi(word.c_str());
    }
    return currCountry;
}
void sort(){
  int points[] = {12, 10, 8, 7, 6, 5, 4, 3, 2, 1};
  for (size_t i = 0; i < countries.size(); i++) {
    for (size_t j = 0; j < countries.size() - 1; j++) {
      for (size_t k = 0; k < countries.size() - 1; k++) {
        if (countries[k].marks[i] < countries[k+1].marks[i]) {
          swap(countries[k], countries[k+1]);
        }
      }

    }
    // cout << i << endl;
    // cout_all_struct();
    for (size_t l = 0; l < 10; l++) {
      countries[l].points += points[l];
    }
  }
}

void sort_last_time(){
  for (size_t i = 0; i < countries.size(); i++) {
    for (size_t j = 0; j < countries.size() - 1; j++) {
      if (countries[j].points < countries[j+1].points) {
        swap(countries[j], countries[j+1]);
      }
    }
  }
}

int number(ifstream &current_file){
  string str;
  getline(current_file, str);
  return stoi(str);
}

void cout_all_struct(){
  for (size_t i = 0; i < countries.size(); i++) {
    cout << countries[i].name << "  " << countries[i].points << endl;
  }
}

void write_in_file(ofstream &result_file){
  for (size_t i = 0; i < 10; i++) {
    result_file << countries[i].name << "," << countries[i].points << endl;
  }
}
