/* 
 * File:   main.c
 * Author: vignesh
 * Comments: Simple shellSort demo program
 * Created on 16 December 2009, 10:28
 */

#include <stdio.h>
#include <stdlib.h>

void shellSortPhase(int a[], int length, int gap) {
     int i;
     for (i = gap; i < length; ++i) {
         int value = a[i];
         int j;
         for (j = i - gap; j >= 0 && a[j] > value; j -= gap) {
             a[j + gap] = a[j];
         }
         a[j + gap] = value;
     }
 }//end for
 
 void shellSort(int a[], size_t length) {
     /*
      * gaps[] should approximate a [[w:geometric progression|geometric progression]].
      * The following sequence is the best known in terms of
      * the average number of key comparisons made [http://www.research.att.com/~njas/sequences/A102549]
      */
     static const int gaps[] = {
         1, 4, 10, 23, 57, 132, 301, 701
     };
     int sizeIndex;
 
     for (sizeIndex = sizeof(gaps)/sizeof(gaps[0]) - 1;
                sizeIndex >= 0;
                --sizeIndex)
         shellSortPhase(a, length, gaps[sizeIndex]);
 }
 
 int main(){
     int array[]= {1, 4, 13, 40, 121, 364, 1093, 3280};
     int i,n;
     n = sizeof array/ sizeof array[0];
     shellSort(array, n);
     for(i=0; i<n; i++)
        printf("%d, ", array[i]);
     return 0;
 }