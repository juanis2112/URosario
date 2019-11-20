SinOsc osc => Gain g => dac;
3 => g.gain;

while(true){
  Std.rand2(60, 82) => int note;
  note $ float => Std.mtof => float freq;

  freq => osc.freq;

  100::ms => now;

}
