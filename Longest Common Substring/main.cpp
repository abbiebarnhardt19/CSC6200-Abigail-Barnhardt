#include "Longest Common Substring.h"
#include <array>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string string_one = "ABAB";
    string string_two = "BABA";

    longestCommonSubstring(string_one, string_two);
    
    return 0;
}
