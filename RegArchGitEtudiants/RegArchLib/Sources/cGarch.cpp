#include "StdAfxRegArchLib.h"
/*!
	\file cGarch.cpp
	\brief sources for class cGarch methods.

	\author Jean-Baptiste DURAND, Ollivier TARAMASCO
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cGarch::cGarch(uint theNGarch):cAbstCondVar(eGarch)
	 * \param uint theNGarch: number of GARCH lags
	*/
	cGarch::cGarch(uint theNGarch)
	:cAbstCondVar(eGarch)  // call constructor of cAbstCondVar with type eGarch
	{
		mvGarch.ReAlloc(theNGarch) ;
		MESS_CREAT("cGarch") ;
	}

	/*!
	 * \fn cGarch::cGarch(cDVector& theGarch):cAbstCondVar(eGarch)
	 * \param cDVector& theGarch theGarch: GARCH parameters
	*/
	cGarch::cGarch(cDVector& theGarch):cAbstCondVar(eGarch)
	{
		mvGarch = theGarch ;
		MESS_CREAT("cGarch") ;
	}

	/*!
	 * \fn cGarch::~cGarch()
	*/
	cGarch::~cGarch()
	{	mvGarch.Delete() ;
		MESS_DESTR("cGarch") ;
	}

	/*!
	 * \fn cAbstCondVar* cGarch::PtrCopy()
	 */

	cGarch* cGarch::PtrCopy() const
	{
	    cGarch*  copie =  new cGarch();
            copie->copy(*this);
            return  copie;
	}

	/*!
	 * \fn void cGarch::Delete(void)
	 * \param void
	 * \details Free memory
	 */
	void cGarch::Delete(void)
	{
		mvGarch.Delete() ;
	}
	/*!
	 * \fn void cGarch::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cGarch::Print(ostream& theOut) const
	{
	uint myNGarch = mvGarch.GetSize() ;
		theOut << "GARCH(" << myNGarch << ") model with:" << endl ;
		for (register uint j = 0 ; j < myNGarch ; j++)
			theOut << "\tGARCH[" << j+1 << "]=" << mvGarch[j] << endl ;
	}

	/*!
	 * \fn void cGarch::ReAlloc(uint theSize, uint theNumParam)
	 * \param uint theSize: new size of mvArch or mvGarch
	 * \param uint theNumParam: 0 for mvGarch.
	 * \details new allocation of mvGarch
	 */
	void cGarch::ReAlloc(uint theSize, uint theNumParam)
	{
		switch (theNumParam)
		{	case 0 :
				mvGarch.ReAlloc(theSize) ;
			break ;
			default :
	//			throw cError("cGarch::ReAlloc - theNumParam must be 0.") ;
			break ;
		}
	}

	/*!
	 * \fn void cGarch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of GARCH coefficients
	 * \param uint theNumParam: =0, theGARCH Coefficients
	 * \details new allocation of mvGarch
	 */
	void cGarch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	{	switch (theNumParam)
		{	case 0:
				mvGarch = theVectParam ;
			break ;
			default :
				throw cError("cGarch::ReAlloc - theNumParam must be 0") ;
			break ;
		}
	}

	/*!
	 * \fn void cGarch::Set(double theValue, uint theIndex, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param double theValue: the value of the "theIndex" th lag. Default 0.
	 * \param uint theIndex: the index.
	 * \param uint theNumParam: =0, GARCH parameters
	 * \details mvGarch[theIndex]= theValue
	 */
	void cGarch::Set(double theValue, uint theIndex, uint theNumParam)
	{	switch (theNumParam)
		{	case 0 :
				if (theIndex < mvGarch.GetSize())
					mvGarch[theIndex] = theValue ;
				else
					throw cError("cGarch::Set - wrong index") ;
			break ;
			default:
				throw cError("cGarch::Set - theNumParam must be 0") ;
			break ;
		}
	}

	/*!
	 * \fn void cGarch::Set(const cDVector& theVectParam, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the vector of values
	 * \param uint theNumParam: =0, GARCH parameters
	 * \details mvGarch = theVectParam
	 */
	void cGarch::Set(const cDVector& theVectParam, uint theNumParam)
	{	switch (theNumParam)
		{	case 0 :
				mvGarch = theVectParam ;
			break ;
			default:
				throw cError("cGarch::Set - theNumParam must be 0") ;
			break ;
		}
	}

	double  cGarch::Get(uint theIndex, uint theNumParam)
	{
		switch (theNumParam)
		{
			case 0 :
				return mvGarch[theIndex] ;
			break ;
			default:
				throw cError("cGarch::Get - theNumParam must be 0") ;
			break ;
		}
	}

	/*!
	 * \fn double cGarch::ComputeVar(uint theDate, const cRegArchValue& theData) const
	 * \param int theDate: date of computation
	 * \param const cRegArchValue& theData: past datas
	 * \details theData is not updated here.
	*/
	double cGarch::ComputeVar(uint theDate, const cRegArchValue& theData) const
	{
	    	uint q = mvGarch.GetSize();
		double cGarchMean = 0;
		for (register uint l = 0; l < min(q,theDate); l++){
			cGarchMean += mvGarch[l] * theData.mHt[theDate-l-1];
		}
		return cGarchMean;

	}

	uint cGarch::GetNParam(void) const
	{
		return mvGarch.GetSize() ;
	}

	void cGarch::copy(const cGarch& theGarch)
	{
		mvGarch = theGarch.mvGarch;
	}


}//namespace
