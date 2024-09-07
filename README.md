# Project OSSM M5 REMOTE
## Overview of the OSSM-M5-Remote

A Remote Control Platform for all ESP Controlled Sex Toys,with a focus on the [OSSM](https://github.com/KinkyMakers/OSSM-hardware) and related toys.

![Final Addon](image/remote.png?raw=true "Remote" )

Intially developed for the OSSM Project: 
https://github.com/KinkyMakers/OSSM-hardware

# [Assembly instructions Klick Here !](Assembly.md)
 

To help with development and design join the KinkyMakers Discord: https://discord.gg/MmpT9xE . Be sure to say hello in the #m5-remote channel. 

Works not with Official OSSM Firmware Right now.
This Branch is needed: https://github.com/ortlof/OSSM-Stroke

Supported in this version of the M5 remote:
## Supported sex toys in this version

| OSSM Machine | https://github.com/KinkyMakers/OSSM-hardware |

## Not Supported sex toys in this version

| EJECT | https://github.com/ortlof/EJECT-cum-tube-project | [A Work in Progress]




# Build the OSSM M5 Remote Yourself

## Bill Of Materials for sourcing Electrical Components

All Stacks are supported Now.

BOM is on Octopart for Easy Sourcing: https://octopart.com/bom-tool/rURYMuwB

PCB Files are located in the /OSSM-M5-Remote/Hardware/PCB folder if you want to make one yourself or use a different manufacturer other than PCBWay.

## Additional parts needed that are not found on Octopart:  

| Quantity | Part | Sourcing EU | Price € |
|----------|------|-------------|---------|
| 2x | M3x25mm Hex Head Cap Bolt | https://www.amazon.de/Edelstahl-Innensechskant-Bolzenset-Eisenrahmen-Mechanischer-Innensechskantschraube-Mutternset/dp/B07PPFT871/ | 12,97 € |
| 4x | M3x20mm Hex Head Cap Bolt | Comes as part of the set mentioned above | " | 
| 4x | Heat Set inserts M3 | https://www.amazon.de/ruthex-Gewindeeinsatz-St%C3%BCck-Gewindebuchsen-Kunststoffteile/dp/B08BCRZZS3 | 8,99 € |
| 1x | 3,7v 2000mAh Lipo Batterie Size 34,5 mm x 10,6 mm x 56 mm | https://www.amazon.de/EEMB-103454-2AhLithium-Schutzplatine-Isolationsbeschichtung/dp/B08214DJLJ/ | 14,89 € |
| 4x | Encoder Knob Bought or 3D Printed | https://de.aliexpress.com/item/1005001394286414.html | 5 € |
| 1x | OSSM M5 Remote PCB | KinyMaker Discord #M5-Remote Channel or https://www.pcbway.com/project/shareproject/M5Stack_Core2_Remote_Plattform_2cb5bac0.html | 15 € |

--------------------------------------------

| Quantity | Part | Sourcing US | Price $ |
|----------|------|-------------|---------|
| 2x | M3x25mm Hex Head Cap Bolt | https://www.amazon.com/dp/B09NR8X2LV | $17.99 |
| 4x | M3x20mm Hex Head Cap Bolt | Comes as part of the set mentioned above | " | 
| 4x | Heat Set inserts M3 | https://www.amazon.com/ruthex-M3-Threaded-Inserts-RX-M3x5-7/dp/B08BCRZZS3 | $10.99 |
| 1x | 3.7v 2000mAh Lipo Battery Size 34.5 X 56 X 10.6 mm (The wires will need to be reversed in the connector on this one! See Assembly instructions for more info.) | https://www.amazon.com/EEMB-2000mAh-Battery-Rechargeable-Connector/dp/B08214DJLJ/ | $14.99 |
| 4x | Encoder Knob Bought or 3D Printed | https://www.aliexpress.us/item/3256801207971662.html?gatewayAdapt=deu2usa4itemAdapt | $5.00 |
| 1x | M5 Remote PCB | KinyMaker Discord #M5-Remote Channel or https://www.pcbway.com/project/shareproject/M5Stack_Core2_Remote_Plattform_2cb5bac0.html | $30.00 |

## 3D Printed Parts Needed:

| Quantity | Part | Information |
|----------|------|-------------|
| 1x | Bottom.stl or Bottom_Adafruit_LIPO.stl or Bottom-Magnets.stl| There is a specific version for the wider Adafruit LIPO battery. Print with the base side facing down, 6 walls 20% Infill | 
| 1x | TOP-*-Keycap-Standoff.stl | Top Depends on your Keycap: Cherry or DSA (DSA is wider) | 
| 4x | M5_Remote_Knob_Customizable.scad | If you go for the 3d Printed knobs |

Filament - A good quality PLA works well. While there are no threads it is recommended that your printer is well calibrated.  

__Note:__
If you are one of the very small number of Version 1 PCB users, you will need to change your version to V1 in the config.h. The current version in GitHub is V2.

## Operation, or...how do I use it?

1. Power on the OSSM and let it home.
2. Power on the OSSM M5 Remote.
3. Press the left encoder to select 'Connect'
4. You can verify it is connected by looking in the top left corner, it should say 'connected'.
5. You can now begin use. You'll need to set the speed, depth and stroke to more than 0 and press the middle key to start. Start the speed out slow. 
