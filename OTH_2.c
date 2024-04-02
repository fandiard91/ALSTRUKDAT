#include <stdio.h>

int calculateMaxStackSum(int maxSum, int stackA[], int stackALen, int stackB[], int stackBLen) {
    int currentSum = 0, maxCount = 0, temp = 0, indexA = 0, indexB = 0;

    while (indexA < stackALen && currentSum + stackA[indexA] <= maxSum) { 
        currentSum += stackA[indexA++];
    }
    maxCount = indexA;

    while (indexB < stackBLen && indexA >= 0) { 
        currentSum += stackB[indexB++];
        while (currentSum > maxSum && indexA > 0) {
            currentSum -= stackA[--indexA];
        }
        if (currentSum <= maxSum && indexA + indexB > maxCount) {
            maxCount = indexA + indexB;
        }
    }
    return maxCount;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    while (testCases--) {
        int stackALen, stackBLen, maxSum;
        scanf("%d%d%d", &stackALen, &stackBLen, &maxSum);
        int stackA[stackALen], stackB[stackBLen];
        for (int i = 0; i < stackALen; i++) {
            scanf("%d", &stackA[i]);
        }
        for (int i = 0; i < stackBLen; i++) {
            scanf("%d", &stackB[i]);
        }
        printf("%d\n", calculateMaxStackSum(maxSum, stackA, stackALen, stackB, stackBLen));
    }
    return 0;
}
