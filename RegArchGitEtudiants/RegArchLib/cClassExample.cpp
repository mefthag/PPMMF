#include "cClassExample.h"

/*!
 \file cClassExample.cpp
 \brief sources for class cClassExample methods.

 \author Jean-Baptiste Durand, Ollivier TMAAMASCO
 \date nov-17-2017 - Last change nov-17-2017 
*/
namespace RegArchLib {
	/*!
	 * \fn cClassExample::cClassExample(uint theNParams)
	 * \param int theNParams: number of parameters.
	 */

	cClassExample::cClassExample(uint theNParams)
	{
		mvParams.ReAlloc(theNParams) ;
		MESS_CREAT("cClassExample")
	}

	/*!
	 * \fn cClassExample::cClassExample(const cDVector& theClassExample):cAbstCondMean(eMa)
	 * \param const cDVector& theAr: vector of AR coefficients.
	 */
	cClassExample::cClassExample(const cDVector& theClassExample)
	{
		mvParams = theClassExample ;
		MESS_CREAT("cClassExample")
	}

	/*!
	 * \fn cClassExample::~cClassExample()
	 */
	cClassExample::~cClassExample()
	{
		mvParams.Delete() ;
		MESS_DESTR("cClassExample")
	}


	/*!
	 * \fn void cClassExample::Delete(void)
	 * \param void
	 */
	void cClassExample::Delete(void)
	{
		mvParams.Delete() ;
	}

	/*!
	 * \fn void cClassExample::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cClassExample::Print(ostream& theOut) const
	{
	uint myNParams = mvParams.GetSize();
		theOut << "cClassExample (" << myNParams <<  "parameters):" << endl ;
		for (register uint i = 0 ; i <  myNParams ; i++)
			theOut << "\tcClassExample[" << i+1 << "]=" << mvParams[i] << endl ;
	}

	/*!
	 * \fn void cClassExample::Set(double theValue, uint theIndex=0)
	 * \param double theValue: the theIndex th value
	 * \param uint theIndex: the index
	 * \details mvParams[theIndex] = theValue
	 */
	void cClassExample::Set(double theValue, uint theIndex)
	{
		if (theIndex >= mvParams.GetSize())
			throw cError("Bad index") ;
		else
			mvParams[theIndex]=theValue ;
	}

	/*!
	 * \fn void cClassExample::Set(const cDVector& theVectParam)
	 * \param const cDVector& theVectParam: the vector of parameters
	 * \details mvParams = theVectParam
	 */
	void cClassExample::Set(const cDVector& theVectParam)
	{
		mvParams=theVectParam ;
	}

	double cClassExample::Get(uint theIndex)
	{
		return mvParams[theIndex] ;
	}

	/*!
	 * \fn void cClassExample::ReAlloc(uint theSize)
	 * \param uint theSize: new size of mvMA
	 * \details new allocation of mvParams 
	 */
	void cClassExample::ReAlloc(uint theSize)
	{
		mvParams.ReAlloc(theSize) ;
	}

	/*!
	 * \fn void cAr::ReAlloc(const cDVector& theVectParam)
	 * \param const cDVector& theVectParam: the vector of AR coefficients
	 * \details new allocation of mvAr
	 */
	void cClassExample::ReAlloc(const cDVector& theVectParam)
	{
		mvParams = theVectParam ;
	}

	uint cClassExample::GetNParam(void) const
	{
		return mvParams.GetSize() ;
	}

	void cClassExample::copy(const cClassExample& theClassExample)
	{
		mvParams = theClassExample.mvParams;
	}

}//namespace
