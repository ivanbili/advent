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
   int prev_number = INT_MAX, curr_number, count = 0;
   while (input_file >> curr_number)
      {
      if (curr_number > prev_number)
         count++;
      prev_number = curr_number;
      }
   input_file.close();
   cout << "Number of increases: " << count << endl;
   return EXIT_SUCCESS;
   }
