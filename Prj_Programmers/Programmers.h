#pragma once
#include <string>
#include <vector>

namespace Level3 {
    /// <summary>
    /// https://school.programmers.co.kr/learn/courses/30/lessons/451808
    /// </summary>
    class BullsAndCows {
    public:
        std::string answer = "9157";

        int solution(int n) const;
    private:
        std::string submit(int num) const;

        std::vector<int> ReviewCandidates(const std::vector<int>& candidates, const int& strike, const int& ball) const;
    };

    /// <summary>
    /// https://school.programmers.co.kr/learn/courses/30/lessons/389481
    /// </summary>
    class SealedSpell {
    public:
        std::string solution(long long n, std::vector<std::string> bans);

    private:
        static bool SpellComparer(const std::string& lhs, const std::string& rhs);

        long long SpellToIndex(std::string spell) const;
        std::string IndexToSpell(long long n) const;
    };
}
