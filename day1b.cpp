#include <iostream>
#include <fstream>
#include <climits>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;

int main()
   {
   string filename("day1.txt");
   ifstream input_file(filename);
   if (!input_file.is_open())
      {
      cerr << "Could not open the file - '" << filename << "'" << endl;
      return EXIT_FAILURE;
      }
   int count = 0, first, second, third, curr_number;
   if (input_file >> curr_number)
      first = curr_number;
   if (input_file >> curr_number)
      second = curr_number;
   if (input_file >> curr_number)
      third = curr_number;
   while (input_file >> curr_number)
      {
      //cout << "sum: " << first + second + third << endl;
      if (curr_number> first)
         count++;
      first = second;
      second = third;
      third = curr_number;
      //cout << "sum: " << first + second + third << endl;
      }
   input_file.close();
   cout << "Number of increases: " << count << endl;
   return EXIT_SUCCESS;
   }
