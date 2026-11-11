#include "header.h"

int register_car() {
    car_details car_a;
    FILE* file = fopen("car_file.dat","ab");

    if (file == NULL) {
        printf("The vehicle file could not be opened!");
        return -1;
    }
    printf("Enter the vehicle's brand: ");
    scanf("%19s",car_a.brand);
    printf("Enter the vehicle's license plate number: ");
    scanf("%19s",car_a.license_plate);
    printf("enter the vehicle's color: ");
    scanf("%19s",car_a.color);
    printf("Enter the vehicle's entry time (hour:minute,date (xx:xx,xx.xx.20xx)): ");
    scanf("%19s",car_a.date);
    fwrite(&car_a,sizeof(car_details),1,file);
    fclose(file);
    return 0;
}
