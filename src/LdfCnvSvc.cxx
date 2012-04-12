// File and Version Information:
//      $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/LdfCnvSvc.cxx,v 1.2.734.1 2012/01/30 18:50:41 heather Exp $
//
// Description:
//      LdfCnvSvc is the GLAST converter service.
//
// Author(s):

#define LdfCnvSvc_CXX

#include "GaudiUtils/IIODataManager.h"
#include "GaudiKernel/IDataManagerSvc.h"
#include "GaudiKernel/IPersistencySvc.h"
#include "GaudiKernel/GenericAddress.h"
#include "GaudiKernel/IDetDataSvc.h"
#include "GaudiKernel/IDataProviderSvc.h"
#include "GaudiKernel/MsgStream.h"
#include "GaudiKernel/SvcFactory.h"
#include "GaudiKernel/SmartDataPtr.h"
#include "GaudiKernel/strcasecmp.h"
#include "GaudiKernel/DataObject.h"
#include "GaudiKernel/IRegistry.h"
#include "GaudiKernel/MsgStream.h"
#include "GaudiKernel/IAddressCreator.h"
#include "GaudiKernel/ConversionSvc.h"

#include "Event/Digi/AcdDigi.h"
#include "Event/Digi/CalDigi.h"
#include "Event/Digi/TkrDigi.h"
#include "Event/TopLevel/DigiEvent.h"
#include "Event/TopLevel/MCEvent.h"

#include "LdfEvent/DiagnosticData.h"
#include "LdfEvent/ErrorData.h"
#include "LdfEvent/EventSummaryData.h"
#include "LdfEvent/Gem.h"
#include "LdfEvent/LdfTime.h"
#include "LdfEvent/LsfCcsds.h"
#include "LdfEvent/LsfMetaEvent.h"
#include "EbfWriter/Ebf.h"
#include "FilterCnv.h"


#include <iostream>

#include "TInterpreter.h"

//#include "GaudiKernel/SmartIF.h"
//#include "GaudiKernel/CnvFactory.h"
//#include "GaudiKernel/ICnvManager.h"
//#include "GaudiKernel/ISvcLocator.h"
//#include "GaudiKernel/IDataProviderSvc.h"
//#include "GaudiKernel/RegistryEntry.h"

//#include "LdfBaseCnv.h"
//#include "LdfCnvSvc.h"
#include "ILdfCnvSvc.h"

template <class TYPE> class SvcFactory;

class LdfCnvSvc  : public ConversionSvc, virtual public ILdfCnvSvc
{

  friend class SvcFactory<LdfCnvSvc>;

  typedef std::map<std::string, Leaf*> LeafMap;
  LeafMap m_leaves;

public:

/*

class Leaf : public std::vector<Leaf*>    {
  public:
    long userParameter;
    std::string path;
    std::string bank;
    CLID        clid;
    Leaf(const std::string& p, const CLID& c, const std::string& b, long u)
      : userParameter(u), path(p), bank(b), clid(c) {}
    Leaf(const Leaf& copy) 
      : std::vector<Leaf*>(copy),userParameter(copy.userParameter), 
        path(copy.path), bank(copy.bank), 
        clid(copy.clid) {}
    Leaf& operator=(const Leaf& copy)   {
      path = copy.path;
      bank = copy.bank;
      clid = copy.clid;
      userParameter = copy.userParameter;
      return *this;
    }
    bool operator==(const Leaf& copy) const  {
      return  path          == copy.path && 
              bank          == copy.bank && 
              clid          == copy.clid && 
              userParameter == copy.userParameter;
    }
  };

  typedef std::map<std::string, Leaf*> LeafMap;
  LeafMap m_leaves;
*/

  virtual StatusCode initialize();

  virtual StatusCode finalize();

  //virtual void loadConverter(DataObject*);

  virtual StatusCode updateServiceState(IOpaqueAddress* pAddress);

  virtual StatusCode declareObject(const ILdfCnvSvc::Leaf& leaf);

  /// Override inherited queryInterface due to enhanced interface
  virtual StatusCode queryInterface(const InterfaceID& riid, void** ppvInterface);

    /// Concrete class type
   virtual const CLID& objType() const { return DataObject::classID(); };


   /** Object creation callback
      *  @@param[in]   pAddr     Reference to opaque object address
      *  @@param[out]  refpObj   Reference to store pointer to created object
      *
      *  @@return Status code indicating success or failure
      */
  //virtual StatusCode createObj(IOpaqueAddress* pAddr, DataObject*& refpObj);


  /** IAddressCreator implementation: Address creation.
    Create an address using the link infotmation together with
    the triple (database name/container name/object name).

    @@param refLink        Reference to abstract link information
    @@param dbName         Database name
    @@param containerName  Object container name
    @@param refpAddress    Opaque address information to retrieve object
    @@return               StatusCode indicating SUCCESS or failure
  */
  virtual StatusCode createAddress( long  svc_type,
                                    const CLID& clid,
                                    const std::string* par, 
                                    const unsigned long* ip,
                                    IOpaqueAddress*& refpAddress);

 // virtual StatusCode createAddress( unsigned char svc_type,
 //                                   const CLID& clid,
 //                                   const std::string* par, 
 //                                   const unsigned long* ip,
 //                                   IOpaqueAddress*& refpAddress);

    /// Retrieve converter from list
// virtual IConverter* converter(const CLID& clid);

protected:

  LdfCnvSvc(const std::string& name, ISvcLocator* svc);

  virtual ~LdfCnvSvc() { };

  /// Reference to data manager interface
 IDataManagerSvc*       m_dataMgr;
  /// Reference to file manager service
 // Gaudi::IIODataManager* m_ioMgr;


private:
    //typedef std::map<std::string, IGlastCnv*>                PathToCnvMap;
    //typedef std::map<std::string, std::vector<std::string> > SubPathMap;

    //PathToCnvMap m_pathToCnvMap;
    //SubPathMap   m_subPathMap;
    IAddressCreator *m_addressCreator;
};



static const InterfaceID IID_ILdfBaseCnv("ILdfBaseCnv", 1 , 0); 

// RCS Id for identification of object version
static const char* rcsid = "$Id: LdfCnvSvc.cxx,v 1.2.734.1 2012/01/30 18:50:41 heather Exp $";
//template <class TYPE> class SvcFactory; HMK Not sure we need this now 2010

DECLARE_SERVICE_FACTORY( LdfCnvSvc );

// Instantiation of a static factory class used by clients to create
// instances of this service
//static const SvcFactory<LdfCnvSvc> s_LdfCnvSvcFactory;
//const ISvcFactory& LdfCnvSvcFactory = s_LdfCnvSvcFactory;

LdfCnvSvc::LdfCnvSvc(const std::string& name, ISvcLocator* svc)
: ConversionSvc(name, svc, TEST_StorageType), m_dataMgr(0)
{
}

StatusCode LdfCnvSvc::initialize()     {
    // Purpose and Method:  Setup GLAST's Event Converter Service.
    //   Associate LdfCnvSvc with the EventDataSvc
    //   Associate the list of known converters with this LdfCnvSvc.
    MsgStream log(msgSvc(), name());

    StatusCode status = ConversionSvc::initialize();
    if (!status.isSuccess() ) return status;

 //IPersistencySvc *pSvc = 0;
 // status = service("EventPersistencySvc",pSvc,true);
 // if ( !status.isSuccess() )  {
 //   log << MSG::ERROR << "Unable to localize EventPersistencySvc." << endmsg;
 //   return status;
 // }

  //status = pSvc->addCnvService( this );
  //if ( !status.isSuccess() )  {
  //  log << MSG::ERROR << "Unable to add conversion service" << endmsg;
  //  return status;
 // }

 // m_addressCreator = 0;
 // //pSvc->addrCreator();
 //  status = service("EventPersistencySvc",m_addressCreator);
 // if ( !status.isSuccess() )  {
 //   log << MSG::ERROR << "Unable to localize IAddressCreator." << endmsg;
 //   return status;
 // }

  status = service ( "EventDataSvc" , m_dataMgr , true ) ;

 if ( !status.isSuccess() )  {
    log << MSG::ERROR << "Unable to retrieve EventDataSvc " << endmsg;
    return status;
  }

 //status = m_dataMgr->setDataLoader(this);
// log << MSG::DEBUG << "Called dataloader" <<endmsg;
// if (!status.isSuccess()) log << "setting dataloader failed " << endmsg;

    //if ( status.isSuccess() )   {
        //        ISvcLocator* svclocator = serviceLocator();  [unused for now]
      //  IDataProviderSvc *pIDP = 0;
        // Set event data service
      //  status = service("EventDataSvc", pIDP, true);
      //  if ( status.isSuccess() )   {
      //      status = setDataProvider ( pIDP );
      //  }
      //  else    {
      //      return status;
     //   }


    //StatusCode istatus =  addConverter(CLID_DigiEvent);
    //istatus =  addConverter(CLID_AcdDigi);
        
        // Add known converters to the service: 
        //ICnvManager::CnvIterator i, stop;
        //for ( i = cnvManager()->cnvBegin(), stop = cnvManager()->cnvEnd(); i != stop; i++ )   {
        //    if ( repSvcType() == (*i)->repSvcType() )   {
        //        StatusCode iret = addConverter( (*i)->objType() );        
        ///        if ( !iret.isSuccess() )   {
        //            status = iret;
        //        }
        //    }
       // }
        
        // Now we have to configure the map of leaves
        // Which should contain the association of converters with 
        // paths on the TDS
       // for (LeafMap::iterator k = m_leaves.begin(); k != m_leaves.end(); k++ )   {
       //     std::string path = (*k).first;
       //     for (LeafMap::iterator j = m_leaves.begin(); j != m_leaves.end(); j++ )   {
        //        std::string pp = (*j).first.substr(0, (*j).first.rfind("/"));
        //        if ( path == pp && path != (*j).first )   {
        //            (*k).second->push_back((*j).second);
        //        }
        //    }
       // }
        
   // }
    
    return status;
}

StatusCode LdfCnvSvc::finalize()     {
    if (m_dataMgr) m_dataMgr->release();
    m_dataMgr = 0;
    StatusCode status = ConversionSvc::finalize();
  //  for (LeafMap::iterator k = m_leaves.begin(); k != m_leaves.end(); k++ )   {
  //      delete (*k).second;
  //  }
  //  m_leaves.erase(m_leaves.begin(), m_leaves.end());
    return status;
}

StatusCode LdfCnvSvc::declareObject(const ILdfCnvSvc::Leaf& leaf)   {
    // Purpose and Method:  Callback from each of the individual converters that allows
    //  association of TDS path and converter.
    Leaf* ll = new Leaf(leaf);
    std::pair<LeafMap::iterator, bool> p = m_leaves.insert(LeafMap::value_type( leaf.path, ll) );
    if( p.second )    {
        return StatusCode::SUCCESS;
    }
    delete ll;
    return StatusCode::FAILURE;
}

/*void LdfCnvSvc::loadConverter(DataObject* pObject) {
    if (pObject) {
        MsgStream log(msgSvc(), name());
        std::string cname = System::typeinfoName(typeid(*pObject));
        log << MSG::DEBUG << "Trying to 'Autoload' dictionary for class " << 
               cname << endmsg;
        gInterpreter->EnableAutoLoading();
        gInterpreter->AutoLoad(cname.c_str());
    }
}
*/
/// Update state of the service
StatusCode LdfCnvSvc::updateServiceState(IOpaqueAddress* pAddress)    {

    // not sure about the use of recid or bank...

    MsgStream log(msgSvc(), name());
    static bool firstTime=true;
    StatusCode status = INVALID_ADDRESS;
    IRegistry* ent = pAddress->registry();
    if ( 0 != ent )   {
        //SmartIF<IDataManagerSvc> iaddrReg(IID_IDataManagerSvc, dataProvider());
        //       if ( 0 != iaddrReg )   {
        status = StatusCode::SUCCESS;
        std::string path = ent->identifier();

        log << MSG::DEBUG << "Called with path: " << path  
            << " and CLID " << endreq;

   if (firstTime) {
    status = addConverter(CLID_DigiEvent);
    if (status.isSuccess())
       log << MSG::INFO << "added DigiEvent Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add DigiEvent Cnv" << endreq;

    status = addConverter(CLID_AcdDigi);
    if (status.isSuccess())
       log << MSG::INFO << "added AcdDigi Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add AcdDigi Cnv" << endreq;

    status = addConverter(CLID_CalDigi);
    if (status.isSuccess())
       log << MSG::INFO << "added CalDigi Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add CalDigi Cnv" << endreq;

    status = addConverter(CLID_TkrDigi);
    if (status.isSuccess())
       log << MSG::INFO << "added TkrDigi Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add TkrDigi Cnv" << endreq;

    status = addConverter(CLID_McEvent);
    if (status.isSuccess())
       log << MSG::INFO << "added McEvent Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add McEvent Cnv" << endreq;

    status = addConverter(CLID_MetaEvent);
    if (status.isSuccess())
       log << MSG::INFO << "added MetaEvent Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add MetaEvent Cnv" << endreq;

    status = addConverter(CLID_LdfEventSummaryData);
    if (status.isSuccess())
       log << MSG::INFO << "added EventSummary Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add EventSummary Cnv" << endreq;

    status = addConverter(CLID_LdfDiagnosticData);
    if (status.isSuccess())
       log << MSG::INFO << "added Diagnostic Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add Diagnostic Cnv" << endreq;

    status = addConverter(CLID_LdfErrorData);
    if (status.isSuccess())
       log << MSG::INFO << "added LdfError Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add LdfError Cnv" << endreq;

    status = addConverter(CLID_LdfGem);
    if (status.isSuccess())
       log << MSG::INFO << "added GEM Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add GEM Cnv" << endreq;

    status = addConverter(CLID_LdfTime);
    if (status.isSuccess())
       log << MSG::INFO << "added LdfTimeCnv" << endreq;
    else
       log << MSG::INFO << "Failed to add LdfTime Cnv" << endreq;

    status = addConverter(CLID_LsfCcsds);
    if (status.isSuccess())
       log << MSG::INFO << "added CCSDS Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add CCSDS Cnv" << endreq;

    status = addConverter(CLID_Filter);
    if (status.isSuccess())
       log << MSG::INFO << "added Filter Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add Filter Cnv" << endreq;

    // NEed to add Filtercnv
    status = addConverter(CLID_Ebf);
    if (status.isSuccess())
       log << MSG::INFO << "added Ebf Filter Cnv" << endreq;
    else
       log << MSG::INFO << "Failed to add Ebf Filter Cnv" << endreq;
   
        // Now we have to configure the map of leaves
        // Which should contain the association of converters with 
        // paths on the TDS
        for (LeafMap::iterator k = m_leaves.begin(); k != m_leaves.end(); k++ )   {
            std::string path = (*k).first;
            for (LeafMap::iterator j = m_leaves.begin(); j != m_leaves.end(); j++ )   {
               std::string pp = (*j).first.substr(0, (*j).first.rfind("/"));
               if ( path == pp && path != (*j).first )   {
                   (*k).second->push_back((*j).second);
               }
            }
        }
    firstTime=false;
   }

 //       if (path == "/Event") return StatusCode::SUCCESS;


        LeafMap::iterator itm = m_leaves.find(path);
          //  int size = m_leaves.size();   [unused for now]
            if ( itm != m_leaves.end() )    {
                ILdfCnvSvc::Leaf* leaf = (*itm).second;
                if ( 0 != leaf )    {
                    //ipar[0] = leaf->userParameter;
                    for ( Leaf::iterator il = leaf->begin(); il != leaf->end(); il++ )   {
                        IOpaqueAddress* newAddr = 0;
                        unsigned long ipars[2] = {0, 0}; 
                        const std::string spars[2] = {"", ""}; 
                        StatusCode ir =
                            addressCreator()->createAddress(TEST_StorageType, 
                            (*il)->clid, 
                            spars, 
                            ipars,
                            newAddr);
                        if ( ir.isSuccess() )   {
                            ir = m_dataMgr->registerAddress((*il)->path, newAddr);
                            if ( !ir.isSuccess() )    {
                                newAddr->release();
                                status = ir;
                            } // end if
                        } // end if
                    } // end for
                } // end if
            } // end if


    }
    return status;
}

StatusCode LdfCnvSvc::queryInterface(const InterfaceID& riid, void** ppvInterface)  {
    if ( IID_ILdfBaseCnv == riid )  {
        *ppvInterface = (ILdfCnvSvc*)this;
    }
    else  {
        // Interface is not directly availible: try out a base class
        return ConversionSvc::queryInterface(riid, ppvInterface);
   }
 //   addRef();
    return StatusCode::SUCCESS;
}

StatusCode LdfCnvSvc::createAddress(long svc_type,
                                      const CLID& clid,
                                      const std::string* , 
                                      const unsigned long* ,
                                      IOpaqueAddress*& refpAddress) 
{
    MsgStream log( msgSvc(), name() );
    
    //if (svc_type != repSvcType() ) {
    //    log << MSG::ERROR << "bad storage type" << svc_type << endreq;
    //    return StatusCode::FAILURE;
   // }
/*
        Address* pAdd = new Address(svc_type, clid, par[0]);
        if ( pAdd )
        {
            refpAddress = pAdd;
            return StatusCode::SUCCESS;
        }
        // Call to GenericAddress routine
        pAdd->release();
        */
  log << MSG::DEBUG << "Checking types " << endreq;
  log << MSG::DEBUG << "svc_type: " << svc_type << " repSvcType: "
      << repSvcType() << endreq;
  log << MSG::DEBUG << "CLID: " << clid << endreq;

  if (svc_type == repSvcType() ) {
  refpAddress = new GenericAddress(TEST_StorageType,clid);
    return StatusCode::SUCCESS;
  }

    log << MSG::ERROR << "Unable to createAddress" << endmsg;
    return StatusCode::FAILURE;

}

/*
StatusCode LdfCnvSvc::activateConverter( const CLID& clid) 
{

    MsgStream log( msgSvc(), name() );

    IOpaqueAddress* newAddr = 0;
    unsigned long ipars[2] = {0, 0};
    const std::string spars[2] = {"", ""};
    istatus = addressCreator()->createAddress(TEST_StorageType, 
            clid,
            spars, 
            ipars,
            newAddr);
     if ( istatus.isSuccess() )   {
         log << MSG::DEBUG << "create address succeeded " << endreq;
         istatus = m_dataMgr->registerAddress(path, newAddr);
         if ( !istatus.isSuccess() )    {
             log << MSG::DEBUG << "Failed to register " <<  path << endreq;
             newAddr->release();
             return istatus;
         } else 
             log << MSG::DEBUG << "registered " << path << endreq;
      else {
          log << MSG::DEBUG << "failed to create addres" << endreq;
          return istatus;
           }
       }
 }  
*/
