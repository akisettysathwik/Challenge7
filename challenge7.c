#include <stdio.h>

int main()
{
    int n, a[15];
    int i, j, id, count;
    int missing = 0, duplicate = 0;
    int missingCount = 0, duplicateCount = 0;
    int valid = 1;
    int outOfOrder = 0;
    int R, target, targetCount = 0;

    do
    {
        printf("Enter N (5 to 15): ");
        scanf("%d", &n);

        if (n < 5 || n > 15)
        {
            printf("Invalid N. Enter again.\n");
        }
    } while (n < 5 || n > 15);

    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Enter ticket ID %d: ", i + 1);
            scanf("%d", &a[i]);

            if (a[i] < 1 || a[i] > n)
            {
                printf("Invalid ticket ID. Enter a value from 1 to %d.\n", n);
            }
        } while (a[i] < 1 || a[i] > n);
    }

    printf("\nOriginal scan sequence: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (id = 1; id <= n; id++)
    {
        count = 0;

        for (i = 0; i < n; i++)
        {
            if (a[i] == id)
            {
                count++;
            }
        }

        if (count == 0)
        {
            missing = id;
            missingCount++;
        }
        else if (count == 2)
        {
            duplicate = id;
            duplicateCount++;
        }
        else if (count != 1)
        {
            valid = 0;
        }
    }

    if (missingCount != 1 || duplicateCount != 1)
    {
        valid = 0;
    }

    if (valid == 0)
    {
        printf("\nInvalid scan log.\n");
        printf("The sequence must contain exactly one missing ID and ");
        printf("one different ID appearing twice.\n");

        return 0;
    }

    printf("\nDuplicated ticket ID: %d\n", duplicate);
    printf("Missing ticket ID: %d\n", missing);

    printf("\nOut-of-order pairs (position:ID):\n");

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                printf("(%d:%d, %d:%d)\n",
                       i + 1, a[i], j + 1, a[j]);

                outOfOrder++;
            }
        }
    }

    if (outOfOrder == 0)
    {
        printf("None\n");
    }

    printf("Total out-of-order pairs: %d\n", outOfOrder);

    do
    {
        printf("\nEnter the last two digits of your registration number (0-99): ");
        scanf("%d", &R);

        if (R < 0 || R > 99)
        {
            printf("Invalid value. Enter a number from 0 to 99.\n");
        }
    } while (R < 0 || R > 99);

    target = (R % n) + 1;

    printf("\nPersonalised audit target ID: %d\n", target);
    printf("Positions in original sequence: ");

    for (i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            printf("%d ", i + 1);
            targetCount++;
        }
    }

    if (targetCount == 0)
    {
        printf("None");
    }

    printf("\nOccurrence count: %d\n", targetCount);

    return 0;
}