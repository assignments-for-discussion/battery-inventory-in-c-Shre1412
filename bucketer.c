#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  int i = 0;
  for(i=0; i<=nBatteries-1; i++){
      if(cycles[i]>=0 && cycles[i]<410){
          counts.lowCount = counts.lowCount +1;
      }else if(cycles[i]>=410 && cycles[i]<=909){
          counts.mediumCount = counts.mediumCount +1;
      }else if(cycles[i]>=910){
          counts.highCount = counts.highCount +1;
      }else{
          printf("Invalid Input - %d \n",cycles[i]);
      }
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Number of batteries in different charging classes are: \nLow: %d \nMedium: %d \nHigh: %d \n",counts.lowCount,counts.mediumCount,counts.highCount);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
