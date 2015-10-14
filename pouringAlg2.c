//  pouringAlg.c
//  Created by Brandon Vicinus on 10/7/15.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   
   if(argc <= 2 || argc > 12) { //too little or too much arguments
      printf("You entered incorrect arguments. System exit. \n");
      exit(0);
   }
   
   //variables
   int numRequests = argc -2;
   int requests[numRequests];
   int allocated[numRequests];
   int bandwith = atoi(argv[1]); //too lazy to correct the spelling
   int totalRequest = 0;
   int partOfWhole = 0;
   int leftOver = 0;
   
   printf("Total Bandwidth: %d\n", bandwith);
   
   //calculate total request amount
   for (int i = 0; i < numRequests; ++i) {
      requests[i] = atoi(argv[i+2]);
      totalRequest += requests[i];
   }

   //if we have enough to give to everybody...just give it to them
   if (totalRequest < bandwith) {
      for (int i = 0; i < numRequests; ++i) {
            allocated[i] = requests[i];
      }//end for
      
      leftOver = bandwith - totalRequest;
   }
   else { //there is more bandwith requested than available
      
      partOfWhole = (int) bandwith / numRequests; //this will truncate
      leftOver = bandwith % numRequests; //this accounts for truncation
      
      for (int i = 0; i < numRequests; ++i) {
         
         if (partOfWhole > requests[i]) {//only give a request as much as asked
            allocated[i] = requests[i];
            leftOver += partOfWhole - requests[i];
         }
         else { //otherwize, give that request only their fair share
            allocated[i] = partOfWhole;
         }
      }//end for
   
      while (leftOver > 0) { //if there is left over after an even pour
      
         int stillNeed = 0; //number of requests that are not full yet
      
         for (int i = 0; i < numRequests; i++) {
            if (requests[i] - allocated[i] > 0) { //if a request still needs
            stillNeed++; //mark him down as still requesting resources
            }
         }
      
         if (stillNeed < leftOver) { //give some to all
            for (int i = 0; i < numRequests; i++) {
               if (requests[i] - allocated[i] > 0) {
                  allocated[i]++;
                  leftOver--;
               }
            }
         }
         else { //give some to the LEAST required left request first
         
            int tempI= -1;
            int tempMin = 2147483646; //MAX INT
            for(int i = 0; i < numRequests; i++) {
            
               if ((requests[i] - allocated[i]) < tempMin //difference < min
                   && (requests[i] - allocated[i] > 0 )) { //& they still need
                  
                  tempMin = requests[i] - allocated[i]; //difference
                  tempI = i;
               }
            }
         
            allocated[tempI]++;
            leftOver--;
         }//end else
      }//end while
   }//end else
   
   //print statement
   for (int i = 0; i < numRequests; i++) {
      printf("Allocating %d out of requested %d\n", allocated[i], requests[i]);
   }
   printf("Leftover: %d\n", leftOver);

   //done
   return(0);
}