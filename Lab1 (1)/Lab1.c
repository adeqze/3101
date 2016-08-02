#include <stdio.h>
#include <stdlib.h>
#include "cashIn.h"

/**program that does computations of 3D arrays.
The program manipulates three functions to do different computations for 
a 3D array that holds float data as money. The first dimension represents half a year
the second dimension represent number of days in a week and the third dimension reperesnts 
the number of register lanes that exist in this particular store, which is five in this case. 
**/ 


//functions declarations
float sumTotal(const float[6][7][5]);
float sumWeekday(const float[6][7][5]);
float sumLane(const float[6][7][5], int n);

int laneNumber = 0; //declared as global so that it can be used within  the function too. 

int main(int argc, char * agrv[]){

int input = 0;

while(1){ //While loop to keep user within program until decided to quit. 

printf("Enter what total you want to calculate as below:\n ");
printf("Enter 1 to calculate the totals for half a year:\n ");
printf("Enter 2 to calculate the totals for the weekday totals:\n ");
printf("Enter 3 to calculate the totals for the a lane:\n ");
printf("Enter 4 if you want to get out of this program: \n");

scanf("%d", &input); // take user input for main selection

if(input < 1 || input > 4){  //throw off if input outside range and display appropriate message
printf("invalid input, please enter a number between 1 and 4:\n ");
printf("You will be taken back to the Main menu: \n");
} 


//Based on the user's input display the computation chosen. 
if(input == 1){
printf("The total of Array: %f \n", sumTotal(cashIn));

} 

else if(input == 2){
printf("The total for the weekday: %f\n", sumWeekday(cashIn));
}

else if (input == 3){ //If they want to compute Lane, ask them to choose which lane. 
printf("Select the lane you want to calculate for:\n ");
printf("Please chose a lane between 0 and 4:\n");
scanf("%d", &laneNumber);
if(laneNumber < 0 || laneNumber > 4){
printf("Invalid lane Entry, please enter a number between 0 and 4:\n ");
printf("You will be taken back to the main menu to choose again:\n");
printf("\n");
}
else{
printf("The total for chosen lane is: %f\n", sumLane(cashIn, laneNumber));
}
}

//If the user option to exit program. 
if(input == 4){
exit(0);
}
}
}


//Functions definitions

/**function to calculate the total sum for the whole period (half a year),
all days included and all lanes. 

**/
float sumTotal(const float someArray[6][7][5]){
int i, j, k;
float total = 0.0;
for(i = 0; i < 6; i++){
for(j = 0; j < 7; j ++){
for(k = 0; k < 5; k++){
total += someArray[i][j][k];
}
}
} 
return total;
}

/**Function to calculate the total for only the weekdays in the whole period (6 months),
weekends not included but all lanes included. 
**/
float sumWeekday(const float someArray[6][7][5]){
int i, j, k;
float total = 0.0;
for(i = 0; i < 6; i++){
for(j = 0; j < 5; j++){ //two days of weekends left out
for(k = 0; k < 5; k++){
total += someArray[i][j][k];
 }
}
}
return total;
}

/**Function to calculate the total for the whole period (six months), 
all days included (7 days a week) but only the specific lane choosen by the user. 
**/
float sumLane(const float someArray[6][7][5], int n){
int i, j , k;
float total = 0.0;
n = laneNumber;
for(i = 0; i < 6; ++i){
for(j = 0; j < 7; ++j){
total += someArray[i][j][n];//n based on the lane chosen by user.
}
}
return total;

}
