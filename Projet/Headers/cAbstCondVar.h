#ifndef _CABSTCONDVAR_H
#define _CABSTCONDVAR_H_
class cAbstCondVAR
{
  public:
    Vector <double> mparam;
 
    cAbstCondVAR();

    virtual double mcomputeVar(int t,cRegArchValue cst) = 0;
};

#endif // _CABSTCONDVAR_H_
