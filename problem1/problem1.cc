#include <iostream>
#include <vector>
const int MinutesPerHour = 60;

// bool checkArithOrder(const std::vector<int>& v) {
//     if (v[1] - v[0] == v[2] - v[1]) {
//         return v[3] - v[2] == v[1] - v[0];
//     }
//     return false;
// }

void buildSeq(std::vector<int>& seq) {
    seq.push_back(34); // 12:34
    for (int h = 1; h < 10; h++) {
        for (int m1 = 0; m1 < 6; m1++) {
            int m2 = m1 + (m1 - h);
            if (m2 >= 0 && m2 <= 9) {
                int val = h * MinutesPerHour + m1 * 10 + m2;
                seq.push_back(val);
            }
        }
    }
    seq.push_back(671); // 11:11
}


int count(int duration, const std::vector<int>& seq) {
    int cycle = duration / (MinutesPerHour * 12);
    int rest = duration % (MinutesPerHour * 12);
    int count = cycle * seq.size();
    for (int i = 0; i < seq.size(); i++) {
        if (rest < seq[i]) {
            count += i;
            break;
        }
    }
    return count;
}



int main() {
    std::vector<int> seq;
    buildSeq(seq);
    int duration;
    std::cin >> duration;
    int counter = count(duration, seq);
    std::cout << counter << std::endl;
}

