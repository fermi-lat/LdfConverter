#ifndef LdfTimeCnv_H
#define LdfTimeCnv_H 1

#include "LdfBaseCnv.h"

#include "LdfEvent/LdfTime.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfTimeCnv
 * @brief Concrete converter for the time stored in the TDS /Event/Time
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfTimeCnv.h,v 1.1.1.1 2004/05/13 22:02:49 heather Exp $
 */ 

class LdfTimeCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfTimeCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_LdfTime;
  }

protected:

  LdfTimeCnv(ISvcLocator* svc);

  virtual ~LdfTimeCnv() { };

  /// override the LdfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, LdfEvent::LdfTime* pObject);


};


#endif // LdfTimeCnv_H
