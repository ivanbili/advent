#include <iostream>
#include <fstream>
#include <deque>

int main()
   {
   std::string filename("day6.txt");
   std::ifstream input_file(filename);
   std::deque<unsigned long long> fish(9); // default value is 0
   unsigned long long curr_num, total = 0;
   while (input_file >> curr_num)
      {
      input_file.get(); // for the ','
      fish[curr_num]++;
      }
   input_file.close();
   const int max_days = 256; // or 80 for part 1
   for (int i = 0; i < max_days; i++)
      {
      unsigned long long old_day0 = fish.front();
      fish.pop_front();
      fish.push_back(old_day0);
      fish[6]+=old_day0;      
      }
   for (int i = 0; i < 9; i++)
      total+=fish[i];
   std::cout << "Total after "<< max_days <<" days: " << total << std::endl;
   return EXIT_SUCCESS;
   }