// File and Version Information:
// $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/Attic/FilterCnv.cxx,v 1.1.4.1 2008/06/26 19:21:00 heather Exp $
//
// Description:
// Concrete converter for the McEvent header on the TDS /Event/MC

#define CNV_FILTERCNV_CPP 

#include "GaudiKernel/CnvFactory.h"

#include "FilterCnv.h"

#include "GaudiKernel/IDataProviderSvc.h"
#include "GaudiKernel/ObjectVector.h"

// RCS Id for identification of object version
static const char* rcsid = "$Id: FilterCnv.cxx,v 1.1.4.1 2008/06/26 19:21:00 heather Exp $";

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


