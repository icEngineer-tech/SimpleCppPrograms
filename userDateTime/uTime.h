#pragma once
#include "macros.h"
#include <ctime>
#include<string>

class uTime
{
	int hour, minute, second;
	std::string timeFormat;
	bool set12Hour = false;
public:
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }
	std::string getTimeFormat()const { return timeFormat; }
	_MAYBEUNUSED void setHMS(int h, int m, int s) { hour = h; minute = m; second = s; }
	_NODISCARD void setTime(uTime time) { hour = time.hour; minute = time.minute; second = time.second; }
	_NODISCARD void setTimeFormat(std::string t_f) { timeFormat = t_f; }
	_NODISCARD uTime& getCurrentSystemTime() noexcept
	{
		time_t lc_time = time(nullptr); struct tm* td = localtime(&lc_time);
		hour = td->tm_hour;
		minute = td->tm_min;
		second = td->tm_sec;
		return *this;
	}
	_NODISCARD std::string ToString()
	{
		char str[10];
		sprintf(str, "%.2i:%.2i:%.2i ", this->hour, this->minute, this->second);
		return str;
	}
	_NODISCARD bool is_am()const { if (this->getTimeFormat() == "AM")return true; return false; }
	_NODISCARD bool is_pm()const { if (this->getTimeFormat() == "PM")return true; return false; }
	_NODISCARD bool is_12_hour()const { if (this->getTimeFormat() == "")return false; return true; }
	_NODISCARD bool is_24_hour()const { if (this->getTimeFormat() != "")return false; return true; }
#ifdef _SET_12_HOUR__
#define _UTIME_
	_NODISCARD bool set12hour() noexcept
	{
		_UNLIKELY if (set12Hour != false)
			return false;
		if (this->hour > 11)
		{
			setTimeFormat("PM");
			if (this->hour > 12)
			{
				int helper_h = this->hour - 12;
				setHMS(helper_h, this->minute, this->second);
			}
		}
		else
			setTimeFormat("AM");
		return true;
	}
#else
	_NODISCARD bool set24hour()
	{
		_UNLIKELY if (set12Hour != true)
			return false;
		setTimeFormat("");
		return true;
	}	
#endif

	friend std::ostream& operator<<(std::ostream&, const uTime&);
};
