#pragma once
#include"macros.h"



class uDate
{
protected:
	unsigned year, month, day, wday, yday;
	const char* week_day[7]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
public:
	uDate()noexcept  :year(0),month(0),day(0),wday(0),yday(0){}
	uDate(unsigned year, unsigned month, unsigned day, unsigned weekday, unsigned yearday) noexcept
		:year(year),month(month),day(day),wday(weekday),yday(yearday){}
	_NODISCARD bool setDate(uDate date)
	{
		if (date.wday > 6)
			return false;
		year = date.year; month = date.month; day = date.day; wday = date.wday;
		return true;
	}
	_NODISCARD uDate& getCurrentDate() noexcept
	{
		time_t lc_date = time(nullptr); struct tm* td = localtime(&lc_date);
		year = td->tm_year + 1900; month = td->tm_mon + 1; day = td->tm_mday; wday = td->tm_wday, yday=td->tm_yday;
		return *this;
	}
	_NODISCARD bool setYMD(unsigned y, unsigned m, unsigned d, unsigned wd = 0) 
	{ 
		if (wd > 6) throw std::string("The week day is incorrect, please choose from 0 to 6!"); 
		year = y; month = m; day = d; return true; 
	}

	_NODISCARD std::string ToString() noexcept
	{
		char str[23];
		sprintf(str,"%.4i-%.2i-%.2i ",this->year, this->month, this->day);
		switch (this->wday)
		{
		case 0:
			strcat(str, week_day[this->wday]);
			break;
		case 1:
			strcat(str, week_day[this->wday]);
			break;
		case 2:
			strcat(str, week_day[this->wday]);
			break;
		case 3:
			strcat(str, week_day[this->wday]);
			break;
		case 4:
			strcat(str, week_day[this->wday]);
			break;
		case 5:
			strcat(str, week_day[this->wday]);
			break;
		default:
			strcat(str, week_day[this->wday]);
			break;
		}
		return str;
	}
	_MAYBEUNUSED bool is_leap_year() noexcept
	{
		if (this->year % 4 == 0 && this->year % 100 != 0)
			return true;
		return false;
	}
	_MAYBEUNUSED unsigned short numberOfDays() noexcept { return is_leap_year() ? 366 : 365; }
};
