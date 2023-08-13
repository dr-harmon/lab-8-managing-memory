#pragma once

#include "home_data.h"

// Allocates memory for HOME_DATA_COUNT copies of the HomeData struct and initializes all
// of them with hard-coded values.
void allocateSalesData();

// Computes and updates the pricePerSqFt field for each struct allocated by allocateSalesData,
// then returns the average pricePerSqFt for all of them.
float averagePricePerSqFt();
