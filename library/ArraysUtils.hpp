//
// Created by nthieu6 on 06/04/2015.
//

class ArraysUtils {
public:
    static long long sumArray(int A[], int n) {
        long long answer = 0;
        for (int i = 0; i < n; i++) {
            answer += A[i];
        }
        return answer;
    }
};