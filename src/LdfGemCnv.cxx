// File and Version Information:
//      $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfGemCnv.cxx,v 1.1.1.1 2004/05/13 22:02:49 heather Exp $
//
// Description:
//      LdfGemCnv is the concrete converter for the event header on the TDS /Event
//
// Author(s):

#define LdfGemCnv_CXX 

#include "GaudiKernel/RegistryEntry.h"
#include "LdfGemCnv.h"
#include "GaudiKernel/MsgStream.h"

#include "ldfReader/data/LatData.h"
#include "LdfEvent/Gem.h"

// Instantiation of a static factory class used by clients to create
// instances of this service
static CnvFactory<LdfGemCnv> s_factory;
const ICnvFactory& LdfGemCnvFactory = s_factory;

LdfGemCnv::LdfGemCnv(ISvcLocator* svc)
: LdfBaseCnv(classID(), svc)
{
    // Here we associate this converter with the /Event/Gem path on the TDS.
    declareObject("/Event/Gem", objType(), "PASS");
}


StatusCode LdfGemCnv::createObj(IOpaqueAddress* , 
                               DataObject*& refpObject) {
    // Purpose and Method:  This converter will store Ebf time on the TDS.
    LdfEvent::LdfGem *gem = new LdfEvent::Gem();
    refpObject = gem;
    // Retrieve the LAT data for this event 
    ldfReader::GemData ldfGem = ldfReader::LatData::instance()->getGem();
    ldfReader::GemDataTileList ldfTileList = ldfGem.tileList();
    LdfEvent::GemDataTileList tdsTileList(ldfTileList.XZM(), ldfTileList.XZP(),
            ldfTileList.YZM(), ldfTileList.YZP(), ldfTileList.XY(), 
            ldfTileList.RBN(), ldfTileList.NA());
    gem->initTrigger(ldfGem.tkrVector(), ldfGem.roiVector(), ldfGem.calLEvector(),
        ldfGem.calHEvector(), ldfGem.cnoVector(), ldfGem.conditionSummary(), tdsTileList);
    LdfEvent::GemDataOnePpsTime ppsTime(ldfGem.onePpsTime().timebase(),
        ldfGem.onePpsTime().seconds());
    gem->initSummary(ldfGem.liveTime(), ldfGem.prescaled(), ldfGem.discarded(),
        ldfGem.sent(), ldfGem.triggerTime(), ppsTime, ldfGem.deltaEventTime());
    return StatusCode::SUCCESS;
}

StatusCode LdfGemCnv::updateObj(int* , LdfEvent::LdfGem*) {
    // Purpose and Method:  This method does nothing other than announce it has
    //   been called.

    MsgStream log(msgSvc(), "LdfGemCnv");
    log << MSG::DEBUG << "LdfGemCnv::updateObj" << endreq;
    return StatusCode::SUCCESS;
}

