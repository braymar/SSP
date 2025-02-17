# swat - swiss army tool

swat is designed to be like the famous swiss army knife, a useful utility to bring out to solve your problems.

## Change Log

1.0.0 Initial Release 

## Developer: TheTechnobear
I develop these plugins for free, please consider supporting my efforts with a donation.
https://ko-fi.com/thetechnobear


## General Usage 

The goal of SWAT is pretty open ended, its designed to be a plugin that I can extend quickly and easily.
It's inspired by Expert Sleepers Disting (but shares no code etc...)

The plugin can run a variety of algorithms, that can do a variety of (unrelated) functions.

The 'interface' into swat is the same for all algos - each has 3 inputs X, Y and Z, and has 2 outputs A and B.
(This is fixed and cannot change!)

I aim to use thee as follows...
### inputs
X - primary input signal
Y - secondardy modifier signal
Z - third input, often a gate or trigger

### outputs 
A - main output
B - alternative output (often, will be inverse of A, depending on algo)

however, the specific meaning of each parameter is particular to each algo.

# important notes
- most algos may be designed to work at audio rate.
- different algos will have different computational costs
- many inputs are optional, and have 'sensible' defaults (particularly y and x)
- check inputs... they aim to be consistent
- unconnected outputs will usually result in less cpu (dependent on algo)
- input gates are considered high > 0.5
- output gates are 0.0 low, 1.0 high (note: unipolar! )

# note on signals levels
Theoretically, on the SSP , we have -5v to +5v currently -1.0 to 1.0f, where A4 = 440 hZ = 0v. where an octave = 0.2.
however, CV inputs are **currently** NOT calibrated to this theoretical values.
instead A4 = 0.02325f, and an octave is approximately 0.18837.

Usually, the user does not need to know/care about this, as all pitch voltages take this into account.
however, when mapping or using external voltages this can become important.
all SWAT algorithms that explicitly deal with notes/pitch take this into account.


# Algorithms

### Display
No Outputs

Displays X, Y, Z inputs as float, voltages and note values

Tips: 
I use mainly to be able to see note values (including cents)

### Min Max
A = min(X,Y)
B = max(X,Y)
Z gate

Returns min and max signals

Tips:
Z acts a kind of sample n' hold, also only using calculating min/max when high.

### Switch
A = Z > 1 , X else Y
B = Z > 1 , Y else X

outputs flip between X, Y depending n Z

Tips:
Handy simple switch alternative to MSW8 

### Transpose 
A = X + Note A
B = Y + Note B

Transposes pitch CV.
A0 = zero transpose, A#4 = +1 semi ,  A1 = +1 Octave etc.

Tips: 
if X is disconnected, its defaults to 0v , so A = Note A as v/oct

### Comparator
A = gate X > Y
B = ! A
Z Hysterisis

Returns a gate where X > Y
Hysterisis is useful X might be fluctuating slightly.

### Windowed Comparator
A = gate X > (L-Y) & X < (H+Y)
B = ! A
Z Hysterisis

Returns gate high when X is between low and high.
Y acts as a 'spread' to low/high
Hysterisis is useful X might be fluctuating slightly.

Tips:
if you set low/high to the same value (e.g zero), you can use Y to modulate around this.
low and high set to same value plus hysterisis allow detection of a particular value (with voltage/float imprecision accounted for)


### Note Comparator 
A = gate (X > L  & X < H ) && Y
B = ! A
Z Hysterisis

Returns gate high when X is between low and high notes
Hysterisis is useful X might be fluctuating slightly.

Tips:
Z is used to allow a bit of quantization around note values.
Low and High the same can detect a particular note 
e.g. to trig a particular sample on SAM from a given note!

### Logic - And
A = X AND Y
B = ! (X AND Y)
Z is gate

result is X AND Y , where high = 0.5
Z acts as a sample and hold


### Logic - Or
A = X OR Y
B = ! (X OR Y)
Z is gate

result is X OR Y , where high = 0.5
Z acts as a sample and hold


### Logic - Xor 
A = X XOR Y
B = ! (X XOR Y)
Z is gate

result is X exclusive OR Y  where high = 0.5
Z acts as a sample and hold

tips:
XOR = X or Y NOT both !


### Map Value to Value
A = X : in range to out range
B = Y : in range to out range

Map an input range to an output range.
output values are clipped to min/max out.

Tips:
many usages e.g. converting unipolar to bipolar.
by making output min > max, you can invert ranges!

note: often you can do the same/similar by using the SSP scale and offset features.


### Map Note to Value
A = X : in range to out range
B = Y : in range to out range


Map an input range of pitch CV to an output range.
Similar to Map Value to Value, however, this algo takes ito account how pitch is represented and convert to a numeric range.

Tip: 
this is useful when we want to convert a pitch cv into a modulation signal - mapping a midi keyboard octave to a range 
e.g  C4 - C5 -> -1.0 to +1.0 for start position of a sample or granular buffer


### Map Note to Note 
A = X : in range to out range
B = Y : in range to out range
Similar to Map Value to Value, however, this algo takes ito account how pitch is represented and convert to a new pitch.
This could be seen as a kind of transposition, however, it will not only offset the pitch, it will also scale or invert.


### Counter
A = A + -0.5>X<0.5
B = B + -0.5>Y<0.5
Z = reset

A simple counter that increase by step amount when X/Y exceeds 0.5
however,  X/Y are treated as bipolar
so X > 0.5 steps forward , X < -0.5 steps backwards !

Z high will reset to the minimum value on true, and stay there until taken low.


Tips:
This is audio rate, so this can for a kind of stepped phasor.
Useful with MSW8 to act as a sequential switch

### Delay
X = Signal
Y = Delay (% buffer)
A = Delayed X ( Delay + Y)
B = Delayed X ( Delay + Y) + X

This is intended as a 'microtime delay' down to sub millisecond, hence the small values by default.
(it will go to 5 seconds, but Delay parameter is more scaled to small size values ;) 

Y is an offset to Delay time.
B is wet + dry signal.

Important notes:
Changing the SIZE parameter resets the delays, if you want to modulate delay time then use Y with a larger SIZE parameters
modulation of Y is not really intended for audio effects, for effeciency it is read at control rate ( 128 samples@48k), so low audio rate, 
and there is no interpolation across sample reads, and changes of Y are immediate i.e. its not really the same as changing read head speed.

I've no intention of changing this ;) ... I'd like to make a more elaborate audio delay FX with speed modulation and multi head but this will be a separate VST.



### Precision Adder
A = X + Y + Z
B = X - Y - Z

Sums or Subtracts X/Y/Z 
mostly a development tool, given SSP has native summing of inputs.


### Constant 
A = Constant A + X
B = Constant B + Y


mostly a development tool, given DCG can output constant values and SSP has native summing of inputs.


tips:
if X/Y are disconnected then they are 0v, so A/B are the constant values


## Can you add this algorithm?
Possibly...  of course this comes down to a couple of aspects.
- do I have time :) 
- does this fit SWAT? or would it be better of as a dedicated module?

Note: Whilst Disting may be a source of ideas, I do **not** plan to implement its algorithms!
This would be a mammoth task, and also pretty pointless... 
there are many functions in Disting that can already be achieved by other modules or by the SSP natively.
e.g. you dont need a precision added on the SSP since summing is automatic and lossless on the SSP anyway.

We are not limited by hardware production costs or physical space..
So more complex functions would likely be better implemented as dedicted modules.
e.g. having simple sample/looper in SWAT doesn't really make much sense, it'd be better to have a dedicated module to do this.




This document is based on the LATEST version of the plugin


## Tips
see individual algos :) 
most important tip : read the help text on each algo, whilst inputs/outputs are hopefully consistent - sometimes they might be unexpected


## Credits: 

Percussa SSP - https://www.percussa.com/ 

