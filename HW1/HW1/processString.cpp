#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <gtest\gtest.h>

using namespace std;


// getAscendingStr Function requirement
//
// Take space seperated digit string (ex. "1 2 3 5 4") and 
//   modify input string to ascending order ("1 2 3 4 5").
//
// return 0 if success, (empty string)
//       -1 if exception occur (ex. string containing non-digit character)
int getAscendingStr(string& inputStr)
{
	
	/// Please fill your code here
	string take;
	string number;
	string ans;
	string temp1;
	int current;
	int count = 0;
	int total = inputStr.length();
	
	int i,j;
	int min_pos;
	int min_num;
	int temp;
	int position;
	int flag = 0;
	for (i = 0; i != total+1; i++)
	{
		temp1 = inputStr[i];
		
		
		if (int(*(temp1.c_str())) >= 48 && int(*(temp1.c_str())) <= 57|| int(*(temp1.c_str()))==45)
		{
			number.push_back(inputStr[i]);
		}
		else if (int(*(temp1.c_str())) == 32||i==total)
		{
			current = atoi(number.c_str());
			
			
			if (ans.empty() == 1)
			{
				ans.append(number);
				ans.append(" ");
				number.clear();
			}
			else
			{
				for (int j = 0; j != ans.length(); j++)
				{
					temp1 = ans[j];
					if (int(*(temp1.c_str())) >= 48 && int(*(temp1.c_str())) <= 57 || int(*(temp1.c_str())) == 45)
						take.push_back(ans[j]);
					else
					{
						
						if (current < atoi(take.c_str()))
						{
							number.append(" ");
							position = ans.find(take);
							ans.insert(position, number);
							flag = 1;
							break;
						}
						take.clear();
					}

				}
				if (flag != 1)
				{
					number.append(" ");
					ans.append(number);
				}
				
			}
			number.clear();
			take.clear();
			flag = 0;
		}
		else
			return -1;
	}





	
	inputStr.clear();
	inputStr.append(ans);
	inputStr.pop_back();
	return 0;
}

// solveQ Function requirement
// 
// solve quadratic function ax^2 + bx + c = 0
//
// return 1 if equation has two different real number root 
//          (return vector size should be 2 containing 2 solution.  
//          Greater value should put into smaller vector index)
//        0 there is only one possible solution to the quadratic equation 
//          (return vector size should be 1)
//       -1 complex roots 
//          (return vector size should be 0)
int solveQ(vector<double> &x, double a, double b, double c)
{
	if (b*b - 4 * a*c > 0)
	{
		double x1= (-1 * b + sqrt(b*b - 4 * a*c)) / (a * 2);
		double x2= (-1 * b - sqrt(b*b - 4 * a*c))/ (a * 2);
		x.push_back(x1);
		x.push_back(x2);
		
		
		return 1;
	}
	else if (b*b - 4 * a*c == 0)
	{
		double x1 = (-1 * b + sqrt(b*b - 4 * a*c)) / (a * 2);
		x.push_back(x1);
		return 0;
	}
	else
		return -1;
	return 0;
}

int main(int argc, char*argv[]) {
	
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

TEST(getAscendingStr, SimpleAscending)
{//Simple ascending test case
	string inputStr = "1 3 2 4 5";
	string tmpStr = inputStr;
	getAscendingStr(tmpStr);
	EXPECT_EQ(tmpStr, "1 2 3 4 5");
}

TEST(getAscendingStr, handleNonDigit)
{//getAscendingStr function should handle non digit case
	string tmpStr = "1 3 2 4 a";
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(err, -1);
}

TEST(solveQ, twoSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 2, -3);
	EXPECT_EQ(iSol, 1);
	EXPECT_EQ(sol.size(), 2);
	EXPECT_EQ(sol.at(0), 1);
	EXPECT_EQ(sol.at(1), -3);
}

TEST(solveQ, oneSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, -8, 16);
	EXPECT_EQ(iSol, 0);
	EXPECT_EQ(sol.size(), 1);
	EXPECT_EQ(sol.at(0), 4);
}

TEST(solveQ, noSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 1, 16);
	EXPECT_EQ(iSol, -1);
	EXPECT_EQ(sol.size(), 0);
}