# Fan-Speed-Controller-with-Temperature

## Overview 
Temperature-based fan control using Atmega16 and LM35. 
* **temp < 15 degree**: Fan **off**
* **15 <= temp < 20 degree**: Rotate with **25%** of max speed
* **20 <= temp < 25 degree**: Rotate with **50%** of max speed
* **25 <= temp < 30 degree**: Rotate with **75%** of max speed
* **temp >= 30 degree**: rotate with **max** speed

## PCB 
You can redesign your PCB
The original PCB file is contained in the **PCB** folder `MAIN.SchDoc`

## Code
The code is stored in the **Src** folder
