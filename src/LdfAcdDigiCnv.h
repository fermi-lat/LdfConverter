#ifndef LdfAcdDigiCnv_H
#define LdfAcdDigiCnv_H 1

#include "LdfBaseCnv.h"

namespace Event{ class EventHeader; }
extern const CLID& CLID_AcdDigi;

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfAcdDigiCnv
 * @brief Concrete converter for the Event header stored in the TDS /Event
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfAcdDigiCnv.h,v 1.1.1.1 2004/05/13 22:02:48 heather Exp $
 */ 

class LdfAcdDigiCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfAcdDigiCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_AcdDigi;
  }

protected:

  LdfAcdDigiCnv(ISvcLocator* svc);

  virtual ~LdfAcdDigiCnv() { };

  /// override the EbfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, Event::EventHeader* pObject);


};


#endif // LdfAcdDigiCnv_H
