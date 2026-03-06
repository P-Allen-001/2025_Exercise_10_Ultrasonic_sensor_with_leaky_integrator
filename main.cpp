#include "mbed.h"
 
#include "SRF05.h"

float Left_ultrasonic_sensor_filtered_value = 10;
float Right_ultrasonic_sensor_filtered_value = 10;

 SRF05 srf_Left(PA_10,PB_3); // Output from PA_10 (D2) is connected to the Trigger pin of the SRF05, Input to PB_3 (D3) is connected to the SRF05 Echo_Pin. 
 SRF05 srf_Right(PA_8,PA_9); // Output from PA_8 (D7) is connected to the Trigger pin of the SRF05, Input to PA_9 (D8) is connected to the SRF05 Echo_Pin.   
  

Serial      usb(USBTX, USBRX, 9600);

 int main() {
     while(1) {
         Left_ultrasonic_sensor_filtered_value = (Left_ultrasonic_sensor_filtered_value * 0.1) + (srf_Left.read() * 0.9);
         Right_ultrasonic_sensor_filtered_value = (Right_ultrasonic_sensor_filtered_value * 0.1) + (srf_Right.read() * 0.9);  
      printf("Left: %.1f"  , Left_ultrasonic_sensor_filtered_value) ;
      printf("  Right: %.1f\n", Right_ultrasonic_sensor_filtered_value);
      printf("\n");
      wait(0.05);

     } 
     
 }
