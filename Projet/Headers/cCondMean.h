#ifndef _CCONDMEAN_H
#define _CCONDMEAN_H_
class cCondMean
{
  public:
    Vector <*cAbstCondMean>;
 
    cCondMean();
    double mcomputeMean(int t,cRegArchValue enst);
};
#endif // _CCONDMEAN_H_
