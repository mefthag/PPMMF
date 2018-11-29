#include "StdAfxRegArchLib.h"
/*!
	\file RegArchCompute.cpp
	\brief implementation of the Simulation / Estimation procedures for general RegArchModel
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/
namespace RegArchLib {

    /*cRegArchValue RegArchSimul(uint Time, cRegArchValue myData, cRegArchModel model){
        cRegArchValue myGivenValue(Time);
        model.GetResid()->Generate(Time, myGivenValue.mEpst);
	for(int i=0; i < myData.mYt.GetSize(); i++){
	    myGivenValue.mHt[i] = model.mVar->ComputeVar(i, myData);
	    myGivenValue.mUt[i] = sqrt(myData.mHt[i])*myData.mEpst[i];
	    myGivenValue.mMt[i] = model.mMean->ComputeMean(i, myData);
	    myGivenValue.mYt[i] = myData.mMt[i] + myData.mUt[i];
	}
        for(int i=myData.mYt.GetSize(); i < Time ; i++){
	    myGivenValue.mHt[i] = model.mVar->ComputeVar(i, myGivenValue);
	    myGivenValue.mUt[i] = sqrt(myGivenValue.mHt[i])*myGivenValue.mEpst[i];
	    myGivenValue.mMt[i] = model.mMean->ComputeMean(i, myGivenValue);
	    myGivenValue.mYt[i] = myGivenValue.mMt[i] + myGivenValue.mUt[i];
	}
        return myGivenValue;
    };*/
    
    void RegArchSimul(uint Time, cRegArchValue* myData, cRegArchModel model){
	myData->ReAlloc(Time);
        model.GetResid()->Generate(Time, myData->mEpst);
	for(int i=0; i < Time; i++){
	    myData->mHt[i] = model.mVar->ComputeVar(i, *myData);
	    myData->mUt[i] = sqrt(myData->mHt[i])*myData->mEpst[i];
	    myData->mMt[i] = model.mMean->ComputeMean(i, *myData);
	    myData->mYt[i] = myData->mMt[i] + myData->mUt[i];
	}
        
    };

   
    double RegArchLLH(cRegArchModel myModel, cRegArchValue myGivenValue){
	 double llh = 0;
        for (uint i = 0 ; i < myGivenValue.mYt.GetSize() ; i++){
            llh += -1/2*log(myGivenValue.mHt[i])+ myModel.GetResid()->LogDensity(myGivenValue.mUt[i]/sqrt(myGivenValue.mHt[i]));
        }        
        return llh;
    }


}//namespace
