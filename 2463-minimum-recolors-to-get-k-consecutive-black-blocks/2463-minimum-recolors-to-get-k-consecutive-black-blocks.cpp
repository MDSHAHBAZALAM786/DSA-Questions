class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minRecolor = k; 
        int whiteCount = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }
        minRecolor = whiteCount;

        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') whiteCount--;  
            if (blocks[i] == 'W') whiteCount++;      

            minRecolor = min(minRecolor, whiteCount);
        }

        return minRecolor;
    }
};
