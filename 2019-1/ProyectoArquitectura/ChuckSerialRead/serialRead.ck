SinOsc osc => dac;

60 => Std.mtof => osc.freq;
0 => osc.gain;

SerialIO.list() @=> string list[];

for(int i; i < list.size(); i++)
{
    chout <= i <= ": " <= list[i] <= IO.newline();
}

SerialIO cereal;
cereal.open(3, SerialIO.B9600, SerialIO.ASCII);

1::second => now;

while(true)
{
    cereal.onLine() => now;
    cereal.getLine() => string line;
    chout <= "Line: ";
    if(line$Object != null) {
      chout<= line <= IO.newline();
    }

    if (line == "Hola")
      1 - osc.gain() => osc.gain;
}
