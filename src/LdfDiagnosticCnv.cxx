// File and Version Information:
//      $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfDiagnosticCnv.cxx,v 1.1.1.1 2004/05/13 22:02:48 heather Exp $
//
// Description:
//      LdfDiagnosticCnv is the concrete converter for the event header on the TDS /Event
//
// Author(s):

#define LdfDiagnosticCnv_CXX 

#include "GaudiKernel/RegistryEntry.h"
#include "LdfDiagnosticCnv.h"
#include "GaudiKernel/MsgStream.h"

#include "ldfReader/data/LatData.h"

#include "LdfEvent/DiagnosticData.h"

// Instantiation of a static factory class used by clients to create
// instances of this service
static CnvFactory<LdfDiagnosticCnv> s_factory;
const ICnvFactory& LdfDiagnosticCnvFactory = s_factory;

LdfDiagnosticCnv::LdfDiagnosticCnv(ISvcLocator* svc)
: LdfBaseCnv(classID(), svc)
{
    // Here we associate this converter with the /Event path on the TDS.
    declareObject("/Event/Diagnostic", objType(), "PASS");
}


StatusCode LdfDiagnosticCnv::createObj(IOpaqueAddress* , 
                                    DataObject*& refpObject) {
    // Purpose and Method:  This converter will store EBF diagnostic data on the TDS
    LdfEvent::DiagnosticData *diag = new LdfEvent::DiagnosticData();
    refpObject = diag;
    
    // Retrieve the LAT data for this event and print out its contents
    ldfReader::LatData* myLatData = ldfReader::LatData::instance();
    const ldfReader::DiagnosticData *diagnostic = myLatData->diagnostic();
    unsigned int numCal = diagnostic->getNumCalDiagnostic();
    unsigned int ind;
    for (ind = 0; ind < numCal; ind++) {
        ldfReader::CalDiagnosticData ldfCalDiag = diagnostic->getCalDiagnosticByIndex(ind);
        //LdfEvent::CalDiagnosticData cal(diagnostic->getCalDiagnosticByIndex(ind).dataWord());
        LdfEvent::CalDiagnosticData cal(ldfCalDiag.dataWord(), ldfCalDiag.tower(), ldfCalDiag.layer());
        diag->addCalDiagnostic(cal);
    }
    unsigned int numTkr = diagnostic->getNumTkrDiagnostic();
    for (ind = 0; ind < numTkr; ind++) {
        ldfReader::TkrDiagnosticData ldfTkrDiag = diagnostic->getTkrDiagnosticByIndex(ind);
        LdfEvent::TkrDiagnosticData tkr(ldfTkrDiag.dataWord(), ldfTkrDiag.tower(), ldfTkrDiag.gtcc());
        diag->addTkrDiagnostic(tkr);
    }
    return StatusCode::SUCCESS;
}

StatusCode LdfDiagnosticCnv::updateObj(int* , LdfEvent::DiagnosticData* ) {
    // Purpose and Method:  This method does nothing other than announce it has
    //   been called.

    MsgStream log(msgSvc(), "LdfDiagnosticCnv");
    log << MSG::DEBUG << "LdfDiagnosticCnv::updateObj" << endreq;
    return StatusCode::SUCCESS;
}

