// IEE routines (Need to be worked on)

#if HANDLE_IEEE
#define _EXC_MASK    \
    _EM_UNDERFLOW  + \
    _EM_OVERFLOW   + \
    _EM_ZERODIVIDE + \
    _EM_INEXACT
// #include "fpieee.h"
#include <excpt.h>
#include <float.h>
#endif

#if HANDLE_IEEE
#define _EXC_MASK    \
    _EM_UNDERFLOW  + \
    _EM_OVERFLOW   + \
    _EM_ZERODIVIDE + \
    _EM_INEXACT
typedef enum {
    _FpFormatFp32,
    _FpFormatFp64,
    _FpFormatFp80,
    _FpFormatFp128,
    _FpFormatI16,
    _FpFormatI32,
    _FpFormatI64,
    _FpFormatU16,
    _FpFormatU32,
    _FpFormatU64,
    _FpFormatBcd80,
    _FpFormatCompare,
    _FpFormatString
} _FPIEEE_FORMAT;
//#include "fpieee.h"
#include <excpt.h>
#include <float.h>
#endif

#if HANDLE_IEEE
int fpieee_handler( _FPIEEE_RECORD *pieee );
#endif

#if HANDLE_IEEE
int fpieee_handler( _FPIEEE_RECORD *pieee )
{
  // user-defined ieee trap handler routine: there is one handler for
  // all IEEE exceptions
    
  // Assume the user wants all invalid operations to return 0.
    
    if((pieee->Cause.InvalidOperation) && 
      (pieee->Result.Format == _FpFormatFp32)) {
	pieee->Result.Value.Fp32Value = 0.0F;
	
        return EXCEPTION_CONTINUE_EXECUTION;
    } else {
	return EXCEPTION_EXECUTE_HANDLER;
    }
}
#endif

