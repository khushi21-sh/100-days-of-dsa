#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int pos;
    int speed;
} Car;

// Sort by position (descending)
int cmp(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[n];

    // Input positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].pos);
    }

    // Input speeds
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    // Step 1: Sort by position (descending)
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double prevTime = 0;

    // Step 2: Process cars
    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        // New fleet
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
        // Else joins previous fleet
    }

    printf("%d", fleets);

    return 0;
}