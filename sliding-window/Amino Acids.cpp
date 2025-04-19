/**
In molecular biology, proteins are composed of chains of amino acids, represented by a sequence of letters, where each letter 
corresponds to one of the 20 standard amino acids (e.g., 'A' for Alanine, 'C' for Cysteine, 'D' for Aspartic Acid, etc.). 
For simplicity, we represent an amino acid sequence as a string composed of uppercase letters from 'A' to 'Z', though in 
practice, only a subset of letters is used.

When studying proteins, identifying repeated motifs (short subsequences of amino acids) is crucial for understanding protein 
structure, function, and potential binding sites. A motif is considered significant if it appears multiple times in the sequence, 
indicating a possible functional or structural role.

Given a string s that represents an amino acid sequence, return all the 8-letter-long subsequences that occur more than once 
in the sequence. The output should be a list of these repeated motifs, and you may return the answer in any order. 
Additionally, to ensure biological relevance, ignore any motif that contains the character 'X' (often used as a placeholder for 
unknown amino acids).

Example 1
Input: s = "ASPARTICACIDASPARTICACI"
Output: ["ASPARTIC", "SPARTICA", "PARTICAC", "ARTICACI"]

Explanation: The following 8-letter sequences appear twice:
"ASPARTIC" (positions 1-8 and 13-20)
"SPARTICA" (positions 2-9 and 14-21)
"PARTICAC" (positions 3-10 and 15-22)
"ARTICACI" (positions 4-11 and 16-23) 
No other 8-letter sequences repeat, and none contain 'X'.

Example 2
Input: s = "LEUCINEXLEUCINEXLEUCINEX"
Output: []

Explanation: Repeated 8-letter subsequence: "LEUCINEX" (appears multiple times, contains 'X') so we exclude it from output.
No other 8-letter subsequences repeat without 'X'.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solve(string s) {
    vector<string> output;
    unordered_map<string, int> map;
    
    for (int i = 0; i <= s.size() - 8; i++) {
        map[s.substr(i, 8)]++;
    }
    
    for (auto entry : map) {
        if (entry.second > 1 && entry.first.find('X') == string::npo) {
            output.push_back(entry.first);
        }
    }
    
    return output;
}

int main() {
    string s = "ASPARTICACIDASPARTICACI";
    
    vector<string> output = solve(s);
    
    for (string o : output) {
        cout << o << endl;
    }
    
    return 0;
}
