/**
 * Created by Jacob on 2017/1/19.
 */

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

// Description: Given integers a and b, determine whether the following pseudocode results in an infinite loop
// Input: a = 2, b = 3
// Output: isInfiniteProcess(a, b) = true
boolean isInfiniteProcess(int a, int b) {
    return a > b ? true : (a - b) % 2 != 0;
    // return (!(a <= b && ((b-a) % 2) == 0));
}
