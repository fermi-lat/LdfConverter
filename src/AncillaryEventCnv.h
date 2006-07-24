#ifndef AncillaryEventCnv_H
#define AncillaryEventCnv_H 1

#include "LdfBaseCnv.h"

//#include "Event/TopLevel/DigiEvent.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class AncillaryEventCnv
 * @brief Concrete converter for the AncillaryEvent stored in the TDS 
 * /Event/AncillaryEvent
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/AncillaryEventCnv.h,v 1.3 2005/01/04 20:36:29 heather Exp $
 */ 

class AncillaryEventCnv : public LdfBaseCnv { 

  friend class CnvFactory<AncillaryEventCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_AncillaryEvent;
  }

protected:

  AncillaryEventCnv(ISvcLocator* svc);

  virtual ~AncillaryEventCnv() { };

  /// override the EbfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the EbfBaseCnv version
  virtual StatusCode updateObj(int* data, DataObject* pObject);


};


#endif // AncillaryEventCnv_H
