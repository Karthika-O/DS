#include <stdio.h>

// Function to find the union of two sets
void unionSets(int set1[], int size1, int set2[], int size2) {
    int unionSet[size1 + size2];
    int i, j, k;

    // Copy elements from set1 to the unionSet
    for (i = 0; i < size1; i++) {
        unionSet[i] = set1[i];
    }
    k = size1;

    // Add elements from set2 to the unionSet if they are not already present
    for (i = 0; i < size2; i++) {
        int isDuplicate = 0;
        for (j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionSet[k++] = set2[i];
        }
    }

    printf("Union of the sets: ");
    for (i = 0; i < k; i++) {
        printf("%d ", unionSet[i]);
    }
    printf("\n");
}

// Function to find the intersection of two sets
void intersectionSets(int set1[], int size1, int set2[], int size2) {
    int intersectionSet[size1];
    int i, j, k = 0;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                intersectionSet[k++] = set1[i];
                break;
            }
        }
    }

    printf("Intersection of the sets: ");
    for (i = 0; i < k; i++) {
        printf("%d ", intersectionSet[i]);
    }
    printf("\n");
}

// Function to find the difference between two sets
void differenceSets(int set1[], int size1, int set2[], int size2) {
    int differenceSet[size1];
    int i, j, k = 0;

    for (i = 0; i < size1; i++) {
        int isDifferent = 1;
        for (j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                isDifferent = 0;
                break;
            }
        }
        if (isDifferent) {
            differenceSet[k++] = set1[i];
        }
    }

    printf("Difference of set1 - set2: ");
    for (i = 0; i < k; i++) {
        printf("%d ", differenceSet[i]);
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the size of the first set: ");
    scanf("%d", &size1);
    int set1[size1];
    printf("Enter elements of the first set: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &set1[i]);
    }

    printf("Enter the size of the second set: ");
    scanf("%d", &size2);
    int set2[size2];
    printf("Enter elements of the second set: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &set2[i]);
    }

    unionSets(set1, size1, set2, size2);
    intersectionSets(set1, size1, set2, size2);
    differenceSets(set1, size1, set2, size2);

    return 0;
}
