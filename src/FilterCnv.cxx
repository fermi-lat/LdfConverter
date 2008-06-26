// File and Version Information:
// $Header: /usr/local/CVS/SLAC/LdfConverter/src/Attic/FilterCnv.cxx,v 1.1.2.1 2007/11/14 13:05:06 heather Exp $
//
// Description:
// Concrete converter for the McEvent header on the TDS /Event/MC

#define CNV_FILTERCNV_CPP 

#include "GaudiKernel/CnvFactory.h"

#include "FilterCnv.h"

#include "GaudiKernel/IDataProviderSvc.h"
#include "GaudiKernel/ObjectVector.h"

// RCS Id for identification of object version
static const char* rcsid = "$Id: FilterCnv.cxx,v 1.1.2.1 2007/11/14 13:05:06 heather Exp $";

// Instantiation of a static factory class used by clients to create
// instances of this service
static CnvFactory<FilterCnv> s_factory;
const ICnvFactory& FilterCnvFactory = s_factory;


FilterCnv::FilterCnv(ISvcLocator* svc)
: LdfBaseCnv(classID(), svc)
{
  declareObject("/Event/Filter", objType(), "PASS");
}


StatusCode FilterCnv::createObj(IOpaqueAddress* pAddress, DataObject*& refpObject)
{
    // Purpose and Method:  Converter just creates an empty instance of MCEvent
    //   for the TDS.  The data members will be initialized by other components.

    refpObject = new DataObject();
    StatusCode sc=StatusCode::SUCCESS;
    return sc;
}


const CLID& FilterCnv::classID(){ return CLID_DataObject;}


