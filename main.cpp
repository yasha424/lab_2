#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
using namespace std;
using namespace filesystem;


int main()
{
  ifstream currFile;
  string path;
  getline(cin, path);
  vector <string> files;
  for (const auto & entry : directory_iterator(path))
    if (entry.path().extension() == ".csv"){
      //cout << entry.path() << endl;
      files.push_back(entry.path());
    }
  for (size_t i = 0; i < files.size(); i++) {
    currFile.open(files[i]);
    if (!currFile.is_open()) {
      cout << "File isn't open!" << endl;
    }
  }
}
