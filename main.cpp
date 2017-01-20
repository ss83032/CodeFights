#include <iostream>
#include <vector>
#include <map>

using namespace std;

int threeSplit(std::vector<int> a);
int sequenceElement(std::vector<int> a, int n);
int sequenceElement_ByCF(std::vector<int> a, int n);

int main(int argc, char** argv) {
    // cout << "threeSplit=" << threeSplit({-1, 0, -1, 0, -1, 0}) << endl;
    // cout << sequenceElement({1, 2, 3, 4, 5}, 9) << endl;
    // cout << sequenceElement_ByCF({1, 2, 3, 4, 5}, 9) << endl;
    return 0;
}

std::string myConcat(std::vector<std::string> arguments, std::string separator) {
    std::string concatenate = "";
    std::vector<std::string>::iterator it;

    for (it = arguments.begin(); it < arguments.end(); it++) {
        concatenate.append((*it).append(separator));
    }

    return concatenate;
}

// Description: Given a list of fractions find the index of the largest one (0-based).
// Input: numerators = [5, 2, 5] and denominators = [6, 3, 4]
// Output: maxFraction(numerators, denominators) = 2
int maxFraction(std::vector<int> numerators, std::vector<int> denominators) {
    int index = 0;
    for (int i = 1; i < numerators.size(); i++) {
        if (numerators[i] * denominators[index] > numerators[index] * denominators[i]) {
            index = i;
        }
    }
    return index;
}

// Description: Determine if a number can be expressed as a sum of some consecutive positive integers.
// Input: n = 9
// Output: isSumOfConsecutive(n) = true, in the following way: 2 + 3 + 4 = 9
bool isSumOfConsecutive(int n) {
  for (int start = 1; start < n; start++) {
    int number = n,
        subtrahend = start;
    while (number > 0) {
      number -= subtrahend;
      subtrahend++;
    }
    if (!number) {
      return true;
    }
  }
  return false;
}

// Description: Find out if the given matrix is skew-symmetric.
// Input: matrix = [[0, 0, 1], [0, 0, -2], [-1, 2, 0]]
// Output: isSkewSymmetricMatrix(matrix) = true
bool isSkewSymmetricMatrix(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] + matrix[j][i] != 0) {
                return false;
            }
        }
    }
    return true;
}

// Description: Given integers a and b, determine whether the following pseudocode results in an infinite loop.
// Input: a = 2, b = 3
// Output: isInfiniteProcess(a, b) = true
bool isInfiniteProcess(int a, int b) {
    return a > b ? true : (a - b) % 2 != 0;
    // return (!(a <= b && ((b-a) % 2) == 0));
}

// Description: Given an integer, find the sum of all its digits, EX: 111 => 1 + 1 + 1 = 3.
// Input: n = 111
// Output: digitSum(n) = 3
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int digitSum_ByCF(int n) {
    if(n == 0)
        return 0;
    else
        return n % 10 + digitSum(n / 10);
}

int threeSplit(std::vector<int> a) {
    long long need = 0;

    for (int i = 0; i < a.size(); i++) {
        need += a[i];
    }

    need /= 3;

    int ans = 0;
    int firstPoints = 0;
    long long curSum = a[0];

    for (int i = 1; i < (int)a.size() - 1; i++) {
        curSum += a[i];
        if (curSum == need) {
            firstPoints++;
        }
        if (curSum == 2 * need) {
            ans += firstPoints;
            if (need == 0) {
                ans--;
            }
        }
    }

    return ans;
}

int sequenceElement(std::vector<int> a, int n) {
    const int MOD = (int)1e5;
    std::vector<int> seq;

    for (int i = 0; i < 5; i++) {
        seq.push_back(a[i]);
        cout << a[i];
    }
    seq.push_back(0);

    int lastFive = a[0] * (int)1e4 + a[1] * (int)1e3 + a[2] * (int)1e2 + a[3] * 10 + a[4];

    for (int i = 5;; i++) {
        int x = (seq[(i - 1) % 6] + seq[(i - 2) % 6] + seq[(i - 3) % 6] + seq[(i - 4) % 6] + seq[(i - 5) % 6]) % 10;

        seq.erase(seq.begin() + (i % 6));
        seq.insert(seq.begin() + (i % 6), x);

        lastFive = (lastFive * 10 + seq[i % 6]) % MOD;

        if (i == n) {
            return seq[i % 6];
        }
    }
}

int sequenceElement_ByCF(std::vector<int> a, int n) {
    const int MOD = (int)1e5;
    std::vector<int> seq;
    for (int i = 0; i < 5; i++) {
        seq.push_back(a[i]);
    }

    int lastFive = a[0] * (int)1e4 + a[1] * (int)1e3 + a[2] * (int)1e2 + a[3] * 10 + a[4];
    std::map<int, int> was;
    was[lastFive] = 4;

    for (int i = 5;; i++) {
        seq.push_back((seq[i - 1] + seq[i - 2] +
                       seq[i - 3] + seq[i - 4] + seq[i - 5]) % 10);
        lastFive = (lastFive * 10 + seq[i]) % MOD;
        if (was.find(lastFive) != was.end()) {
            int last = was[lastFive];
            return seq[n % (i - last)];
        } else {
            was[lastFive] = i;
        }
    }
}
