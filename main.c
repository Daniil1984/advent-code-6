#include <stdio.h>
#include <stdlib.h>
#define DAYS1 80
#define DAYS2 256
#define SIX 6
#define SEVEN 7
#define EIGHT 8

long long solution(const long long *array, int days);

int main(int argc, char *argv[argc])
{
    if (argc != 2) {
        return -1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        return 1;
    }
    long long array[EIGHT + 1];
    for (int i = 0; i < EIGHT + 1; i++) {
        array[i] = 0;
    }
    int number;
    char c;
    int res;
    while ((res = fscanf(input, "%d", &number)) == 1 &&
           fscanf(input, "%c", &c) == 1) {
        if (number > SIX || number < 0) {
            return 2;
        }
        array[number]++;
    }
    if (res == 1) {
        array[number]++;
    }
    fclose(input);
    printf("%lld\n", solution(array, DAYS1));
    printf("%lld\n", solution(array, DAYS2));
    return 0;
}

int new_fish(int number, int days)
{
    if (days <= number) {
        return 0;
    }
    int n_count = 0;
    n_count += 1;
    n_count += new_fish(SIX, days - number - 1);
    n_count += new_fish(SEVEN, days - number - 1);
    return n_count;
}

long long solution(const long long *array, int days)
{
    long long array_copy[EIGHT + 1];
    for (int j = 0; j < EIGHT + 1; j++) {
        array_copy[j] = array[j];
    }
    for (int i = 0; i < days; i++) {
        long long buf[EIGHT + 1];
        for (int j = 0; j < EIGHT + 1; j++) {
            buf[j] = 0;
        }
        for (int j = 0; j < EIGHT + 1; j++) {
            if (j == 0) {
                buf[SIX] += array_copy[j];
                buf[EIGHT] += array_copy[j];
            } else {
                buf[j - 1] += array_copy[j];
            }
        }
        for (int j = 0; j < EIGHT + 1; j++) {
            array_copy[j] = buf[j];
        }
    }
    long long result = 0;
    for (int i = 0; i < EIGHT + 1; i++) {
        result += array_copy[i];
    }
    return result;
}
