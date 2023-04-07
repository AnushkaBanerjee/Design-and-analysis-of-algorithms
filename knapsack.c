#include <stdio.h>
#include <stdlib.h>

struct knapsack
{
    int item;
    float weight, profit, ratio;
};
typedef struct knapsack ks;

// A function to implement bubble sort
void bubbleSort(ks arr[], int n)
{
    struct knapsack temp;
    for (int i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (int j = i + 1; j < n; j++)
        {
            // printf("%f %f\n", arr[j].ratio, arr[i].ratio);
            if (arr[j].ratio > arr[i].ratio)
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
}

void knapsack(ks arr[], int n, float bag_cap)
{

    float cost = 0.0, fraction;
    float rem_cap = bag_cap;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= rem_cap)
        {
            cost = cost + arr[i].profit;
            rem_cap = rem_cap - arr[i].weight;
        }
        else if (rem_cap > 0)
        {
            cost = cost + ((rem_cap / arr[i].weight) * arr[i].profit);
            break;
        }
        // printf("\n The profit is: %f Rem Capacity: %f",cost, rem_cap);
    }

    printf("\n The profit is: %f", cost);
}


int main()
{
    float bag_cap;
    int num;
    printf("Enter the no. of items: ");
    scanf("%d", &num);
    printf("Enter the bag apacity: ");
    scanf("%f", &bag_cap);
    ks arr[num];

    printf("Enter the weight and profit: ");
    for (int indx = 0; indx < num; indx++)
    {
        arr[indx].item = indx+1;
        scanf("%f %f", &arr[indx].weight, &arr[indx].profit);
        arr[indx].ratio = arr[indx].profit / arr[indx].weight;
    }

    printf("before sorting\n");
    for (int indx = 0; indx < num; indx++)
    {
        printf("%d %f %f %f", arr[indx].item, arr[indx].weight, arr[indx].profit, arr[indx].ratio);
        printf("\n");
    }
    printf("\n");
    bubbleSort(arr, num);
    printf("after sorting\n");
    for (int indx = 0; indx < num; indx++)
    {
        printf("%d %f %f %f", arr[indx].item, arr[indx].weight, arr[indx].profit, arr[indx].ratio);
        printf("\n");
    }

    knapsack(arr, num, bag_cap);

    return 0;
}
