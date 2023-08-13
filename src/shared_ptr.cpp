#include "home_sales.h"

#include <memory>

std::shared_ptr<HomeData> salesData[HOME_DATA_COUNT];

void allocateSalesData()
{
    for (int i = 0; i < HOME_DATA_COUNT; i++) {
        std::shared_ptr<HomeData> home = std::make_shared<HomeData>();
        home->bedrooms = 3;
        home->bathrooms = 2;
        home->square_feet = 1800;
        home->price = 400000;
        salesData[i] = home;
    }
}

void calculatePricePerSqFt(std::shared_ptr<HomeData> data)
{
    data->pricePerSqFt = data->price / data->square_feet;
}

float averagePricePerSqFt()
{
    float total = 0;
    for (int i = 0; i < HOME_DATA_COUNT; i++) {
		calculatePricePerSqFt(salesData[i]);
        total += salesData[i]->pricePerSqFt;
	}
    return total / HOME_DATA_COUNT;
}
