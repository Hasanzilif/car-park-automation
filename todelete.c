#include "header.h"

int todelete() {
    car_details car_a;
    char license_p[20];
     int thereisVeh=0;

     FILE* file=fopen("car_file.dat","rb");
     FILE* temporary=fopen("temporary_file.dat","wb");

     if (file==NULL || temporary==NULL) {
         printf("Files could not be opened!");
         return 1;
     }
     printf("Enter the license plate number of the vehicle you wish to delete: ");
     scanf("%19s",license_p);

     while (fread(&car_a,sizeof(car_details),1,file)==1) {
         if (strcmp(car_a.license_plate,license_p)!=0) {
             fwrite(&car_a,sizeof(car_details),1,temporary);
         }
         else {
             thereisVeh=1;
         }
     }

     fclose(file);
     fclose(temporary);

     if (thereisVeh==1) {
         remove("car_file.dat");
         rename("temporary_file.dat","car_file.dat");
         printf("The vehicle has been successfully deleted.");
     }else {
         remove("temporary_file.dat");
         printf("No vehicle was found for the license plate you searched for.\n");
     }
     return 0;
 }
