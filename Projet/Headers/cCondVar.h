#ifndef _CCONDVAR_H
#define _CCONDVAR_H_
class cCondVar
{
  public:

    Vector<*cAbstCondVar> vAbstCondVar;
 
    cCondVar();
    double mComputeVar(int t, cRegArchValue cst);
};
#endif // _CCONDVAR_H_
