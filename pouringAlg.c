//
//  pouringAlg.c
//  
//
//  Created by Brandon Vicinus on 10/7/15.
//
//

#include <stdio.h>


int main(int argc, char *argv[]) {
   
   char input1[20];
   int i = 1;
   
   input1[0] = argv[1];
   
   do {
      input1[i] = argv[i+1];
      ++i;
      
   }while (argv[i+1] != NULL) ;
   
   
   printf("Allocated bandwith: %d" , input1[0]);
   
   return(0);
}