// TestStringCons.cpp

#include "stringConstruction.h"
#include <iostream>
#include <vector>

struct Testcase {
    std::string target;
    int appendCost;
    int cloneCost;
    int bestCost;

    std::string notes;
};

// Overload for << operator to print the Testcase
std::ostream& operator<<(std::ostream& os, const Testcase& tc) {
    os << "  Target: " << tc.target << "\n";
    os << "  Append Cost: " << tc.appendCost << "\n";
    os << "  Clone Cost: " << tc.cloneCost << "\n";
    os << "  Best Cost: " << tc.bestCost << "\n";
    os << "  Notes: " << tc.notes << "\n";
    return os;
}

int main() {
    int retval = 0;

    std::vector<Testcase> testcases{
        {"aa", 1, 2, 2, "    Append 'a' (cost 1), append 'a' (cost 1)"},
        {"aaaa", 2, 3, 7, "    Append 'a' (cost 2), append 'a' (cost 2), clone 'aa' (cost 3)"},
        {"xzxpzxzxpq", 10, 11, 71, "    Append 'x' (cost 10), Append 'z' (cost 10), Append 'x' (cost 10), Append 'p' (cost 10), Append 'z' (cost 10),\n    Clone 'xzxp' (cost 11), Append 'q' (cost 10)"}
    };

    for (size_t i = 0; i < testcases.size(); ++i) {
        std::cout << "Testcase " << i << "\n";
        std::cout << testcases[i];
        std::cout << "\nRunning your function\n";

        int costWas = stringConstruction(testcases[i].target, testcases[i].cloneCost, testcases[i].appendCost);

        if (costWas == testcases[i].bestCost) {
            std::cout << " -- Test passed, correct cost was returned\n\n\n";
        } else {
            std::cout << " -- Test failed, incorrect cost of " << costWas << " was returned\n";
            std::cout << "    To help your debugging, the cheapest way to make the string should be:\n";
            std::cout << testcases[i].notes << "\n\n\n";

            ++retval;
        }
    }

    std::string bigString = "abcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipiblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcntdblgblgmbaipobacjodblgblgmbaiabcblgmbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcqaipfdmbcntdblgblgmbaipmbcntdblgblgmbaiprtifbcntdblgblgmbaipmbcntdblgblgmbaipfdmbcntdblgblgmbaipmbcntdblgblgmbaipcbcnt";
    std::cout << "\nBig target string testcase, using a " << bigString.size() << " character test string.  An excellent solution will complete in around a hundredth of a second.\n";
    std::cout << "(Note -- if the program freezes at this point, Ctrl+C will stop it from running)\n";
    int bigCost = stringConstruction(bigString, 10, 11);
    if (bigCost == 59249) {
        std::cout << "-- Test passed, correct cost was returned\n\n";
    } else {
        std::cout << "-- Incorrect cost of " << bigCost << " returned, rather than 59249\n\n";
        ++retval;
    }

    return retval;
}
