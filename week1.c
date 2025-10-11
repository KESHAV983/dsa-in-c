#include <stdio.h>
void BubbleSort(int num[], int size)
{
    int i, j;
    int temp;
    int swap;
    for (i = 0; i < size - 1; i++)
    {
        swap = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                temp = nums[j];

                num[j] = num[j + 1];
                num[j + 1] = temp;
                swap = 1;
            }
        }
    }
}
void showArray(int data[], int length)
{
    for (int k = 0; k < length; k++)
    {
        printf("%d ", data[k]);
    }
    printf("\n");
}

int main()
{
    int n;
    int i;
    printf("How many numbers do you want to sort? ");
    scanf("%d", &n);
    int values[n];
    printf("Enter your %d numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }
    printf("Array before sorting: ");
    showArr(values, n);
    doBubbleSort(values, n);
    printf("Array after sorting (ascending): ");
    showArr(values, n);
    return 0;
}