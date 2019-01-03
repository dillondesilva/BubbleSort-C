#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER 100

int swap(int arr[], int, int);
int compare(int, int);

// This is a bubblesort program
int main() {
  int array[BUFFER];
  int idx = 0;
  int size = 0;
  printf("Enter number. If finished, enter 'f'\n");

  while((scanf("%d", &array[idx])) == 1) {
    printf("Enter number. Enter a character to indicate finish\n");
    idx++;
    size++;
  }
  
  // Print original array
  printf("Original array: ");
  for (int j = 0; j < size; j++) {
    printf("%d ", array[j]);
  }
  printf("\n\nBubblesort Progress Below\n\n");
  
  for (int t = 0; t < idx; t++) {
    int has_swap_occured = 0;
    for(int i = 0; i < size; i++) {
      int curr_element = array[i];
      int next_element;
      int next_element_idx = i + 1;
      if (next_element_idx < size) {
        next_element = array[next_element_idx];
      } else {
        break;
      }

      int should_swap = compare(curr_element, next_element);
      if (should_swap == 1) {
          // Swapping adjacent values together
          int idx_one_val = array[i];
          int idx_two_val = array[next_element_idx];

          array[i] = idx_two_val;
          array[next_element_idx] = idx_one_val; 
          has_swap_occured = 1;
      }

      // Printing array to see the bubblesort progress
      for (int j = 0; j < size; j++) {
        printf("%d ", array[j]);
      }
      printf("\n");
    }
    
    if (has_swap_occured == 0) {
      break;
    }
  }
} 

// compare() takes two values and returns whether
// a swap should occur
int compare(val_one, val_two) {
  int should_swap = 0;

  if (val_one > val_two) {
    should_swap = 1;
  } 

  return should_swap;
}
