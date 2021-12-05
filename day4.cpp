#include <iostream>
#include <fstream>
#include <climits>
#include <vector>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;
using std::move;

void markNumber(vector<vector<vector<int>>> & matrices, int num)
   {
   for (int i = 0; i < matrices.size(); i++)
      for (int j = 0; j < matrices[0].size(); j++)
         for (int k = 0; k < matrices[0][0].size(); k++)
            if (matrices[i][j][k] == num)
               matrices[i][j][k] = -num;
   }

bool isWinner(vector<vector<int>> & matrix)
   {
   for (int i = 0; i < matrix.size(); i++)
      {
      bool win = true;
      for (int j = 0; win && j < matrix[0].size(); j++)
         if (matrix[i][j] >= 0)
            win = false;
      if (win)
         return true;
      }
    for (int i = 0; i < matrix[0].size(); i++)
      {
      bool win = true;
      for (int j = 0; win && j < matrix.size(); j++)
         if (matrix[j][i] >= 0)
            win = false;
      if (win)
         return true;
      }     
   return false;
   }

int computeSum(vector<vector<int>> & matrix)
   {
   int score = 0;
   for (int i = 0; i < matrix.size(); i++)
      for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[i][j] > 0)
               score += matrix[i][j];
   return score;
   }

int main()
   {
   string filename("day4.txt");
   ifstream input_file(filename);
   if (!input_file.is_open())
      {
      cerr << "Could not open the file - '" << filename << "'" << endl;
      return EXIT_FAILURE;
      }
   unsigned long depth = 0, x = 0, aim = 0;
   int curr_num;
   vector<int> nums;
   while (input_file >> curr_num)
      {
      nums.push_back(curr_num);
      if (input_file.peek() == ',')
         input_file.get();
      else
         break;
      }
   vector<vector<vector<int>>> matrices;
   vector<int> curr_row;
   vector<vector<int>> curr_matrix;
   int col_elements = INT_MAX;
   while (input_file >> curr_num)
      {
      curr_row.push_back(curr_num);
      if (input_file.peek() == ' ')
         input_file.get();
      else
         {
         if (col_elements == INT_MAX)
            col_elements = curr_row.size();
         if (curr_matrix.size() == col_elements)
            {
            matrices.push_back(curr_matrix);
            curr_matrix.clear();
            }
         curr_matrix.push_back(curr_row);
         curr_row.clear();
         }
      }
   matrices.push_back(curr_matrix);
   input_file.close();
   int score = 0;
   vector<bool> in_play(matrices.size(), true);
   vector<int> scores;
   for (int i = 0; i < nums.size(); i++)
      {
      for (int j = 0; j < matrices.size(); j++)
         markNumber(matrices, nums[i]);
      for (int j = 0; j < matrices.size(); j++)
         if (in_play[j] && isWinner(matrices[j]))
            {
            scores.push_back(computeSum(matrices[j])*nums[i]);
            in_play[j] = false;
            }
      }
   cout << "First board score: " << scores[0] << endl;
   cout << "Last board score: " << scores[scores.size()-1] << endl;
   return EXIT_FAILURE;
   }
