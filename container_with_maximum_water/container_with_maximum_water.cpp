// container_with_maximum_water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//Brute force approach
/*class Solution {
public:
    int maxArea(vector<int>& height) {
        //Brute force approach
        if (height.size() <= 1)
            return 0;

        int max_area = INT_MIN;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int length = 0, width = 0, area = 0;
                if (height[i] < height[j])
                    length = height[i];
                else
                    length = height[j];

                width = j - i;
                area = length * width;
                if (max_area < area)
                    max_area = area;
            }
        }

        return max_area;
    }
};*/

//Optimal Solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;

        int max_area = 0;
        size_t i = 0;
        size_t j = height.size() - 1;

       
        while (i < j)
        {
            int length = 0, width = 0, area = 0;
            if (height[i] < height[j])
                length = height[i];
            else
                length = height[j];

            width = j - i;
            area = length * width;

            if (max_area < area)
                max_area = area;

            if (height[j] < height[i])
                j--;
            else
                i++;
        }

        return max_area;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = { 1,8,6,2,5,4,8,3,7 };
    std::cout << sol.maxArea(heights);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
