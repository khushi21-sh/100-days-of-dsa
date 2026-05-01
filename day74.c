#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    int freq[MAX] = {0};
    int uniqueCount = 0;

    char temp[LEN];

    // Read votes
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);

        int found = 0;

        // Check if name already exists
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(names[j], temp) == 0) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        // New candidate
        if (!found) {
            strcpy(names[uniqueCount], temp);
            freq[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[LEN] = "";

    for (int i = 0; i < uniqueCount; i++) {
        if (freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, names[i]);
        }
        else if (freq[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}