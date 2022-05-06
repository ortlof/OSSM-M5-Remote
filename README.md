# OSSM-M5-Remote

PCB Files in Folder Fixed Development of v2 is running.

It depends right now on this OSSM PCB Base Code:

https://github.com/ortlof/OSSM-Stroke/tree/OSSM_ESP_Remote

You need to set you mac adresses in both codes right now Manual:

After building both codes they display MAC's in Serial Console.
Find Line and Change to your OSSM MAC in OSSM code you have to Set the mac of your Remote. 

MAC in Serial Looks like: 34:86:5D:57:F5:84

Change to this:

"#define OSSM 1"
"uint8_t OSSM_Address[] = {0x34, 0x86, 0x5d, 0x57, 0xf5, 0x84};"

# BOM
BOM is on Octopart: https://octopart.com/bom-tool/rURYMuwB

# Assembly will follow