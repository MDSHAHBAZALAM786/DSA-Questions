class Solution {
public:
    int romanToInt(string s) {
        int total = 0, prevValue = 0;

        for (char ch : s) {
            int currValue = getValue(ch);

            // If current value is greater than previous, adjust for subtraction cases
            if (currValue > prevValue) {
                total += (currValue - 2 * prevValue);  // Undo previous addition
            } else {
                total += currValue;
            }

            prevValue = currValue;
        }

        return total;
    }

private:
    int getValue(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // Handle unexpected cases
        }
    }
};
