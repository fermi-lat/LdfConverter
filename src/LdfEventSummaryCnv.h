#ifndef LDFEVENTCNV_H
#define LDFEVENTCNV_H 1

#include "LdfBaseCnv.h"
#include "LdfEvent/EventSummaryData.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfEventSummaryCnv
 * @brief Concrete converter for the Event header stored in the TDS /Event
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfEventSummaryCnv.h,v 1.1.1.1 2004/05/13 22:02:49 heather Exp $
 */ 

class LdfEventSummaryCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfEventSummaryCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_LdfEventSummaryData;
  }

protected:

  LdfEventSummaryCnv(ISvcLocator* svc);

  virtual ~LdfEventSummaryCnv() { };

  /// override the EbfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the EbfBaseCnv version
  virtual StatusCode updateObj(int* data, LdfEvent::EventSummaryData* pObject);


};


#endif // LdfEventCNV_H
