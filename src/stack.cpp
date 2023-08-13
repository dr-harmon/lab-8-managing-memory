#include "home_sales.h"

HomeData salesData[HOME_DATA_COUNT];

void allocateSalesData()
{
    for (int i = 0; i < HOME_DATA_COUNT; i++) {
        HomeData home;
        home.bedrooms = 3;
        home.bathrooms = 2;
        home.square_feet = 1800;
        home.price = 400000;
        salesData[i] = home;
    }
}

HomeData calculatePricePerSqFt(const HomeData data)
{
    HomeData newData = data;
    newData.pricePerSqFt = data.price / data.square_feet;
    return newData;
}

float averagePricePerSqFt()
{
    float total = 0;
    for (int i = 0; i < HOME_DATA_COUNT; i++) {
		salesData[i] = calculatePricePerSqFt(salesData[i]);
        total += salesData[i].pricePerSqFt;
	}
    return total / HOME_DATA_COUNT;
}
