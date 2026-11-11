#include "header.h"

int  tolist() {
	car_details car_a;
    FILE* file = fopen("car_file.dat","rb");

	if(file==NULL) {
		return 1;
	}
	printf("BRAND%16sLICENSE PLATE%8sCOLOR%16sDATE\n"," "," "," ");
	printf("-----%16s-------------%8s-----%16s-----\n"," "," "," ");
	while(fread(&car_a,sizeof(car_details),1,file)==1) {
		printf("%-20s %-20s %-20s %-20s\n",car_a.brand,car_a.license_plate,car_a.color,car_a.date);

	}
	fclose(file);
	return 0;
}
