#include "Programmers.h"
#include <algorithm>

int Level3::BullsAndCows::solution(int n) const
{
    // prepare all candidates
    std::vector<int> candidates = std::vector<int>();
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            if (i != j) {
                for (int k = 1; k < 10; ++k) {
                    if ((j != k) && (i != k)) {
                        for (int l = 1; l < 10; ++l) {
                            if ((i != l) && (j != l) && (k != l)) {
                                int candidate = 1000 * i + 100 * j + 10 * k + 1 * l;
                                candidates.push_back(candidate);
                            }
                        }
                    }
                }
            }
        }
    }

    // repeat up to n times
    for (int i = 0; i < n; ++i) {
        // try using front candidate
        std::string result = submit(candidates.front());

        // if 4 strike, return it
        if (result == "4S 0B") {
            break;
        }

        // parse strike & ball count
        int strike = result[0] - '0';
        int ball = result[3] - '0';

        // review each candidates with current results
        candidates = ReviewCandidates(candidates, strike, ball);

        // if only one candidate was remained, return it
        if (candidates.size() == 1) {
            break;
        }
    }

    return candidates.front();
}

std::string Level3::BullsAndCows::submit(int num) const
{
    int strike = 0;
    int ball = 0;
    std::string str = std::to_string(num);
    for (int i = 0; i < answer.size(); ++i) {
        if (answer[i] == str[i]) {
            ++strike;
        }
        else if (answer.find(str[i]) != -1) {
            ++ball;
        }
    }
    std::string result = { (char)(strike + '0'), 'S', ' ', (char)(ball + '0'), 'B' };
    return result;
}

std::vector<int> Level3::BullsAndCows::ReviewCandidates(const std::vector<int>& candidates, const int& strike, const int& ball) const
{
    // get the number attempted
    std::string attempt = std::to_string(candidates.front());

    // alternative vector
    std::vector<int> filteredCandidates;
    filteredCandidates.reserve(candidates.size() / 2);

    for (const int element : candidates) {
        int s = 0;
        int b = 0;
        std::string candidate = std::to_string(element);

        // check all candidates' strike & ball with the number attempted
        for (int i = 0; i < candidate.length(); ++i) {
            // check the number attempted contain each number
            if (candidate[i] == attempt[i]) {
                ++s;
            }
            else if (attempt.find(candidate[i]) != -1) {
                ++b;
            }
        }

        // select candidate which has same value on the number of strike & ball with the number attempted
        if ((strike == s) && (ball == b)) {
            filteredCandidates.push_back(element);
        }
    }

    return filteredCandidates;
}

std::string Level3::SealedSpell::solution(long long n, std::vector<std::string> bans)
{
    std::sort(bans.begin(), bans.end(), SpellComparer);

    for (std::string banSpell : bans) {
        long long banIndex = SpellToIndex(banSpell);
        if (banIndex <= n) {
            ++n;
        }
    }

    std::string answer = IndexToSpell(n);
    return answer;
}

bool Level3::SealedSpell::SpellComparer(const std::string& lhs, const std::string& rhs)
{
    if (lhs.length() == rhs.length()) {
        return lhs < rhs;
    }
    else {
        if (lhs.length() < rhs.length()) {
            return true;
        }
        else {
            return false;
        }
    }
}

long long Level3::SealedSpell::SpellToIndex(std::string spell) const
{
    int length = spell.length();

    long long index = 0;
    long long quot = 1;

    for (int i = length - 1; i >= 0; --i) {
        int rem = spell[i] - 'a';
        index += quot * (rem + 1);
        quot *= 26;
    }

    return index;
}

std::string Level3::SealedSpell::IndexToSpell(long long n) const
{
    std::string spell;

    while (n > 0) {
        --n;
        lldiv_t div = std::div(n, 26ll);
        spell += 'a' + div.rem;
        n = div.quot;
    }
    std::reverse(spell.begin(), spell.end());

    return spell;
}
