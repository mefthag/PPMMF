#include "StdAfxRegArchLib.h"
/*!
	\file RegArchCompute.cpp
	\brief implementation of the Simulation / Estimation procedures for general RegArchModel
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/
namespace RegArchLib {

    void RegArchSimul(uint Time, cRegArchValue* myData, cRegArchModel model){
	myData->ReAlloc(Time);
	for (int i=0; i < Time, i++){
	    myData->mHt[i] = model.mVar->ComputeVar(i, *myData);
	    myData->mEpst[i] = ;
	    myData->mUt[i] = sqrt(mHt[i])*mEpst[i];
	    myData->mMt[i] = model.mMean->ComputeMean(i, *myData);
	    myData->mYt[i] = myData->mMt[i] + myData->mUt[i];
	}
    };

} //namespace
