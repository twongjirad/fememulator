#ifndef __FEMBEAMTRIGGERALGO__
#define  __FEMBEAMTRIGGERALGO__

#include <vector>
#include "FEMBeamTriggerTypes.h"

namespace fememu {

  class FEMBeamTriggerAlgo {
  public:
    /// Default ctor
    FEMBeamTriggerAlgo();
    /// Config ctor
    FEMBeamTriggerAlgo(const FEMBeamTriggerConfig&);
    /// Default dtor
    ~FEMBeamTriggerAlgo(){}

    /// Executor function
    const FEMBeamTriggerOutput Emulate( const WaveformArray_t& );

    /// FEM configuration for generating FEM Beam trigger
    FEMBeamTriggerConfig _cfg;

    /// Summed (over channels) multiplicity vector getter
    const Waveform_t& Multiplicity() const;

    /// Summed (over channels) phmax vector getter
    const Waveform_t& PHMAX() const;

    /// Channel-wise disc 0 phase-diff vector getter
    const Waveform_t& PhaseDiffDisc0(const size_t) const;

    /// Channel-wise disc 3 phase-diff vector getter
    const Waveform_t& PhaseDiffDisc3(const size_t) const;

    /// Channel-wise multiplicity vector getter
    const Waveform_t& ChannelHitVector(const size_t) const;

    /// Channel-wise phmax vector getter
    const Waveform_t& ChannelPHMAXVector(const size_t) const;

  private:
    /// Computation variable: channel-wise phmax vector
    WaveformArray_t _chdiff;
    /// Computation variable: channel-wise multiplicity vector
    WaveformArray_t _chhit;
    /// Computation variable: disc. 0 diff vector
    WaveformArray_t _diff0_array;
    /// Computation variable: disc. 3 diff vector
    WaveformArray_t _diff3_array;
    /// Computation variable: phmax sum vector over channels
    Waveform_t _chdiff_sum;
    /// Computation variable: multiplicity sum vector over channels
    Waveform_t _chhit_sum;

  protected:
    inline bool debug   () const { return _cfg.fVerbosity <= kDEBUG;   }
    inline bool info    () const { return _cfg.fVerbosity <= kINFO;    }
    inline bool normal  () const { return _cfg.fVerbosity <= kNORMAL;  }
    inline bool warning () const { return _cfg.fVerbosity <= kWARNING; }
    inline bool error   () const { return _cfg.fVerbosity <= kERROR;   }
  };

}

#endif
