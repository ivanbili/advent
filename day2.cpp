#include <iostream>
#include <fstream>
#include <climits>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;

int main()
   {
   string filename("day2.txt");
   ifstream input_file(filename);
   if (!input_file.is_open())
      {
      cerr << "Could not open the file - '" << filename << "'" << endl;
      return EXIT_FAILURE;
      }
   unsigned long depth = 0, x = 0, aim = 0;
   string curr_str;
   unsigned int curr_num;
   while (input_file >> curr_str && input_file >> curr_num)
      {
      if (curr_str == "down")
         aim+=curr_num;
      else if (curr_str == "up")
         aim-=curr_num;
      else if (curr_str == "forward")
         {
         x+=curr_num;
         depth+=aim*curr_num;
         }
      }
   input_file.close();
   cout << "Product: " << depth*x << endl;
   return EXIT_SUCCESS;
   }
