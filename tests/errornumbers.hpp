#pragma once
#ifndef ERRORNUMBERS_HPP
#define ERRORNUMBERS_HPP

#include "../deps.hpp"

//	This should really be in a self-contained CSV file
//	Error Message Look Up Table

unsigned int getErrorNumber(string errorMsg);
void logError(string errmsg, ofstream &output);

#endif	//	ERRORNUMBERS_HPP



//	TODO:
//	If we're being pedantic, this theoretically needs unit tests as well.  But I'm not that much of a pedant
//
//


