#ifndef __FEMEMULATOR_LARLITE_INTERFACE_H
#define __FEMEMULATOR_LARLITE_INTERFACE_H
#include <vector>
#include "FEMBeamTriggerAlgo.h"
#include "DataFormat/opdetwaveform.h"
#include "DataFormat/fifo.h"
namespace fememu {

  /// LArLite interface class for fememu::FEMBeamTriggerAlgo class
  class LLInterface : public fememu::FEMBeamTriggerAlgo {
  public:
    /// Default ctor
    LLInterface() : fememu::FEMBeamTriggerAlgo() {}
    /// Config ctor
    LLInterface(const FEMBeamTriggerConfig& cfg) : fememu::FEMBeamTriggerAlgo(cfg) {}
    /// Default dtor
    ~LLInterface(){}

    /// Add an interface type that accepts larlite::event_opdetwaveform
    FEMBeamTriggerOutput Emulate( const ::larlite::event_opdetwaveform& );

    /// Add an interface type that accepts larlite::event_opdetwaveform
    FEMBeamTriggerOutput Emulate( const ::larlite::event_fifo& );

  };
}

#endif
