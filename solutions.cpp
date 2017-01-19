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
maxFraction(numerators, denominators) = 2.
Op
int maxFraction(std::vector<int> numerators, std::vector<int> denominators) {
    int max_index = 0;
    float max_fraction = 0;
    for (int i = 0; i < numerators.size(); i++) {
        float temp_fraction = (float)(numerators[i]) / denominators[i];
        if (temp_fraction > max_fraction) {
            max_fraction = temp_fraction;
            max_index = i;
        }
    }
    return max_index;
}
