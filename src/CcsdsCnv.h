#ifndef CcsdsCnv_H
#define CcsdsCnv_H 1

#include "LdfBaseCnv.h"
#include "LdfEvent/LsfCcsds.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class CcsdsCnv
 * @brief Concrete converter for the ccsds items
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/Attic/CcsdsCnv.h,v 1.1.2.1 2006/04/12 07:20:58 heather Exp $
 */ 

class CcsdsCnv : public LdfBaseCnv { 

  friend class CnvFactory<CcsdsCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_LsfCcsds;
  }

protected:

  CcsdsCnv(ISvcLocator* svc);

  virtual ~CcsdsCnv() { };

  /// override the LdfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, LsfEvent::LsfCcsds* pObject);



};


#endif // CcsdsCnv_H
