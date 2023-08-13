#include "home_sales.h"

#include <memory>

std::unique_ptr<HomeData> salesData[HOME_DATA_COUNT];

void allocateSalesData()
{
    for (int i = 0; i < HOME_DATA_COUNT; i++) {
        std::unique_ptr<HomeData> home = std::make_unique<HomeData>();
        home->bedrooms = 3;
        home->bathrooms = 2;
        home->square_feet = 1800;
        home->price = 400000;
        home->pricePerSqFt = 0;
        salesData[i] = std::move(home);
    }
}

std::unique_ptr<HomeData> calculatePricePerSqFt(std::unique_ptr<HomeData> data)
{
    data->pricePerSqFt = data->price / data->square_feet;
    return data;
}

float averagePricePerSqFt()
{
    float total = 0;
    for (int i = 0; i < HOME_DATA_COUNT; i++) {
		salesData[i] = calculatePricePerSqFt(std::move(salesData[i]));
        total += salesData[i]->pricePerSqFt;
	}
    return total / HOME_DATA_COUNT;
}
