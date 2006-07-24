#ifndef AdfEventCnv_H
#define AdfEventCnv_H 1

#include "LdfBaseCnv.h"

#include "AdfEvent/AdfEvent.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class AdfEventCnv
 * @brief Concrete converter for the Event header stored in the TDS /Event
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/AdfEventCnv.h,v 1.3 2005/01/04 20:36:29 heather Exp $
 */ 

class AdfEventCnv : public LdfBaseCnv { 

  friend class CnvFactory<AdfEventCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_AncillaryDataFormat;
  }

protected:

  AdfEventCnv(ISvcLocator* svc);

  virtual ~AdfEventCnv() { };

  /// override the EbfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the EbfBaseCnv version
  virtual StatusCode updateObj(int* data, AncillaryData::AdfEvent* pObject);


};


#endif // AdfEventCnv_H
