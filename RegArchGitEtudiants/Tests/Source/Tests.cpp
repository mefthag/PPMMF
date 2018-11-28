// Test.cpp : definit le point d'entree pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"
#include "StdAfxRegArchLib.h"

using namespace ErrorNameSpace;
using namespace VectorAndMatrixNameSpace;
using namespace RegArchLib ;

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif //WIN32
{
	cout.precision(12) ;

	/*********
	 * ARMA pur
	 *******/
	cConst myConst(0.1);

	cAr	myAr(2) ;

	myAr.Set(.8, 0) ;
	myAr.Set(-.2, 1) ;
	myAr.Print() ;

	cMa myMa(2) ;
	myMa.Set(0.8, 0) ;
	myMa.Set(0.6, 1) ;
        

	cCondMean myCondMeanArma ;
	myCondMeanArma.SetOneMean(0, myConst) ;
	myCondMeanArma.SetOneMean(1, myAr) ;
	myCondMeanArma.SetOneMean(2, myMa) ;

	cConstCondVar myConstVar(1.0) ;

	cCondVar myCondVar ;
	myCondVar.SetOneVar(0, myConstVar) ;

	cNormResiduals myNormResid ;

	cRegArchModel myModelArma ;
	myModelArma.SetMean(myCondMeanArma) ;
	/*myModelArma.SetVar(myCondVar) ;
	myModelArma.SetResid(myNormResid) ;
	cout << "Modele : " ;
	myModelArma.Print() ;

	cRegArchModel myModelArmaCp(myModelArma) ;
	cout << "Copie du modele : " ;
	myModelArmaCp.Print() ;*/

        
        /*********
	 *Garch pur
	 *******/
	

	cArch	myArch(2) ;

	myArch.Set(.9, 0) ;
	myArch.Set(-.1, 1) ;
	myArch.Print() ;

	cGarch myGarch(2) ;
	myGarch.Set(0.14, 0) ;
	myGarch.Set(0.65, 1) ;
        

	
	
	myCondVar.SetOneVar(1, myArch) ;
	myCondVar.SetOneVar(2, myGarch) ;



	myModelArma.SetVar(myCondVar) ;
        
	myModelArma.SetResid(myNormResid) ;
	cout << "Modele : " ;
	myModelArma.Print() ;

	cRegArchModel myModelArmaCp(myModelArma) ;
	cout << "Copie du modele : " ;
	myModelArmaCp.Print() ;
        
	// Observations
	uint myNData = 50 ;
	cRegArchValue myGivenValue(myNData);
	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
		myGivenValue.mYt[t] = t;
	}

	cDVector myMeans(myNData);
  
         
        
        
        
        
        ///////////////////////////////////////////////////////////////////////////////////////////////
        // Moyennes conditionnelles
        myModelArma.GetResid()->Generate(myNData , myGivenValue.mEpst);
	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{    
		myMeans[t] = myCondMeanArma.ComputeMean(t, myGivenValue);
		myGivenValue.mUt[t] = myGivenValue.mYt[t] - myMeans[t];
		myGivenValue.mHt[t] = (myGivenValue.mUt[t]*myGivenValue.mUt[t])/(myGivenValue.mEpst[t]*myGivenValue.mEpst[t]);
                myGivenValue.mMt[t] = myMeans[t];
                
	}
        
	cout << "Moyennes conditionnelles ARMA pur gaussien : " << endl ;
	myMeans.Print();


        
        
        
	//Simulation
	uint myNSample = 54;
	cRegArchValue mySimulData = myGivenValue;
	cDVector mySimulVector(myNSample);
	cRegArchValue myGivenValue2 = RegArchSimul(myNSample,mySimulData,myModelArma);
	cout << "Valeurs simulees : " << endl ;
	mySimulVector = myGivenValue2.mYt;
	mySimulVector.Print();

        // Calcul de vraisemblance
        double myLoglikelihood = 0.;
        myLoglikelihood = RegArchLLH(myModelArma, myGivenValue);
        cout << "Log-vraisemblance : " << myLoglikelihood << endl;
        
	return 0 ;


}

