#ifndef LdfGemCnv_H
#define LdfGemCnv_H 1

#include "LdfBaseCnv.h"
#include "LdfEvent/Gem.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfGemCnv
 * @brief Concrete converter for the time stored in the TDS /Event/Time
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfGemCnv.h,v 1.1 2004/08/02 21:05:54 heather Exp $
 */ 

class LdfGemCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfGemCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_LdfGem;
  }

protected:

  LdfGemCnv(ISvcLocator* svc);

  virtual ~LdfGemCnv() { };

  /// override the LdfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, LdfEvent::Gem* pObject);



};


#endif // LdfGemCnv_H
