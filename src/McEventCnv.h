#ifndef CNV_McEventCnv_H 
#define CNV_McEventCnv_H 1

#include "LdfBaseCnv.h"

class IDataDirectory;
class ISvcLocator;
namespace Event {
class MCEvent;
}
// Abstract factory to create the converter
template <class T> class CnvFactory;

/** @class McEventCnv
* @brief Concrete converter for the McEvent header on the TDS /Event/MC
*
* $Header: /nfs/slac/g/glast/ground/cvs/GlastSvc/src/EventSelector/McEventCnv.h,v 1.6 2002/09/13 16:14:34 burnett Exp $
*/
class McEventCnv : public LdfBaseCnv { 
    friend class CnvFactory<McEventCnv>;
public:
    
    McEventCnv(ISvcLocator* svc);
    
    virtual ~McEventCnv() { };
    static const CLID& classID();
    
    /// Create object
    virtual StatusCode createObj(IOpaqueAddress* pAddress, DataObject*& refpObject);
    
private:
};
#endif // CNV_McEventCnv_H
