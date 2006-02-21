#ifndef MetaEventCnv_H
#define MetaEventCnv_H 1

#include "LdfBaseCnv.h"
#include "LdfEvent/LsfMetaEvent.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class MetaEventCnv
 * @brief Concrete converter for the time stored in the TDS /Event/Time
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/MetaEvent.h,v 1.2 2005/01/04 20:36:29 heather Exp $
 */ 

class MetaEventCnv : public LdfBaseCnv { 

  friend class CnvFactory<MetaEventCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_MetaEvent;
  }

protected:

  MetaEventCnv(ISvcLocator* svc);

  virtual ~MetaEventCnv() { };

  /// override the LdfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, LsfEvent::MetaEvent* pObject);



};


#endif // MetaEventCnv_H
