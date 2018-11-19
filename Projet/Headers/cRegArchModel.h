#ifndef _CREGARCHMODEL_H
#define _CREGARCHMODEL_H_

class cRegArchModel
{
  public:
    cCondMean *condMean_;
    cCondVar *condVar_;
    cAbstResiduals *abstResiduals_;
 
    cRegArchModel();
    void msimulate(int t);
    double mloglikelihood();
};
#endif // _CREGARCHMODEL_H_
