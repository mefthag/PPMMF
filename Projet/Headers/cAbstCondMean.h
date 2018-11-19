#ifndef _CABSTCONDMEAN_H
#define _CABSTCONDMEAN_H_
class cAbstCondMean
{
  public:
    Vector <double> mparam;
 
    cAbstCondMean();

    cAbstCondMean mPtrCopy();
    virtual double mcomputeMean(int t,cRegArchValue enst) = 0;
};

#endif // _CABSTCONDMEAN_H_
