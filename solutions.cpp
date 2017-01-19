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

