#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<char> stack; // Use a stack to help with decoding
    string decoded = "";

    for (int i = 0; i < s.length(); i++) {
        // wait for the string until you see ']'
        if (s[i] == ']') {
            string temp = "";
            while (!stack.empty() && stack.top() != '[') {
                temp = stack.top() + temp;
                stack.pop();
            }
            stack.pop(); // Pop '['

          // Initialize variables for number k and base.
         int k = 0;     // This will store the integer value before '['.
         int base = 1;  // Base is used to calculate the actual value of k.

        // Iterate through characters in the stack while they are digits.
        while (!stack.empty() && isdigit(stack.top())) {
            // For this example, let's assume the stack contains '3' from "3[a2[bc]]".
        
            // Calculate k:
            // - 'stack.top() - '0'' converts the character '3' to the integer 3.
            // - Then, multiply it by the current base (which starts at 1).
            // - Add the result to k. Initially, k = 0, so k += 3 * 1 = 3.
            k += (stack.top() - '0') * base;
        
            // Pop the processed digit from the stack.
            stack.pop();
        
            // Update the base by multiplying it by 10 to handle multi-digit numbers.
            // For the next digit, it will be 10, and for the digit after that, 100, and so on.
            base *= 10;
        
            // Continue this process until a non-digit character is encountered.
            // In our example, after processing '3', 'a' is encountered, which is not a digit.
        }


            // Repeat the temp string k times and push it back onto the stack
            for (int j = 0; j < k; j++) {
                for (char ch : temp) {
                    stack.push(ch);
                }
            }
        } else {
            stack.push(s[i]); // Push characters onto the stack
        }
    }

    while (!stack.empty()) {
        decoded = stack.top() + decoded;
        stack.pop();
    }

    return decoded;
}

int main() {
    string s = "3[a]2[bc]";
    string decoded = decodeString(s);
    
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
