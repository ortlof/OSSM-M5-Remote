
# Assembling the OSSM M5 Remote

**Some important notes**
* Assembly will require soldering of small surface mount components in addition to through hole components. Be sure you have the proper tools and supplies:
    * Solder reflow oven or hot air gun with nozzles. You can use an old toaster oven as a reflow oven, just do not use it for food again after that.
    * Low temperature solder paste
    * Tweezers
    * Soldering iron
    * Rosin core solder
    * Flux
    * optional helping hands to hold the PCB while you solder
    * optional stencil provided by the PCB Manufacturer (not necessary but would make things easier)

* Due to a lack of standardisation in LIPO battery polarity it is important to verify how yours is configured. If the battery is reversed it will result in the CORE M5 Stack being damaged. You may have to reverse the female pins in the connector so they align with the expected polarity on the PCB.

## Solder the components

1. If you purchased a stencil from PCBWay/ Your chosen PCB Manufacturer, align it over the PCB and tape it in place. Add a blob of low temperature solder paste to the stencil and scrape it across the holes with a credit card or similar. When you lift the stencil away the PCB should now have solder paste on it in the correct places. Example photos below are from PCBWay and are not of the OSSM M5 Remote PCB  
  
  
![solderPaste](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/7bfadb82-3385-47ea-94f3-8652fe080af8)
![solderPaste2](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/62b96751-cfc3-4502-a370-034971e312ae)
![solderpaste3](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/51d70cb2-353b-47d7-a89a-ca4f13daa100)
  
    
    

If you did not purchase a stencil then you will need to very carefully coat the solder pads of the PCB with solder paste. It doesn't need a ton.

![without_stencil](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/6e634335-d5ee-4417-ba8e-f26e55206448)  

Photo Credit Xue Ming. The amount of solder paste in the above photo is a little excessive.

2. Carefully place the 11 10k ohm resistors (Bourns CR1206-JW-103ELF) on the solder paste using tweezers. The polarity doesn't matter. Apply heat using a heat gun or reflow oven. The solder paste container will state what temperature to use.  


![Resistors](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/87db8ef8-29a1-498f-b41d-2c0ce7b44b00)

3. Next, place the button encoders (Bourns PEC12R-4220F-S0024) at U1 and U4. Add flux to the pins and pad and solder the button encoders in place with a soldering iron.

4. Repeat the same for U2 and U3, adding flux and soldering the regular encoders (Bourns PEC12R-4220F-N0024)

5. The (Cherry MX1A-F1NN /  switch is soldered to the center position in the white square.

6. Next, the headers. Insert the headers from the front of the PCB (Amphenol Communications Solution 10129381-916001BLF), add a generous amount of flux to the back side and solder each pin.  


![PCB-Soldered](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/6c788856-cce5-42a2-8c96-6fc6ae87ce2c)

7. Finally we will solder the battery connector (JST S2B-PH-K-S(LF)(SN)) on the back side of the PCB. The positive pin is the pin closest to the bottom edge of the PCB, the negative pin is the pin the closest to the top edge of the PCB.  


![BatteryConnectorSoldered](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/6c1c1cd7-7d8b-4631-922d-3177ff94a039)

8. Again pay special attention to the polarity of the Lithum battery you have, checking to see if the negative terminal of the battery connector will align with the negative pin of the connector on the PCB. Remove the wires from the battery terminal and reverse them if you need to (I had to, for example).

![FlippingWires](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/232e0879-97b6-4940-85c0-7890638a2a90)

## 3D printed parts

All parts are printed with 6 walls and 20% infill with a .04 nozzle. No supports and no brim (just a skirt).

A good quality PLA works well. While there are no threads it is recommended that your printer is well calibrated.  

* Be sure to choose the correct back to print based on the battery that you source 

    USA - Adafruit 485-2011 / or [Alternate](https://www.amazon.com/EEMB-2000mAh-Battery-Rechargeable-Connector/dp/B08214DJLJ/) uses 'Bottom_Adafruit_Lipo.stl' OR you can use 'Bottom-Magnets.stl' if you want to add 6 x 3mm magnets.

    Other countries - [RS Pro 1449405](https://uk.rs-online.com/web/p/speciality-size-rechargeable-batteries/1449405) uses 'Bottom.stl', or if you want to use magnets in the base you can use 'Bottom-Magnets.stl' that will accept 6 x 3mm magnets.

* You have options for the top depending on the keycap type you choose (cherry vs DSA). 

    If you chose to buy a DSA keycap go with 'TOP-DSA-Keycap-Standoff_Bigger_Ecoder_Space.stl'

    If you chose to buy a Cherry Keycap go with 'TOP-Cherry-Keycap-Standoff_Bigger_Ecoder_Space.stl'

* You can print encoder knobs or purchaes separate ones, 'M5_Remote_Knob_Customizable.scad'

* If you would like to mount the OSSM M5 remote to a mini tripod you can print the excellent holder by KinkyMakers Discord community member GHHOSS, the file is called  'M5_Tripod_Holder_v3.stl' and can be found in the 'GHHOSS_tripod_mount' folder.

* Finally you will add the M3 brass heatset inserts to the underside of the **TOP** piece.

## Final Assembly

1. Remove the M5 Core2 MIC/MPU Module from M5 Core2 Bottom, then unscrew the grey bottom and remove internal battery. Store the screws, the back and battery somewhere in case you want to use the M5 Stack Core2 for another project later.

2. Affix the battery to the bottom case with double sided tape.

![1](image/bottom+battery.jpg?raw=true "1" )

3. Connect Battery to PCB connector on the back side of the PCB.

![2](image/bottom+pcb.png?raw=true "2" )

4. Insert the PCB into Bottom case. 
![AffixBattery](https://github.com/NightmareSyndrome/OSSM-M5-Remote/assets/131713378/392cc5ae-f787-404a-b128-40521d7e20d7)

5. Connect the M5 Core2 to the headers on the PCB and fasten with two 25mm M3 Bolts to Case.

![3](image/bottom+m5.jpg?raw=true "3" )

6. Put top on Remote and fasten with four M3 20mm Bolts to the Case.

![4](image/full-remote.jpg?raw=true "4" )

7. Install the Mx Cap and Encoder Knobs.

8. Charge the battery fully.

## Upload Software

1. Visit the [M5 website to download and install the drivers](https://docs.m5stack.com/en/core/core2) for the Core2 on your machine.

2. Clone or download this repository. If you download it as a zip, extract the files.  
**Note:** If you are one of the very small number of Version 1 PCB users, you will need to change your version to V1 in the config.h. The current version in this repository is V2.

3. Download Visual Studio Code and set up [PlatformIO](https://docs.platformio.org/en/latest/integration/ide/vscode.html#installation)  or [if you would prefer to watch a video](https://docs.platformio.org/en/latest/integration/ide/vscode.html#installation) - Thanks KinkyMakers Disord community admin Ka D'argo for the video!

Open the OSSM M5 Controller repository from step 2 in VS Code by clicking "File" > "Open Folder" and selecting the folder.


4. Once PlatformIO is set up you can select the M5 Core2 from your list of devices by clicking the 'Auto' button at the bottom center of the screen in the blue ribbon. If you aren't sure which device is the Core2 you can open DeviceManager on Windows and expand "Ports (COM & LPT)", then unplug the Core2 and plug it in again while keeping an eye on Device Manager to see what changes.

__Note:__
If you are one of the very small number of Version 1 PCB users, you will need to change your version to V1 in the config.h file. The current version in this GitHub repository is V2.

5. Click the upload button at the bottom left of the screen. The program will build then automatically upload to the M5 Core2. Once the software has succesfully uploaded you may disconnect the Core2 from your computer.

6. Next, Clone or download the M5 fork of the OSSM Stroke Engine from [here](https://github.com/ortlof/OSSM-Stroke) using the same method as mentioned in Step 2.

7. Open the OSSM Stroke repository from Step 5 in VS Code, again by clicking "File" > "Open Folder" and selecting the folder.

8. Now connect the OSSM board to your computer using a USB cable. You can look for it in DeviceManager the same way as you did in step 4. [You can also reference this link for help](https://github.com/KinkyMakers/OSSM-hardware/blob/master/OSSM%20PlatformIO%20Readme.md)

9. Click upload.
