// This program configures the General Programmable Interface (GPIF) for FX2.     
// Please do not modify sections of text which are marked as "DO NOT EDIT ...". 
//                                                                                
// DO NOT EDIT ...                  
// GPIF Initialization              
// Interface Timing      Sync         
// Internal Ready Init   IntRdy=1     
// CTL Out Tristate-able Binary       
// SingleWrite WF Select     1     
// SingleRead WF Select      0     
// FifoWrite WF Select       3     
// FifoRead WF Select        2     
// Data Bus Idle Drive   Tristate     
// END DO NOT EDIT                  
                                    
// DO NOT EDIT ...       
// GPIF Wave Names       
// Wave 0   = Single R     
// Wave 1   = Single W     
// Wave 2   = FIFO Rea     
// Wave 3   = FIFO Wri     
                         
// GPIF Ctrl Outputs   Level   
// CTL 0    = cmdwen   CMOS        
// CTL 1    = evtren   CMOS        
// CTL 2    = rspren   CMOS        
// CTL 3    = r_wn     CMOS        
// CTL 4    = olpwrn   CMOS        
// CTL 5    = Ctl-NoOp CMOS        
                               
// GPIF Rdy Inputs         
// RDY0     = RSP_RDYN       
// RDY1     = EVT_RDYN       
// RDY2     = RDY2           
// RDY3     = RDY3           
// RDY4     = RDY4           
// RDY5     = TCXpire        
// FIFOFlag = FIFOFlag       
// IntReady = IntReady       
// END DO NOT EDIT         
// DO NOT EDIT ...                                                                         
//                                                                                         
// GPIF Waveform 0: Single R                                                                
//                                                                                         
// Interval     0         1         2         3         4         5         6     Idle (7) 
//          _________ _________ _________ _________ _________ _________ _________ _________
//                                                                                         
// AddrMode Same Val  Same Val  Same Val  Same Val  Same Val  Same Val  Same Val           
// DataMode NO Data   Activate  Activate  Activate  Activate  Activate  Activate           
// NextData SameData  SameData  SameData  SameData  SameData  SameData  SameData           
// Int Trig No Int    No Int    No Int    No Int    No Int    No Int    No Int             
// IF/Wait  IF        Wait 4    Wait 1    Wait 1    Wait 1    Wait 1    Wait 1             
//   Term A RSP_RDYN                                                                       
//   LFunc  AND                                                                            
//   Term B RSP_RDYN                                                                       
// Branch1  Then 0                                                                         
// Branch0  Else 1                                                                         
// Re-Exec  Yes                                                                            
// Sngl/CRC Default   Default   Default   Default   Default   Default   Default            
// cmdwen       1         1         1         1         1         1         1         1    
// evtren       1         1         1         1         1         1         1         1    
// rspren       0         0         0         0         0         0         0         1    
// r_wn         1         1         1         1         1         1         1         1    
// olpwrn       1         1         1         1         1         1         1         1    
// Ctl-NoOp     0         0         0         0         0         0         0         0    
//                     
// END DO NOT EDIT     
// DO NOT EDIT ...                                                                         
//                                                                                         
// GPIF Waveform 1: Single W                                                                
//                                                                                         
// Interval     0         1         2         3         4         5         6     Idle (7) 
//          _________ _________ _________ _________ _________ _________ _________ _________
//                                                                                         
// AddrMode Same Val  Same Val  Same Val  Same Val  Same Val  Same Val  Same Val           
// DataMode Activate  Activate  Activate  Activate  Activate  Activate  Activate           
// NextData SameData  SameData  SameData  SameData  SameData  SameData  SameData           
// Int Trig No Int    No Int    No Int    No Int    No Int    No Int    No Int             
// IF/Wait  Wait 3    Wait 3    Wait 1    Wait 1    Wait 1    Wait 1    Wait 1             
//   Term A                                                                                
//   LFunc                                                                                 
//   Term B                                                                                
// Branch1                                                                                 
// Branch0                                                                                 
// Re-Exec                                                                                 
// Sngl/CRC Default   Default   Default   Default   Default   Default   Default            
// cmdwen       1         1         0         1         1         1         1         1    
// evtren       1         1         1         1         1         1         1         1    
// rspren       1         1         1         1         1         1         1         1    
// r_wn         1         0         0         0         0         0         0         1    
// olpwrn       1         1         1         1         1         1         1         1    
// Ctl-NoOp     0         0         0         0         0         0         0         0    
//                     
// END DO NOT EDIT     
// DO NOT EDIT ...                                                                         
//                                                                                         
// GPIF Waveform 2: FIFO Rea                                                                
//                                                                                         
// Interval     0         1         2         3         4         5         6     Idle (7) 
//          _________ _________ _________ _________ _________ _________ _________ _________
//                                                                                         
// AddrMode Same Val  Same Val  Same Val  Same Val  Inc Val   Same Val  Same Val           
// DataMode NO Data   NO Data   Activate  NO Data   NO Data   NO Data   NO Data            
// NextData SameData  SameData  SameData  NextData  SameData  SameData  SameData           
// Int Trig No Int    No Int    No Int    No Int    No Int    No Int    No Int             
// IF/Wait  IF        Wait 8    Wait 4    Wait 1    Wait 1    Wait 1    Wait 1             
//   Term A EVT_RDYN                                                                       
//   LFunc  AND                                                                            
//   Term B EVT_RDYN                                                                       
// Branch1  Then 0                                                                         
// Branch0  Else 1                                                                         
// Re-Exec  Yes                                                                            
// Sngl/CRC Default   Default   Default   Default   Default   Default   Default            
// cmdwen       1         1         1         1         1         1         1         1    
// evtren       0         0         1         1         1         1         1         1    
// rspren       1         1         1         1         1         1         1         1    
// r_wn         1         1         1         1         1         1         1         1    
// olpwrn       1         1         1         1         1         1         1         1    
// Ctl-NoOp     0         0         0         0         0         0         0         0    
//                     
// END DO NOT EDIT     
// DO NOT EDIT ...                                                                         
//                                                                                         
// GPIF Waveform 3: FIFO Wri                                                                
//                                                                                         
// Interval     0         1         2         3         4         5         6     Idle (7) 
//          _________ _________ _________ _________ _________ _________ _________ _________
//                                                                                         
// AddrMode Same Val  Same Val  Same Val  Same Val  Same Val  Same Val  Same Val           
// DataMode NO Data   NO Data   NO Data   NO Data   NO Data   NO Data   NO Data            
// NextData SameData  SameData  SameData  SameData  SameData  SameData  SameData           
// Int Trig No Int    No Int    No Int    No Int    No Int    No Int    No Int             
// IF/Wait  Wait 1    Wait 1    Wait 1    Wait 1    Wait 1    Wait 1    Wait 1             
//   Term A                                                                                
//   LFunc                                                                                 
//   Term B                                                                                
// Branch1                                                                                 
// Branch0                                                                                 
// Re-Exec                                                                                 
// Sngl/CRC Default   Default   Default   Default   Default   Default   Default            
// cmdwen       1         1         1         1         1         1         1         1    
// evtren       1         1         1         1         1         1         1         1    
// rspren       1         1         1         1         1         1         1         1    
// r_wn         1         1         1         1         1         1         1         1    
// olpwrn       1         1         1         1         1         1         1         1    
// Ctl-NoOp     0         0         0         0         0         0         0         0    
//                     
// END DO NOT EDIT     
                                              
// GPIF Program Code                          
// DO NOT EDIT ...                     
const char __xdata WaveData[128] =     
{                                      
// Wave 0 
/* LenBr */ 0x81,     0x04,     0x01,     0x01,     0x01,     0x01,     0x01,     0x07,
/* Opcode*/ 0x01,     0x02,     0x02,     0x02,     0x02,     0x02,     0x02,     0x00,
/* Output*/ 0x1B,     0x1B,     0x1B,     0x1B,     0x1B,     0x1B,     0x1B,     0x1F,
/* LFun  */ 0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x3F,
// Wave 1 
/* LenBr */ 0x03,     0x03,     0x01,     0x01,     0x01,     0x01,     0x01,     0x07,
/* Opcode*/ 0x02,     0x02,     0x02,     0x02,     0x02,     0x02,     0x02,     0x00,
/* Output*/ 0x1F,     0x17,     0x16,     0x17,     0x17,     0x17,     0x17,     0x1F,
/* LFun  */ 0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x3F,
// Wave 2 
/* LenBr */ 0x81,     0x08,     0x04,     0x01,     0x01,     0x01,     0x01,     0x07,
/* Opcode*/ 0x01,     0x00,     0x02,     0x04,     0x08,     0x00,     0x00,     0x00,
/* Output*/ 0x1D,     0x1D,     0x1F,     0x1F,     0x1F,     0x1F,     0x1F,     0x1F,
/* LFun  */ 0x09,     0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x3F,
// Wave 3 
/* LenBr */ 0x01,     0x01,     0x01,     0x01,     0x01,     0x01,     0x01,     0x07,
/* Opcode*/ 0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x00,
/* Output*/ 0x1F,     0x1F,     0x1F,     0x1F,     0x1F,     0x1F,     0x1F,     0x1F,
/* LFun  */ 0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x00,     0x3F,
};                     
// END DO NOT EDIT     
                       
// DO NOT EDIT ...                     
const char __xdata FlowStates[36] =   
{                                      
/* Wave 0 FlowStates */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Wave 1 FlowStates */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Wave 2 FlowStates */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Wave 3 FlowStates */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};                     
// END DO NOT EDIT     
                       
// DO NOT EDIT ...                                               
const char __xdata InitData[7] =                                   
{                                                                
/* Regs  */ 0xC0,0x00,0x00,0x1F,0xEE,0x4E,0x00     
};                                                               
// END DO NOT EDIT                                               
