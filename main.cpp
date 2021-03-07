#include "lib.h"


int main()
{

  vector <Country> countries;

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
    do_the_stuff(current_file, countries);
    current_file.close();
  }
  points_adder(countries);
  sort_struct(countries);
  write_in_file(result_file, countries);
  result_file.close();
}

// функция, которая делает всю работу xD
