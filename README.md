# BITboy

A handheld oscilloscope and behavior setup debugger for neuroscientists. Your every-day companion for trouble shooting and setting up experimental instruments.

Read and write analog as well as digital signals with ease. Check continuity in electronic circuits with the continuity checker. It can be used as a handheld oscilloscope or connected to your pc on a desk for higher resolution.






<p align="center">
  <img src="./images/BITboy_bottom.png" width="400">
  <img src="./images/BITboy_top.png" width="400">
</p>


All provided files are in metric units (mm). The case can be 3D printed, while the cover can be lasercut or printed. The design aims at maximum reproduxibility with low total cost.

### File List


| Door-Module Component | Production Amount | Material |
| :---: | :---: | :---: |
| Arduino Holder | 1 piece | Acrylic glass 6mm, PLA or ABS |

All files are available as .STEP (for 3D CAD), .DXF Files (scaling: 1pt equals 1mm for laser cutting), .STL (3D Object for Printing) and .SVG (Open Source Vector Graphic).

And DXF

### Commercial Parts List


| Item | Quantity | Notes | Product Example Link |
| :---: | :---: | :---: | :---: |
| Arduino Nano | 1 piece | with pin headers | [arduino.cc](https://store-usa.arduino.cc/products/arduino-nano?selectedStore=us) |




Lasercutting
--------------------

We used a Trotec Speedy Flex lasercutter with a 100W CO2 laser with the following settings:


| Parameter | Cutting Quality |
| :---: | :---: |
| Power |  |
| Speed |  |
| Laser Source |  |
| Frequency |  |
| Passes |  |
| Power Correction |  |
| z-Offset |  |
| Resolution |  |



3D Printing
--------------------
We suggest printing with PLA, tough PLA or ABS for best results. Any standard print settings will provide aceptable results. Avoid fancy materials to reduce cost and effort.

For the case, we used a Babulab A1 mini filament printer.


Wiring Diagram
--------------------
<p align="center">
  <img src="./images/Electronics_Diagram.png" width="800">
</p>


PCB Layout
--------------------
<p align="center">
  <img src="./images/PCB_top.png" width="400">
  <img src="./images/PCB_bottom.png" width="400">
</p>









Modular-Door Control Logic
--------------------

Input detection is via digital input and internal pullup resistor. Consequently, 0V (or connecting to GND) at the signal in port will open the door, while 5V will close it again. Sync ports will be set to the corresponding output current.


| BNC In Signal | Door Status | BNC Sync 1 Status | BNC Sync 2 Status |
| :---: | :---: | :---: | :---: |
| 5V (High) input | Closed (Up) | 5V output | 5V output |
| 0V (Low) input | Open (Down) | 0V output | 0V output |