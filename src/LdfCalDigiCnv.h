#ifndef LdfCalDigiCnv_H
#define LdfCalDigiCnv_H 1

#include "LdfBaseCnv.h"

#include "Event/Digi/CalDigi.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfCalDigiCnv
 * @brief Concrete converter for the Event header stored in the TDS /Event
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfCalDigiCnv.h,v 1.2 2004/12/18 17:23:19 usher Exp $
 */ 

class LdfCalDigiCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfCalDigiCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_CalDigi;
  }

protected:

  LdfCalDigiCnv(ISvcLocator* svc);

  virtual ~LdfCalDigiCnv() { };

  /// override the EbfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, Event::CalDigi* pObject);


};


#endif // LdfCalDigiCnv_H
