#include <stdio.h>

int main(void) {
    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    int value;
    int coin_count = 0;
    int charge;

    scanf("%d", &value);

    charge = 1000 - value;

    for (int i = 0; i < 6; i++)
    {
        int num = charge / coin[i];
        coin_count += num;
        charge = charge % coin[i];
    }

    printf("%d\n", coin_count);
    return 0;
}