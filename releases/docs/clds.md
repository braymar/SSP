# Clds : Texture synthesizer 

clds - an implementation of Mutable Instrument Clouds for the Percussa SSP.

## Change Log

1.2.0 requires new ssp firmware for vst sdk 2 !
new cv input parameters mix,spread,freeze, feedback,reverb
separate trig and freeze to different cv inputs
ssp preset now stores/loads vst parameters
clicking encoder resets values

note: you will loose presets, as these are now stored in the SSP preset

1.1.0 internal release only - code cleanup

1.0.0 Initial Release 

## Developer: TheTechnobear
I develop these plugins for free, please consider supporting my efforts with a donation.
https://ko-fi.com/thetechnobear


## General Usage 

The best source of information about this module is the Mutable Instruments Clouds manual
https://mutable-instruments.net/modules/clouds/manual/

This document is based on the LATEST version of the plugin


## Differences
Generally, I've tried to make as close as possible to the hardware module.

Clouds hardware runs at 32kHZ sample rate, clds runs on Percussa runs at 48kHz.
There is currently no lo-fi or mono mode.

## Input / Outputs
like MI module, 
if you only enable LEFT input, then it will treat as mono and use left for right input
if you only patch the LEFT output, then this will contain a sum of left and right outputs.

## Tips

Play with the different modes - personally my favourite for 'general purpose' patching is looping delay :) 

In Gain - 0.0 = no gain (or 1x) , 1.0 goes to 17x for very quiet signals, if you turn it up to much you will distort, 
so listen carefully, and I'd recommend err'ing on the side of quiet.


I only recommend using at 48Khz sample rate, as this is how the clouds code is designed.
Using at other sample rates will lead to incorrect pitch, and possible other oddities.
( the only solution would be downsample/upsampling but this is sub-optimal on a platform such as the SSP)


## Credits: 

Percussa SSP - https://www.percussa.com/ 

Mutable Instruments : https://mutable-instruments.net/
Thanks to Emilie for sharing her code with the community.
please note: this VST in no way endorsed or supported by Mutable Instruments.
