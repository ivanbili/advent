#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <bitset>
#include <unordered_set>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;
using std::bitset; using std::unordered_set;
using std::stoi;

int main()
   {
   string filename("day3.txt");
   ifstream input_file(filename);
   if (!input_file.is_open())
      {
      cerr << "Could not open the file - '" << filename << "'" << endl;
      return EXIT_FAILURE;
      }
   unsigned long depth = 0, x = 0, aim = 0;
   string curr_str;
   unordered_set<string> oxygen;
   unordered_set<string> co2;
   while (input_file >> curr_str)
      {
      oxygen.insert(curr_str);
      co2.insert(curr_str);
      }
   input_file.close();
   int ind = 0;
   while (oxygen.size() > 1)
      {
      int freq = 0;
      for (auto it = oxygen.begin(); it != oxygen.end(); it++)
         if ((*it)[ind] == '1')
            freq++;
         else
            freq--;
      for (auto it = oxygen.begin(); it != oxygen.end(); )
         if ((*it)[ind] == '0' && freq >= 0)
            it = oxygen.erase(it);
         else if ((*it)[ind] == '1' && freq < 0)
            it = oxygen.erase(it);
         else
            it++;
      ind++;
      }
   ind = 0;
   while (co2.size() > 1)
      {
      int freq = 0;
      for (auto it = co2.begin(); it != co2.end(); it++)
         if ((*it)[ind] == '1')
            freq++;
         else
            freq--;
      for (auto it = co2.begin(); it != co2.end(); )
         if ((*it)[ind] == '0' && freq < 0)
            it = co2.erase(it);
         else if ((*it)[ind] == '1' && freq >= 0)
            it = co2.erase(it);
         else
            it++;
      ind++;
      }
   cout << "Product: " << stoi(*oxygen.begin(), nullptr, 2) * stoi(*co2.begin(), nullptr, 2) << endl;
   return EXIT_SUCCESS;
   }
