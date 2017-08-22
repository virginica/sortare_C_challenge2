

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
void function_vector (vector<string> &v);
int n;


bool CompareStringCaseInsensitive(const string& c1,const string& c2){

   string::size_type common_length = std::min(c1.length(),c2.length());

   for(string::size_type i=0;i<common_length;++i){
      if(toupper(c1[i]) < toupper(c2[i]))return true;
      if(toupper(c1[i]) > toupper(c2[i]))return false;
   }

   if(c1.length()<c2.length())return true;
   if(c1.length()>c2.length())return false;//can ignore

   return false;//equal should return false
}

int main()
{
    vector<string> database;
    function_vector(database);
    sort(database.begin(), database.end(),CompareStringCaseInsensitive);
     ofstream myfile ("database_sortata.txt");
     n=database.size();
     if (myfile.is_open())
    for(int i = 0; i < n; i++)
    {
           myfile << database[i]<<endl;
        }
     myfile.close();
    
    return 0;
}

void function_vector(vector<string> &v)
{
   ifstream file;
   file.open ("2.names");
   if (!file.is_open()) return;
    std::string line;
   while (getline(file, line)) {
    v.push_back(line);
   }
   file.close();
}

