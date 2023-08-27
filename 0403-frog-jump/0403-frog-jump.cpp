class Solution {
public:
    bool canCrossHelper(int currentPosition, vector<int> &stones, int lastJump, int totalStones, vector<vector<int>> &memo) {
        // Base case: If the current position is beyond the last stone, we cannot cross.
        if (currentPosition >= totalStones)
            return false;
        
        // If we've reached the last stone, we've successfully crossed.
        if (currentPosition == totalStones - 1)
            return true;

        // If the result for the current state is already computed, return it.
        if (memo[currentPosition][lastJump] != -1)
            return memo[currentPosition][lastJump];

        bool canCrossFlag = false;

        // Iterate through stones from the current position to explore possible jumps.
        for (int nextPosition = currentPosition + 1; nextPosition < totalStones; nextPosition++) {
            // Try different jump sizes, including one step less, current step, and one step more.
            for (int jumpSize = lastJump - 1; jumpSize <= lastJump + 1; jumpSize++) {
                // Check if the difference between the next stone's position and the current stone's position
                // matches the expected jump size. If so, recursively check if we can cross from the next stone.
                if (stones[nextPosition] - stones[currentPosition] == jumpSize)
                    canCrossFlag |= canCrossHelper(nextPosition, stones, jumpSize, totalStones, memo);
            }
        }

        // Store the result in the memoization table and return it.
        return memo[currentPosition][lastJump] = canCrossFlag;
    }

    bool canCross(vector<int>& stones) {
        int totalStones = stones.size();
        vector<vector<int>> memo(totalStones, vector<int>(totalStones, -1)); // Initialize memoization table.
        return canCrossHelper(0, stones, 0, totalStones, memo);
    }
};