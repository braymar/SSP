# Plts : macro oscillator 

plts - an implementation of Mutable Instrument Plaits for the Percussa SSP.

## Change Log
1.0.0 Initial Release 

## Developer: TheTechnobear
I develop these plugins for free, please consider supporting my efforts with a donation.
https://ko-fi.com/thetechnobear


## General Usage 

The best source of information about this module is the Mutable Instruments Rings manual
https://mutable-instruments.net/modules/plaits/manual/


This document is based on the LATEST version of the plugin

## Tips

I only recommend using at 48Khz sample rate, as this is how the Plaits code is designed.
Using at other sample rates may lead to incorrect pitch, and possible other oddities.
( the only solution would be downsample/upsampling but this is sub-optimal on a platform such as the SSP)


### FM / Morph / Timbre modulations are not working !?
This is a 'plaits' feature - theres built in 'attenuverters', which I default to zero (see next tip!), 
you should turn these positive or negative to apply some modulation.
Why? we already have attenuation in the SSP... indeed but for compatiblity with 'internal modulation' we need, see below.


### when I trig plaits I get some wierd modulation, why?
When the FM, Morph and Timbre CV inputs are not connected, Plaits has a built in envelope modulation for these parameters,
this can be positive or negative (0 = no modulation).
This is particular useful for percussive sounds, e.g. you can do a kick drums pitch env just by altering the FM modulation amount.


## Credits: 

Percussa SSP - https://www.percussa.com/ 

Mutable Instruments : https://www.mutable.com/ 
Thanks to Emilie for sharing her code with the community.
please note: this VST in no way endorsed or supported by Mutable Instruments.
