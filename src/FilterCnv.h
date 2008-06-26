#ifndef CNV_FilterCnv_H 
#define CNV_FilterCnv_H 1

#include "LdfBaseCnv.h"

class IDataDirectory;
class ISvcLocator;
namespace Event {
}
// Abstract factory to create the converter
template <class T> class CnvFactory;

/** @class FilterCnv
* @brief Concrete converter for the Filter header on the TDS /Event/Filter
*
* $Header: /usr/local/CVS/SLAC/LdfConverter/src/Attic/FilterCnv.h,v 1.1.2.1 2007/11/14 13:05:06 heather Exp $
*/
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
#endif // CNV_FilterCnv_H

