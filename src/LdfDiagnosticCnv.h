#ifndef LdfDiagnosticCnv_H
#define LdfDiagnosticCnv_H 1

#include "LdfBaseCnv.h"
#include "LdfEvent/DiagnosticData.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;

/** @class LdfDiagnosticCnv
 * @brief Concrete converter for the EM Diagnostic data stored in the TDS /Event/Diagnostic
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfDiagnosticCnv.h,v 1.2 2004/05/13 22:40:41 heather Exp $
 */ 

class LdfDiagnosticCnv : public LdfBaseCnv { 

  friend class CnvFactory<LdfDiagnosticCnv>;

public: 
  static const CLID& classID()   
  {
    return CLID_LdfDiagnosticData;
  }

protected:

  LdfDiagnosticCnv(ISvcLocator* svc);

  virtual ~LdfDiagnosticCnv() { };

  /// override the LdfBaseCnv version to handle the conversion
  virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);

  /// override the LdfBaseCnv version
  virtual StatusCode updateObj(int* data, LdfEvent::DiagnosticData* pObject);


};


#endif // LdfDiagnosticCnv_H
