#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char brand[20];
    char license_plate[20];
    char color[20];
    char date[20];

}car_details;

void menu();
int tolist();
int register_car();
int toedit();
int todelete();

#endif