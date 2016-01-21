/**
 * \file Result.h
 *
 * \ingroup Base
 * 
 * \brief Class def header for a class Result
 *
 * @author kazuhiro
 */

/** \addtogroup Base

    @{*/
#ifndef __TRIGGER_RESULT_H__
#define __TRIGGER_RESULT_H__

#include <iostream>

namespace trigger {
  /**
     \class Result
     User defined class Result ... these comments are used to generate
     doxygen documentation!
  */
  class Result{
    
  public:
    
    /// Default constructor
    Result()
      : pass         (  0 )
      , pass_algo    (  0 )
      , pass_prescale(  0 )
      , amplitude    (  0 )
      , multiplicity (  0 )
      , time         ( -1 )
    {}
    
    /// Default destructor
    ~Result(){}

    bool  pass;         ///< Do we keep this event (this is the AND of pass_algo, pass_prescale below)
    bool  pass_algo;    ///< Did the event pass the algorithm applied
    bool  pass_prescale;///< Did it pass a pre-scale (if one is applied) (if no-prescale applied, this is always true)
    short amplitude;    ///< PHMAX sum
    short multiplicity; ///< Multiplicity sum
    int   time;         ///< Trigger decision times (-1 means not fired)
    
  };
}
  
#endif
/** @} */ // end of doxygen group 
