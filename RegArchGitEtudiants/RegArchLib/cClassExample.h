#pragma once 
#ifndef _CCLASSEXAMPLE_H_
#define _CCLASSEXAMPLE_H_

#include "StdAfxVectorAndMatrix.h"
/*!
	\file cClassExample.h
	\brief header for dummy class cClassExample.
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO
	\date nov-17-2017 - Last change nov-17-2017 
*/
namespace RegArchLib {
	/*! 
	 * \class cClassExample
	 * \brief  Example of a C++ class with parameters (print, set, ...)
	 */
	class _DLLEXPORT_ cClassExample
	{
	private :
		cDVector mvParams ;
	public :
		cClassExample(uint theNParams = 0) ; ///< A simple constructor
		cClassExample(const cDVector& theParams) ; ///< Another constructor
		virtual ~cClassExample() ;  ///< A simple destructor
		void Delete(void) ; ///< Free memory
		void Print(ostream& theOut=cout) const ; ///< Print the parameters
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam) ; ///< Allocation of the model parameters
		void Set(double theValue, uint theIndex=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam) ; ///< Set model parameters.
		double Get(uint theIndex=0) ;
		uint GetNParam(void) const ;
	protected :
		void copy(const cClassExample& theClassExample) ; /// < Copy attribute from instance
	} ;

}

#endif // _CCLASSEXAMPLE_H_
