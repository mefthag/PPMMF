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
        /************
         * Le modele
         ***********/
	cRegArchModel myModelArma ;
        cCondMean myCondMeanArma ;
	cCondVar myCondVar ;
        cNormResiduals myNormResid ;
	myModelArma.SetResid(myNormResid) ;
        
        /*********
	 * Partie ARMA pure
	 *******/
	cConst myConst(0.1);

	cAr	myAr(2) ;
	myAr.Set(.8, 0) ;
	myAr.Set(-.2, 1) ;

	cMa myMa(2) ;
	myMa.Set(0.8, 0) ;
	myMa.Set(0.6, 1) ;
        
	myCondMeanArma.SetOneMean(0, myConst) ;
	myCondMeanArma.SetOneMean(1, myAr) ;
	myCondMeanArma.SetOneMean(2, myMa) ;
        
	myModelArma.SetMean(myCondMeanArma) ;
        
        /*********
	 *Partie Garch pure
	 *******/
        cConstCondVar myConstVar(1.0) ;
        
	cArch	myArch(2) ;
	myArch.Set(.9, 0) ;
	myArch.Set(-.1, 1) ;

	cGarch myGarch(2) ;
	myGarch.Set(0.14, 0) ;
	myGarch.Set(0.25, 1) ;
        
        myCondVar.SetOneVar(0, myConstVar) ;
	myCondVar.SetOneVar(1, myArch) ;
	myCondVar.SetOneVar(2, myGarch) ;

	myModelArma.SetVar(myCondVar) ;
        
	cout << "Modele :" ;
	myModelArma.Print() ;

	cRegArchModel myModelArmaCp(myModelArma) ;
	cout << "Copie du modele : " ;
	myModelArmaCp.Print() ;
        
        
	// Observations
	uint myNData = 10 ;
	cRegArchValue myGivenValue(myNData);
	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
            myGivenValue.mYt[t] = t;
	}

	cDVector myMeans(myNData);
  

        // Moyennes et Variances conditionnelles
        myModelArma.GetResid()->Generate(myNData , myGivenValue.mEpst);
	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{    
            myMeans[t] = myCondMeanArma.ComputeMean(t, myGivenValue);
            myGivenValue.mUt[t] = myGivenValue.mYt[t] - myMeans[t];
            //calcul des mHt
            myGivenValue.mHt[t] = (myGivenValue.mUt[t]*myGivenValue.mUt[t])/(myGivenValue.mEpst[t]*myGivenValue.mEpst[t]);
            myGivenValue.mMt[t] = myMeans[t];
                
	}
        
	cout << "Moyennes conditionnelles ARMA pur gaussien : " << endl ;
	myMeans.Print();

        //Simulation 
	uint myNSample = 50;
	cRegArchValue mySimulData = myGivenValue;
	cDVector mySimulVector(myNSample);
	RegArchSimul(myNSample,&mySimulData,myModelArma);
	cout << "Valeurs simulees : " << endl ;
	mySimulVector = mySimulData.mYt;
	mySimulVector.Print();

        // Calcul de vraisemblance
        double myLogLikelihood = 0.;
        myLogLikelihood = RegArchLLH(myModelArma, mySimulData);
        cout << "Log-vraisemblance : " << myLogLikelihood << endl;
        
	return 0;
}

