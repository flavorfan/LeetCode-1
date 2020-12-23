/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0 || matrix[0].size() == 0 )
            return false;

        auto row_s = matrix.begin(), row_e = matrix.end();
        while (row_s < row_e){
            auto mid = row_s + ((row_e - row_s) >> 1);
            // cout << row_s - matrix.begin()  << " " << row_e - matrix.begin() << " " << mid - matrix.begin() << endl;
            if ((*mid)[0] < target) {
                row_s = mid + 1;
            }else if ((*mid)[0] == target){
                return true;
            }else{
                row_e = mid;
            }
        }

        if (row_s == matrix.begin()) 
            return false;
        else {
            auto row = row_s - 1;
            auto col_s = (*row).begin(), col_e = (*row).end();
            while (col_s < col_e){
                auto col_m = col_s + ((col_e - col_s) >> 1);
                if (*col_m < target) {
                    col_s = col_m + 1;
                }else if (*col_m == target){
                    return true;
                }else{
                    col_e = col_m;
                }
            }
        }
        return false;
    }
};
// @lc code=end

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>> &m, int t) {
        // pointless edge case we still have to consider
		if (!m.size() || !m[0].size()) return false;
        // support variables
		int row, l = 0, r = m.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            // moving l up if needed
            if (m[mid].back() < t) l = mid + 1;
            // moving r down if needed
            else if (m[mid][0] > t) r = mid - 1;
            // we found our row!
            else {
                l = mid;
                break;
            };
        }
        // storing the value of the new found row
        row = l;
        // resetting l and r to run a binary search on the rows
        l = 0;
        r = m[0].size() - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            // moving l up if needed
            if (m[row][mid] < t) l = mid + 1;
            // moving r down if needed
            else if (m[row][mid] > t) r = mid - 1;
            // we found our value!
            else return true;
        }
        return false;
    }
};

TEST(Test, case1)
{
    Solution s;

    vector<vector<int>> matrix = {{1,3,5,7}, {10, 11, 16, 20}, {23, 30, 34, 60}};


    // EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.searchMatrix(matrix, 3), true );
}

TEST(Test, case2)
{
    Solution s;

    vector<vector<int>> matrix = {{}};


    // EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.searchMatrix(matrix, 1), false );
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

/*


*/