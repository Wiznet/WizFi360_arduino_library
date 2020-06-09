/*--------------------------------------------------------------------
This file is part of the Arduino WizFi360 library.

The Arduino WizFi360 library is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

The Arduino WizFi360 library is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The Arduino WizFi360 library.  If not, see
<http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

// Change _WIZFILOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _WIZFILOGLEVEL_
#define _WIZFILOGLEVEL_ 3
#endif


#define LOGERROR(x)    if(_WIZFILOGLEVEL_>0) { Serial.print("[WizFi360] "); Serial.println(x); }
#define LOGERROR1(x,y) if(_WIZFILOGLEVEL_>2) { Serial.print("[WizFi360] "); Serial.print(x); Serial.print(" "); Serial.println(y); }
#define LOGWARN(x)     if(_WIZFILOGLEVEL_>1) { Serial.print("[WizFi360] "); Serial.println(x); }
#define LOGWARN1(x,y)  if(_WIZFILOGLEVEL_>2) { Serial.print("[WizFi360] "); Serial.print(x); Serial.print(" "); Serial.println(y); }
#define LOGINFO(x)     if(_WIZFILOGLEVEL_>2) { Serial.print("[WizFi360] "); Serial.println(x); }
#define LOGINFO1(x,y)  if(_WIZFILOGLEVEL_>2) { Serial.print("[WizFi360] "); Serial.print(x); Serial.print(" "); Serial.println(y); }

#define LOGDEBUG(x)      if(_WIZFILOGLEVEL_>3) { Serial.println(x); }
#define LOGDEBUG0(x)     if(_WIZFILOGLEVEL_>3) { Serial.print(x); }
#define LOGDEBUG1(x,y)   if(_WIZFILOGLEVEL_>3) { Serial.print(x); Serial.print(" "); Serial.println(y); }
#define LOGDEBUG2(x,y,z) if(_WIZFILOGLEVEL_>3) { Serial.print(x); Serial.print(" "); Serial.print(y); Serial.print(" "); Serial.println(z); }


#endif
