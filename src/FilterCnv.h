#ifndef CNV_FilterCnv_H 
#define CNV_FilterCnv_H 1

static const CLID& CLID_Filter = InterfaceID("Filter", 1, 0);

/*

#include "LdfBaseCnv.h"

class IDataDirectory;
class ISvcLocator;
namespace Event {
}
// Abstract factory to create the converter
template <class T> class CnvFactory;
*/

/** @class FilterCnv
* @brief Concrete converter for the Filter header on the TDS /Event/Filter
*
* $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/FilterCnv.h,v 1.2 2008/07/03 16:47:38 heather Exp $
*/
/*
class FilterCnv : public LdfBaseCnv { 
    friend class CnvFactory<FilterCnv>;
public:
    
    FilterCnv(ISvcLocator* svc);
    
    virtual ~FilterCnv() { };
    static const CLID& classID();
    
    /// Create object
    virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);
    
private:
};
*/
#endif // CNV_FilterCnv_H

