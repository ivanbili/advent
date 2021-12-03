#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <bitset>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;
using std::bitset;

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
   vector<int> frequency;
   if (input_file >> curr_str)
      for (int i = 0; i < curr_str.size(); i++)
         if (curr_str[i] == '1')
            frequency.push_back(1);
         else
            frequency.push_back(-1);
   while (input_file >> curr_str)
      {
      for (int i = 0; i < curr_str.size(); i++)
         if (curr_str[i] == '1')
            frequency[i]++;
         else
            frequency[i]--;
      }
   input_file.close();
   int gamma = 0, epsilon = 0;
   for (int i = 0; i < frequency.size(); i++)
      {
      if (frequency[i] > 0)
         gamma+=1;
      else
         epsilon+=1;
      gamma<<=1;
      epsilon<<=1;
      }
   gamma>>=1;
   epsilon>>=1;
   int product = gamma*epsilon;
   cout << "Product: " << product << endl;
   return EXIT_SUCCESS;
   }
