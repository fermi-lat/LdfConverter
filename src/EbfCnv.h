#ifndef EbfCnv_H
#define EbfCnv_H 1

#include "LdfBaseCnv.h"
#include "EbfWriter/Ebf.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class EbfCnv
 * @brief Concrete converter for the EBF event 
 *
 * $Header: /usr/local/CVS/SLAC/LdfConverter/src/Attic/EbfCnv.h,v 1.1.2.1 2007/11/14 13:05:06 heather Exp $
 */ 

class EbfCnv : public LdfBaseCnv { 

  friend class CnvFactory<EbfCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_Ebf;
  }

protected:

  EbfCnv(ISvcLocator* svc);

  virtual ~EbfCnv() { };

  /// override the LdfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, EbfWriterTds::Ebf* pObject);



};


#endif // EbfCnv_H
