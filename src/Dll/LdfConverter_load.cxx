/** 
* @file LdfConverter_load.cpp
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/LdfConverter/src/Dll/LdfConverter_load.cxx,v 1.5 2004/08/02 21:06:22 heather Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_FACTORY_ENTRIES(LdfConverter) {
  DECLARE_SERVICE(LdfCnvSvc);
  DECLARE_SERVICE( LdfEventSelector );
  DECLARE_CONVERTER(LdfEventSummaryCnv);
  DECLARE_CONVERTER(LdfEventCnv);
  DECLARE_CONVERTER(LdfDigiCnv);
  DECLARE_CONVERTER(LdfTkrDigiCnv);
  DECLARE_CONVERTER(LdfCalDigiCnv);
  DECLARE_CONVERTER(LdfAcdDigiCnv);
  DECLARE_CONVERTER(LdfDiagnosticCnv);
  DECLARE_CONVERTER(LdfTimeCnv);
  DECLARE_CONVERTER(LdfGemCnv);
  DECLARE_CONVERTER( McEventCnv );

}
  
