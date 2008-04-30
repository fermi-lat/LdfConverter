#ifndef LdfAcdDigiCnv_H
#define LdfAcdDigiCnv_H 1

#include "LdfBaseCnv.h"

#include "Event/Digi/AcdDigi.h"

// Abstract factory to create the converter
template <class TYPE> class CnvFactory;


/** @class LdfAcdDigiCnv
 * @brief Concrete converter for the Event header stored in the TDS /Event
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfAcdDigiCnv.h,v 1.4 2005/01/04 20:36:28 heather Exp $
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
  virtual StatusCode updateObj(int* data, Event::AcdDigi* pObject);

  void LdfAcdDigiCnv::base10ToAcdId(unsigned int val, short &lay, short &face, 
                          short &row, short &col);


  bool createAcdDigi(Event::AcdDigiCol*& digiCol, unsigned int bitWord, int face, int offset, 
                     int maxRow, int maxCol);

};


#endif // LdfAcdDigiCnv_H
