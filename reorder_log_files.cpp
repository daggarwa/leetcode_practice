#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, ans;
        vector<pair<string, string>> letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1));
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin(), letterLogs.end(), [&](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for (auto &p : letterLogs) ans.push_back(p.first + " " + p.second);
        for (string &s : digitLogs) ans.push_back(s);
        return ans;
}

int main() {
  std::cout << "Hello World!\n";
  vector<string> logs {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
  reorderLogFiles(logs);
}

