#ifndef LdfDigiCnv_H
#define LdfDigiCnv_H 1

#include "LdfBaseCnv.h"

namespace Event{ class EventHeader; }

#include "Event/TopLevel/DigiEvent.h"
//extern const CLID& CLID_DigiEvent;

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfDigiCnv
 * @brief Concrete converter for the Event header stored in the TDS /Event
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfDigiCnv.h,v 1.1.1.1 2004/05/13 22:02:48 heather Exp $
 */ 

class LdfDigiCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfDigiCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_DigiEvent;
  }

protected:

  LdfDigiCnv(ISvcLocator* svc);

  virtual ~LdfDigiCnv() { };

  /// override the EbfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the EbfBaseCnv version
  virtual StatusCode updateObj(int* data, Event::EventHeader* pObject);


};


#endif // LdfDigiCnv_H
