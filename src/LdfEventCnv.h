#ifndef LdfEventCnv_H
#define LdfEventCnv_H 1

#include "LdfBaseCnv.h"

#include "Event/TopLevel/Event.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfEventCnv
 * @brief Concrete converter for the Event header stored in the TDS /Event
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/LdfConverter/src/LdfEventCnv.h,v 1.3.654.1 2010/10/08 16:34:25 heather Exp $
 */ 

class LdfEventCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfEventCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_Event;
  }

//protected:

  LdfEventCnv(ISvcLocator* svc);

  virtual ~LdfEventCnv() { };

  /// override the EbfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the EbfBaseCnv version
  virtual StatusCode updateObj(int* data, Event::EventHeader* pObject);


};


#endif // LdfEventCnv_H

