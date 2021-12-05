#include <iostream>
#include <fstream>
#include <vector>

int main()
   {
   std::string filename("day5.txt");
   std::ifstream input_file(filename);
   int max = 0, x1, x2, y1, y2;
   std::vector<std::pair<int, int>> points;
   bool considerDiagonals = true;
   while (input_file >> x1)
      {
      input_file.get(); // for the ','
      input_file >> y1;
      input_file.get(); input_file.get(); input_file.get(); input_file.get(); // for the ' -> '
      input_file >> x2;
      input_file.get(); // for the ','
      input_file >> y2;
      if (x1 > max)
         max = x1;
      if (x2 > max)
         max = x2;
      if (y1 > max)
         max = y1;
      if (y2 > max)
         max = y2;
      if (x1 == x2)
         {
         if (y1 > y2)
            std::swap(y1, y2);
         for (int i = y1; i <= y2; i++)
            points.push_back(std::make_pair(x1, i));
         }
      else if (y1 == y2)
         {
         if (x1 > x2)
            std::swap(x1, x2);
         for (int i = x1; i <= x2; i++)
            points.push_back(std::make_pair(i, y1));
         }
      else if (considerDiagonals) // for part 2
         {
         if (x1 > x2)
            {
            std::swap(x1, x2);
            std::swap(y1, y2);
            }
         bool increment_y = y1 <= y2;
         for (int i = x1; i <= x2; i++)
            points.push_back(std::make_pair(i, increment_y ? y1 + (i - x1) : y1 - (i - x1)));
         }
      }
   input_file.close();
   std::vector<std::vector<int>> frequency(max+1, std::vector<int>(max+1)); // default value is 0
   for (int i = 0; i < points.size(); i++)
      frequency[points[i].first][points[i].second]++;
   int score = 0;
   for (int i = 0; i <= max; i++)
      for (int j = 0; j <= max; j++)
         if (frequency[i][j] > 1)
            score++;
   std::cout << "Score: " << score << std::endl;
   return EXIT_SUCCESS;
   }
