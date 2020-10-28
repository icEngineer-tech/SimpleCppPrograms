#include "uDateTime.h"


uDateTime::uDateTime()
	:uDate(0,0,0,0,0),uTime(0,0,0,"")
{
	uTime::getCurrentSystemTime();
	uDate::getCurrentDate();
}
uDateTime::uDateTime(uTime time, uDate date)
	: uTime(time),uDate(date)
{}
_NODISCARD bool uDateTime::setDateTime(uDateTime DateTime)
{
	if (DateTime.wday > 6)
		throw std::string("The week day is incorrect, please choose from 0 to 6!");
	uTime::setHMS(DateTime.hour, DateTime.minute, DateTime.second);
	uDate::setYMD(DateTime.year, DateTime.month, DateTime.day);
	return true;
}
_MAYBEUNUSED std::string uDateTime::getCurrentDateTime()
{
	uTime::getHour();
	uTime::getMinute();
	uTime::getSecond();
	std::string strTime = uTime::ToString();
	std::string strDate = uDate::ToString();
	std::string str = strDate + " " + strTime + uTime::getTimeFormat();
	return str;
}
