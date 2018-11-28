#pragma once 
#ifndef _REGARCHCOMPUTE_H_
#define _REGARCHCOMPUTE_H_

#include "cRegArchModel.h"
#include "cRegArchValue.h"

/*!
 \file RegArchCompute.h
 \brief Header for simulation / estimation of general RegArch models.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
// please complete function profile
cRegArchValue extern _DLLEXPORT_ RegArchSimul(uint Time, cRegArchValue myData, cRegArchModel model) ; ///< Simulation of a general RegArch Model}

double extern _DLLEXPORT_ RegArchLLH(cRegArchModel myModel, cRegArchValue myGivenValue);
}
#endif //_REGARCHCOMPUTE_H_
