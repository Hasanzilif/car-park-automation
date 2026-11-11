#include "header.h"                     //PARK SYSTEM


int main() {
    int choice;
    int value;
    char endchar;

    do {

        while (1) {
            menu();
            endchar=' ';
            printf("Enter a number between 1 and 5 : ");
            value = scanf("%d%c",&choice,&endchar);
            if (value==2 && endchar=='\n') {
                break;
            }else {
                printf("Invalid input.Please enter only an integer between 1 and 5!\n");
                if (endchar!='\n') {
                    while (getchar()!='\n');
                }
            }
        }


        switch (choice) {
            case 1:if (register_car()==0) {
                printf("\nVehicle successfully registered.");
            }
                else {
                    printf("An issue occurred during the registration of the vehicle!");
                }
                break;
            case 2:if (tolist()==0) {
                printf("\n\aThe vehicles have been successfully listed.");
            }
            else {
                printf("An issue occurred while listing the vehicles!");
            }
                break;
            case 3:if (toedit()==0) {
                printf("\n");
            }else {
                printf("An error occurred!!");
            }
                break;
            case 4:if (todelete()==0) {
                printf("\n");
            }else {
                printf("The operation failed!");
            }
                break;
            case 5: printf("You have exited the program.");
                break;
            default:printf("Please select a valid action!!");
                break;
        }
    }while (choice!=5);

    return 0;
}

