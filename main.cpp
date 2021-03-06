#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
using namespace std;
using namespace filesystem;
void do_the_stuff(ifstream &current_file);
int number(ifstream &current_file);
void sort();

struct Country{
  string name;
  int marks[20];
  int points;
};

vector <Country> countries;

int main()
{
  ifstream current_file;
  ofstream result_file;
  string path;
  cin >> path;
  result_file.open(path + "result.csv");
  vector <string> file_names;
  for (const auto & entry : directory_iterator(path))
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

Country work_with_line(string current_line){
  // сюда надо шо-то пихнуть
}

void sort(){
  int points[] = {12, 10, 8, 7, 6, 5, 4, 3, 2, 1};
  for (size_t i = 0; i < countries.size(); i++) {
    for (size_t j = 0; j < countries.size() - 1; j++) {
      for (size_t k = 0; k < countries.size() - 1; k++) {
        if (countries[i].marks[k] < countries[i].marks[k+1]) {
          swap(countries[i].marks[k], countries[i].marks[k+1]);
        }
      }
    }
    for (size_t i = 0; i < 10; i++) {
      countries[j].points += points[i];
    }
  }
}

int number(ifstream &current_file){
  string str;
  getline(current_file, str);
  return stoi(str);
}
