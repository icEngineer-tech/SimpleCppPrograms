#include <iostream>
#include "hotel_mang_function.h"
#include <iomanip>


int main()
{
	std::string hotelName;
	unsigned nbrFloor{}, nbrRoom{}; // , sRoom{}, dRoom{}, kRoom{}, suiteRoom{};
	unsigned FloorArr[MAX_FLOOR];
	Floor F[MAX_FLOOR];
	std::cout << "======================================================================================================================\n";
	std::cout << "\t\tBlueMont Hotel\n";
	std::cout << "======================================================================================================================\n";
	std::cout << "Enter the location of this hotel: ";
	std::cin >> hotelName;
	do
	{
		std::cout << "Enter the total number of floors: ";
		std::cin >> nbrFloor;
		if (nbrFloor<MIN_FLOOR || nbrFloor>MAX_FLOOR)
			std::cout << "Number of floor should be between 1 and 5!! please try again.\n";
	} while (nbrFloor<MIN_FLOOR || nbrFloor>MAX_FLOOR);

	for (int i = 1; i <= nbrFloor; i++)
	{
		do
		{
			std::cout << "Enter the total number of Rooms in the "<<i<<" floor: ";
			std::cin >> nbrRoom;
			FloorArr[i - 1] = nbrRoom;
			if (nbrRoom<MIN_ROOM || nbrRoom>MAX_ROOM)
				std::cout << "Number of floor should be between 1 and 5!! please try again.\n";
		} while (nbrRoom<MIN_ROOM || nbrRoom>MAX_ROOM);
	}
	for (int i = 1; i <= nbrFloor; i++)
	{
		std::cout << "How many SINGLE Room are occupied in the " << i << " Floor: ";
		std::cin >> F[i-1].sRoom;
		std::cout<< "How many DOUBLE Room are occupied in the " << i << " Floor: ";
		std::cin >> F[i-1].dRoom;
		std::cout << "How many KING Room are occupied in the " << i << " Floor: ";
		std::cin >> F[i-1].kRoom;
		std::cout << "How many SUITE Room are occupied in the " << i << " Floor: ";
		std::cin >> F[i-1].suiteRoom;
	}

	info(hotelName);
	float hotelIncome = 0.f;
	unsigned totsRoom{}, totdRoom{}, totkRoom{}, totsuiteRoom{}, totRoom{};
	for (int i = 0; i < nbrFloor; i++)
	{
		totsRoom += F[i].sRoom;
		totdRoom += F[i].dRoom;
		totkRoom += F[i].kRoom;
		totsuiteRoom += F[i].suiteRoom;
		totRoom += FloorArr[i];
	}
	unsigned min = FloorArr[0], fNbr{};
	for (int i = 1; i < nbrFloor; i++)
	{
		if (min > FloorArr[i])
		{
			min = FloorArr[i];
			fNbr = i + 1;
		}
	}
	if (fNbr == 0)
		fNbr = 1;
	hotelIncome = totsRoom * 60 + totdRoom * 75 + totkRoom * 100 + totsuiteRoom * 150;
	unsigned unoccupiedRoom = totRoom - (totsRoom + totkRoom + totdRoom + totsuiteRoom);
	float occupancyRate = (float)(totsRoom + totkRoom + totdRoom + totsuiteRoom) / totRoom * 100;
	std::cout << "\t\tHotel income: $" << hotelIncome;
	std::cout << "\n\tTotal room: " << totRoom;
	std::cout << "\n\tTotal # occupied room: "<< totsRoom + totkRoom + totdRoom + totsuiteRoom;
	std::cout << "\n\tTotal # unoccupied room: " << unoccupiedRoom;
	std::cout << "\n\tOccupancy rate: " << std::setprecision(4) << occupancyRate << "%\n\n";
	switch (fNbr)
	{
	case 1:
		std::cout << fNbr << "st floor with " << min << " rooms, has the least number of rooms!\n";
		break;
	case 2:
		std::cout << fNbr << "nd floor with " << min << " rooms, has the least number of rooms!\n";
		break;
	default:
		std::cout << fNbr << "th floor with " << min << " rooms, has the least number of rooms!\n";
	}
	if (occupancyRate < 60)
		std::cout << "Need to improve Hotel occupancy.\n\n";

	End();
	return 0;
}
