#include "header.h"

int toedit() {
    int choice;
    char lisence_p[20];
    int thereisVeh=0;
    int value;
    char endchar;

    car_details car_a;
    FILE* file = fopen("car_file.dat","rb+");


    if (file==NULL) {
        printf("File could not be opened!\n");
        return 1;
    }
    printf("Enter the license plate of the vehicle you wish to edit: ");
    scanf("%19s",lisence_p);

    while (fread(&car_a,sizeof(car_details),1,file)) {
        if (strcmp(car_a.license_plate,lisence_p)==0) {
            thereisVeh=1;

            do {
                printf("***** VEHICLE WITH LICENSE PLATE %s *****\n",car_a.license_plate);
                printf(" 1. Change color (current: %s)\n",car_a.color);
                printf(" 2. Change brand (current: %s)\n",car_a.brand);
                printf(" 3. Change date (current: %s)\n",car_a.date);
                printf(" 4. Change the vehicle license plate (current: %s)\n",car_a.license_plate);
                printf(" 5. Save and exit\n\n");

                while (1) {
                    endchar=' ';
                    printf("Enter your selection: ");
                    value=scanf("%d%c",&choice,&endchar);
                    if (value==2 && endchar=='\n') {
                        break;
                    }else {
                        printf("Invalid selection.Please enter an integer between 1 and 5!\n");
                        if (endchar!='\n') {
                            while (getchar()!='\n');
                        }
                    }
                }


                switch (choice) {
                    case 1:printf("enter a new color: ");
                        scanf("%19s",car_a.color);
                        printf("color updated\n\n");
                        break;
                    case 2:printf("enter a new brand: ");
                        scanf("%19s",car_a.brand);
                        printf("New brand updated\n\n");
                        break;
                    case 3:printf("enter the new date: ");
                        scanf("%19s",car_a.date);
                        printf("New date updated\n\n");
                        break;
                    case 4:printf("enter a new license plate: ");
                        scanf("%19s",car_a.license_plate);
                        printf("New license plate updated\n\n");
                        break;
                    case 5:
                            fseek(file,-(long)sizeof(car_details),SEEK_CUR);
                            fwrite(&car_a,sizeof(car_details),1,file);
                            fseek(file,0,SEEK_CUR);
                            break;
                    default: printf("Please enter a valid transaction!\n");
                }
            }while (choice!=5);
            break;
        }
    }

    if (thereisVeh==0) {
        printf("The requested license plate could not be found!");
    }
    fclose(file);
    return 0;
}

