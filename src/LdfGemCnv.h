#ifndef LdfGemCnv_H
#define LdfGemCnv_H 1

#include "LdfBaseCnv.h"
namespace LdfEvent { class LdfGem; }

extern const CLID& CLID_LdfGem;

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfGemCnv
 * @brief Concrete converter for the time stored in the TDS /Event/Time
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfGemCnv.h,v 1.1.1.1 2004/05/13 22:02:49 heather Exp $
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
  virtual StatusCode updateObj(int* data, LdfEvent::LdfGem* pObject);



};


#endif // LdfGemCnv_H
