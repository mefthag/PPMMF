#ifndef _CABSTRESIDUALS_H
#define _CABSTRESIDUALS_H_
class cAbstResiduals
{
  public:
    int mSeed;
 
    Vector <double> mParam;
    cAbstResiduals();

    virtual Vector <double> mSimulate(int t,cRegArchValue cst) = 0;
    virtual double mLogDens(double x) = 0;
    virtual void mGradient(double x, *Vector<deouble> par) = 0;
};
#endif // _CABSTRESIDUALS_H_
