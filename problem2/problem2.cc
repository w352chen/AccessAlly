#include <iostream>
#include <vector>

const int rulesCount = 27;
const int receivingBloodTypeFrom[rulesCount] = {
    0, 1, 2, 3, 4, 5, 6, 7, // step1: receiving blood for same type/RH
    0, 2, 4, 6,             // step2: O- -> O+, A- -> A+, B- -> B+, AB- -> AB+
    3, 5, 2, 4,             // step3: A+ -> AB+, B+ -> AB+, A- -> AB-, B- -> AB-
    2, 4,                   // step4: A- -> AB+, B- -> AB+
    1, 1, 1,                // step5: O+ -> A+, O+ -> B+, O+ -> AB+
    0, 0, 0,                // step6: O- -> A-, O- -> B-, O- -> AB-
    0, 0, 0                 // step7: O- -> A+, O- -> B+, O- -> AB+
};

const int receivingBloodTypeTo[rulesCount] = {
    0, 1, 2, 3, 4, 5, 6, 7, // step1: receiving blood for same type/RH
    1, 3, 5, 7,             // step2: O- -> O+, A- -> A+, B- -> B+, AB- -> AB+
    7, 7, 6, 6,             // step3: A+ -> AB+, B+ -> AB+, A- -> AB-, B- -> AB-
    7, 7,                   // step4: A- -> AB+, B- -> AB+
    3, 5, 7,                // step5: O+ -> A+, O+ -> B+, O+ -> AB+
    2, 4, 6,                // step6: O- -> A-, O- -> B-, O- -> AB-
    3, 5, 7                 // step7: O- -> A+, O- -> B+, O- -> AB+
};

// calculate minimum value among two integers  
int min(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int receiveBlood(std::vector<int> &blood, std::vector<int> &patients, const int ruleNo) {
    int bloodType = receivingBloodTypeFrom[ruleNo];
    int patientBloodType = receivingBloodTypeTo[ruleNo];
    int receivingBUnits = min(blood[bloodType], patients[patientBloodType]);
    blood[bloodType] -= receivingBUnits;
    patients[patientBloodType] -= receivingBUnits;
    return receivingBUnits;
}

int main() {
    // Obtain inputs
    int input;
    std::vector<int> blood, patients;
    for (int i = 0; i < 8; i++) {
        std::cin >> input;
        blood.push_back(input);
    }
    for (int i = 0; i < 8; i++) {
        std::cin >> input;
        patients.push_back(input);
    }

    // Calculate receiving blood units
    int count = 0;
    for (int i = 0; i < rulesCount; i++) {
        count += receiveBlood(blood, patients, i);
    }

    // Output the result
    std::cout << count << '\r' << std::endl;
}
    