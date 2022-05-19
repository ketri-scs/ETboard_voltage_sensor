/******************************************************************************************
 * FileName     : voltage_sensor.ino
 * Description  : 전압 센서로 배터리 전압을 읽기
 * Author       : 손철수
 * Created Date : 2022.05.18
 * Reference    : 
 * Modified     : 
 * Modified     : 
******************************************************************************************/

// Define analog input
#define ANALOG_IN_PIN A3
 
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 

//float R1 = 29830.0;
//float R2 = 7480.0; 
 
// Float for Reference Voltage
float ref_voltage = 3.3;
//float ref_voltage = 3.296;

 
// Integer for ADC value
int adc_value = 0;
 
void setup()
{
   // Setup Serial Monitor
   Serial.begin(9600);
   Serial.println("DC Voltage Test");
}
 
void loop(){
   // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   //adc_voltage  = (adc_value * ref_voltage) / (4095); 
   adc_voltage  = (adc_value * ref_voltage) / (4095-1024+512-256); 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 
   
   // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.println(in_voltage, 2);
  
  // Short delay
  delay(500);
}

//==========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//==========================================================================================
