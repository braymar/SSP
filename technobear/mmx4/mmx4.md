# mmx4 matrix mixer

a matrix mixer with 4 stereo inputs and 4 stereo outputs, controllable via cv


## Change Log

1.0.0 Initial Release 

## Developer: TheTechnobear
I develop these plugins for free, please consider supporting my efforts with a donation.
https://ko-fi.com/thetechnobear


## General Usage 

This document is based on the LATEST version of the plugin

A matrix mixer allows inputs to be mixed to multiple outputs.
In the case of this plugin each input ( 1 - 4 ) is stereo, and also each output ( A - D).

the user can mix with the parameters on the UI and also via CV.

the mixing can be consider like a bipolar vca or attenuverter, so can also be used to invert signals (with negative vca)


notes:
- the 'level' is per input/output pair e.g.  2D, 3B 
- all mixing is done at audio rate
- the parameter vca value is **added** to any incoming vca cv




## Tips

## click encoder
this will set a non-zero value to zero (i.e. clear it) , or a zero/clear value to 1.0


### CV mixing
the matrix mixer can be for audio or cv mixing, mixing cvs can open up a whole new world of modulation shapes.


### Using vca cv

you can use either bipolar cv (e.g. LFO) or unipolar (ENV) for the vca input.
BUT should should remember a negative value will **invert** the wave form (which can be fun)

IF you do not want this and prefer it going to zero you have two choices
a) use the Percussa's excellent scale and offset controls  e.g. scale by 0.5 and offset  by +1.0
b) use the VCA level on the UI and set to 1.0 ... this will make it go from 0.0 to 2.0 , so it'll be loud unless you scale it ;) 


### Stereo
whilst the mixer is stereo, you can use if for mono signal, the mixer is optimised to only calculate for the input and outputs connected.

also there is not 'connection' between left and right channels, the limitation is they use the same vcas.

whilst panning is not implemented, if you chain two mmx4 this is easy to achieve, with 2 mmx, connected something like:

1L->1L  cv=pan       -> 1L  vca1 -> 1L
2L->1R  cv=pan       -> 2L  vca1 -> 2R
1R->2L  cv=-ve pan   -> 1R  vca2 -> 1R
2R->2R  cv=-ve pan   -> 2R  vca2 -> 2R



## Possible future updates
Some ideas I have for improvements

vca 'scaling' 
there are a couple of different modes I see useful that do not use linear scaling
exponential scale - convert the linear vca values into exponential, useful for audio levels
pan law - if we want to cross fade, then things like cos/sin pan laws are often more useful than linear fading.



## Credits: 

Percussa SSP - https://www.percussa.com/ 

