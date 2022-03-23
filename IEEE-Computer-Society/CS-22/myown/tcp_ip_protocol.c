#include <stdio.h>
#include <string.h>

struct packet_order {
    char order[3];
};

int fill_packets(struct packet_order *packets) {
    char buffer[80];
    int state = -1;
    scanf("%d\n", &state);
    int number_of_packages = 0;
    if (state == 1) {
        char order[3];
        fgets(buffer, 80, stdin);
        while (sscanf(buffer, "Package %c%c%c\n", &order[0], &order[1], &order[2])) {
            for (int i = 0; i < 3; ++i) {
                packets[number_of_packages].order[i] = order[i];
            }
            number_of_packages += 1;
            fgets(buffer, 80, stdin);
        }
        return number_of_packages;
    }
    return 0;
}

void countSort(struct packet_order packets[], int n, int digit_order) {
    struct packet_order output[n];
    int count[10] = {0};
    for (int i = 0; i < n; ++i) {
        count[packets[i].order[digit_order]-'0']++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i-1];
    }

    for (int i = n-1; i >= 0; --i) {
        memcpy(output[count[packets[i].order[digit_order]-'0']-1].order, packets[i].order, sizeof(char)*3);
        count[packets[i].order[digit_order]-'0']--;
    }

    memcpy(packets, output, n*sizeof(struct packet_order));
}
void radixsort(struct packet_order packets[], int n) {
    for (int digit_order = 2; digit_order >= 0; digit_order--) {
        countSort(packets, n, digit_order);
    }
}

int main()
{
    int state;
    struct packet_order packets[1000] = {0};

    int number_of_packages = 0;
    while ((number_of_packages = fill_packets(packets)) != 0) {
        radixsort(packets, number_of_packages);
        for (int i = 0; i < number_of_packages; ++i) {
            printf("Package %c%c%c\n", packets[i].order[0], packets[i].order[1], packets[i].order[2]);
        }
        printf("\n");
    }
}
