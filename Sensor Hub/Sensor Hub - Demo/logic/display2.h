// *************************************************************************************************
//
//  Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
//   
//   
//    Redistribution and use in source and binary forms, with or without 
//    modification, are permitted provided that the following conditions 
//    are met:
//  
//      Redistributions of source code must retain the above copyright 
//      notice, this list of conditions and the following disclaimer.
//   
//      Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the 
//      documentation and/or other materials provided with the   
//      distribution.
//   
//      Neither the name of Texas Instruments Incorporated nor the names of
//      its contributors may be used to endorse or promote products derived
//      from this software without specific prior written permission.
//  
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *************************************************************************************************
// Additional display functions.
// *************************************************************************************************

#ifndef DISPLAY2_H_
#define DISPLAY2_H_


// *************************************************************************************************
// Include section


// *************************************************************************************************
// Prototypes section



// *************************************************************************************************
// Defines section
#define DISPLAY_NO      (0u)
#define DISPLAY_YES     (1u)


// *************************************************************************************************
// Global Variable section

// *************************************************************************************************
// Extern section
extern void display_charSegments(u8 segment, u8 charSegments, u8 mode);

extern void display_OFF_ON(u8 segments, u32 value, u8 digits, u8 blanks);
extern void display_CONT_ONCE(u8 segments, u32 value, u8 digits, u8 blanks);
extern void display_NO_YES(u8 segments, u32 value, u8 digits, u8 blanks);
extern void display_NO_YES_AUTO_MAN(u8 segments, u32 value, u8 digits, u8 blanks);
extern void display_SW_Version(u8 segments, u32 value, u8 digits, u8 blanks);


#endif
