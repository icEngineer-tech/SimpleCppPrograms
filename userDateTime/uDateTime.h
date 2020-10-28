#pragma once

#pragma warning(disable:4996)
#include"uTime.h"
#include "uDate.h"
#include <iostream>


class uDateTime: uTime,uDate
{
	
public:
	uDateTime();
	uDateTime(uTime, uDate);
	_NODISCARD bool setDateTime(uDateTime DateTime);
	_MAYBEUNUSED std::string getCurrentDateTime();
};
