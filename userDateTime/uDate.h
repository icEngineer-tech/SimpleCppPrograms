#pragma once
#include"macros.h"



class uDate
{
	int year, month, day, wday, yday;
	const char* weed_day[7]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
public:
	//uDate();
	_NODISCARD bool setDate(uDate date)
	{
		if (date.wday > 6)
			return false;
		year = date.year; month = date.month; day = date.day; wday = date.wday;
		return true;
	}
	_NODISCARD uDate& getCurrentDate()
	{
		time_t lc_date = time(nullptr); struct tm* td = localtime(&lc_date);
		year = td->tm_year + 1900; month = td->tm_mon + 1; day = td->tm_mday; wday = td->tm_wday, yday=td->tm_yday;
		return *this;
	}
	_NODISCARD bool setYMD(int y, int m, int d, int wd = 0) { if (wd > 6)return false; year = y; month = m; day = d; return true; }

	_NODISCARD std::string ToString()
	{
		char str[23];
		sprintf(str,"%.4i, %.2i, %.2i ",this->year, this->month, this->day);
		switch (this->wday)
		{
		case 0:
			strcat(str, weed_day[this->wday]);
			break;
		case 1:
			strcat(str, weed_day[this->wday]);
			break;
		case 2:
			strcat(str, weed_day[this->wday]);
			break;
		case 3:
			strcat(str, weed_day[this->wday]);
			break;
		case 4:
			strcat(str, weed_day[this->wday]);
			break;
		case 5:
			strcat(str, weed_day[this->wday]);
			break;
		default:
			strcat(str, weed_day[this->wday]);
			break;
		}
		return str;
	}
	_MAYBEUNUSED bool is_leap_year()
	{
		if (this->year % 4 == 0 && this->year % 100 != 0)
			return true;
		return false;
	}
};
