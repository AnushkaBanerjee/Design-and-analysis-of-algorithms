#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Job {
  int id;
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}

int main(void) {
  //variables
  int i, j;

  


int num;
printf("enter the number of jobs : ");
scanf("%d",&num);
struct Job *jobs;
jobs=(struct Job*)malloc(num*sizeof(struct Job));


for(int i=0;i<num;i++){
    printf("\nenter the deadline of job %d : ",i+1);
    scanf("%d",&jobs[i].deadline);
    printf("enter the profit of job %d : ",i+1);
    scanf("%d",&jobs[i].profit);
    jobs[i].id=i+1;
}

printf("\n\nPRINTING JOBS:\n");
for(int i=0;i<num;i++){
    printf("job--> %d profit--> %d deadline--> %d \n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
}
  //temp
  Job temp;

  //number of jobs
  int n = num;

  //sort the jobs profit wise in descending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

printf("\n\nPRINTING JOBS AFTER SORTING:\n");
for(int i=0;i<num;i++){
    printf("job--> %d profit--> %d deadline--> %d \n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
}

  jobSequencingWithDeadline(jobs, n);

  return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n) {
  //variables
  int i, j, k, maxprofit;

  //free time slots
  int timeslot[MAX];

  //filled time slots
  int filledTimeSlot = 0;

  //find max deadline value
  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  //free time slots initially set to -1 [-1 denotes EMPTY]
  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

 // printf("dmax: %d\n", dmax);

  for(i = 1; i <= n; i++) {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    //if all time slots are filled then stop
    if(filledTimeSlot == dmax) {
      break;
    }
  }

  //required jobs
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%d", jobs[timeslot[i]].id);

    if(i < dmax) {
      printf(" --> ");
    }
  }

  //required profit
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}

