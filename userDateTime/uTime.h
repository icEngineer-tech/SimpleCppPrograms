#pragma once
#include "macros.h"
#include <ctime>
#include <memory>
#include<string>
#include <string_view>
#include <chrono>

class uTime
{
protected:
	unsigned hour, minute, second;
	std::string timeFormat;
	bool set12Hour;
	enum class tz 
	{ 
		UTC_MINUS_12, UTC_MINUS_11, UTC_MINUS_10, UTC_MINUS_930, UTC_MINUS_9, UTC_MINUS_8, UTC_MINUS_7, UTC_MINUS_6,
		UTC_MINUS_5, UTC_MINUS_4, UTC_MINUS_3, UTC_MINUS_2, UTC_MINUS_1, UTC_0, UTC_PLUS_1, UTC_PLUS_2, UTC_PLUS_3, UTC_PLUS_4,
		UTC_PLUS_5, UTC_PLUS_6, UTC_PLUS_7, UTC_PLUS_8, UTC_PLUS_9, UTC_PLUS_10, UTC_PLUS_11, UTC_PLUS_12, UTC_PLUS_13, UTC_PLUS_14
	};
public:
	uTime():hour(0),minute(0),second(0),timeFormat{""},set12Hour(false){}
	uTime(unsigned hour, unsigned minute, unsigned second, std::string Format)
		:hour(hour),minute(minute),second(second),timeFormat(Format), set12Hour(false){}
	unsigned getHour()const { return hour; }
	unsigned getMinute()const { return minute; }
	unsigned getSecond()const { return second; }
	std::string getTimeFormat()const { return timeFormat; }
	_MAYBEUNUSED void setHMS(unsigned h, unsigned m, unsigned s) { hour = h; minute = m; second = s; }
	_NODISCARD void setTime(uTime time) { hour = time.hour; minute = time.minute; second = time.second; }
	_NODISCARD void setTimeFormat(std::string t_f) { timeFormat = t_f; }
	_NODISCARD uTime& getCurrentSystemTime() noexcept
	{
		time_t lc_time = time(nullptr); struct tm* td = localtime(&lc_time);
		hour = td->tm_hour;
		minute = td->tm_min;
		second = td->tm_sec;
		if (is_am())
			timeFormat = "AM";
		else
			timeFormat = "PM";
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
		if (set12Hour != false) _UNLIKELY
			return false;
		if (this->hour > 11) 
		{
			setTimeFormat("PM");
			if (this->hour > 12)
			{
				unsigned helper_h = this->hour - 12;
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
	_NODISCARD std::string localZone(std::string_view str_v)
	{
		//implement a database from time_zone.txt using enum class tz
	}
	friend std::ostream& operator<<(std::ostream&, const uTime&);
};
