#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
using namespace std;
using namespace filesystem;

struct Country{
  string name;
  int marks[20];
  int points;
};

void do_the_stuff(ifstream &current_file);
int number(ifstream &current_file);
string word_before_comma(string &word);
Country work_with_line(string current_line);
void points_adder();
void sort_last_time();
void write_in_file(ofstream &result_file);


vector <Country> countries;

int main()
{
  ifstream current_file;
  ofstream result_file;
  string path;
  cout << "Please, enter the directory path:" << endl;
  cin >> path;
  result_file.open(path + "result.csv");
  vector <string> file_names;
  for (const auto & entry : directory_iterator(path))
    if (entry.path().extension() == ".csv"){
      file_names.push_back(entry.path().string());
    }
  for (size_t i = 0; i < file_names.size(); i++) {
    current_file.open(file_names[i]);
    if (!current_file.is_open()) {
      cout << "File isn't open!" << endl;
    }
    do_the_stuff(current_file);
    current_file.close();
  }
  points_adder();
  sort_last_time();
  write_in_file(result_file);
  result_file.close();
}

// функция, которая делает всю работу xD
void do_the_stuff(ifstream &current_file){
  int numb = number(current_file);
  string current_line;
  for (size_t i = 0; i < numb; i++) {
    getline(current_file, current_line);
    countries.push_back(work_with_line(current_line));
  }
}

//функция, которая возвращает слово, разделенное запятой
string word_before_comma(string &word) {
    int pos = word.find(",");
    string subword = word.substr(0, pos);
    word = word.substr(pos+1);
    return subword;
}

// функция6 возвращающая инфу про страну
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

// функция, добавляющая очки странам
void points_adder(){
  int points[] = {12, 10, 8, 7, 6, 5, 4, 3, 2, 1};
  for (size_t i = 0; i < countries.size(); i++) {
    for (size_t j = 0; j < countries.size() - 1; j++) {
      for (size_t k = 0; k < countries.size() - 1; k++) {
        if (countries[k].marks[i] < countries[k+1].marks[i]) {
          swap(countries[k], countries[k+1]);
        }
      }

    }
    for (size_t l = 0; l < 10; l++) {
      countries[l].points += points[l];
    }
  }
}

// функция сортирующая страны по набраным очкам
void sort_last_time(){
  for (size_t i = 0; i < countries.size(); i++) {
    for (size_t j = 0; j < countries.size() - 1; j++) {
      if (countries[j].points < countries[j+1].points) {
        swap(countries[j], countries[j+1]);
      }
    }
  }
}

// функция, которая возвращает кол-во стран
int number(ifstream &current_file){
  string str;
  getline(current_file, str);
  return stoi(str);
}

//функция записи в файл
void write_in_file(ofstream &result_file){
  for (size_t i = 0; i < 10; i++) {
    result_file << i+1 << "," << countries[i].name << "," << countries[i].points << endl;
  }
}
