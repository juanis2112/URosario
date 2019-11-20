Gain masterVolume => NRev verb => Gain OnOff => Gain louder => dac;
// Object of type Gain named masterVolume connected to (P)
// Object of type NRev named verb (Reverberation)
// Object of type Gain named OnOff (Switch1)
// Object of type Gain named louder (to make it louder)
SinOsc osc1 => Gain isOn1 => masterVolume; // object of type SinOsc (sine wave) named osc1 to Gain isOn to masterVolume
TriOsc osc2 => Gain isOn2 => masterVolume; // object of type TriOsc (triangle wave) named osc2 to Gain isOn to masterVolume
SinOsc osc3 => Gain isOn3 => masterVolume; // object of type SinOsc (sine wave) named osc3 to Gain isOn to masterVolume

verb.mix(0.2); // Reverberation with mix at 20% (80 percent original signal 20 percent reverberation)
louder.gain(3); // gain object with gain 3

SinOsc vibrato => blackhole;  // connect SinOsc to a blackhole
6 => vibrato.freq;            // Frequency of the vibrato 7Hz rate of variation
3 => vibrato.gain;            // Amplitude of the vibrato (change frequency by +/- 4Hz)

float uTar;
float rTar;
float pTar;

float uCur;
float rCur;
float pCur;
float s;
float s1;
float s2;
float s3;

1.0 - Math.exp(-1.0/(50::ms/1::samp)) => float b0;
1.0 - Math.exp(-1.0/(10::ms/1::samp)) => float b1;
1.0 - Math.exp(-1.0/(10::ms/1::samp)) => float b2;

[60, 62, 64, 65, 67, 69, 71, 72] @=> int n[];


3 => int serialId;            // Index of serial port

/* SerialIO.list() @=> string list[];

for(int i; i < list.size(); i++)
{
    chout <= i <= ": " <= list[i] <= IO.newline();
} */

fun void processLine(string info){
    info.find('u') + 1 => int uPos;
    info.find('r') + 1 => int rPos;
    info.find('p') + 1 => int pPos;
    info.find('s') + 1 => int sPos;
    info.find('b') + 1 => int bPos;
    info.find('c') + 1 => int cPos;
    info.find('d') + 1 => int dPos;
    info.find(';') + 1 => int ePos;

    if (ePos * dPos * cPos * bPos * sPos * pPos * rPos * uPos == 0)
        return;

    // substring returns a string starting in pos uPos of length rPos - uPos + 1
    // atof converts string into double
    info.substring(uPos, rPos - uPos - 1) => Std.atof => uTar;
    info.substring(rPos, pPos - rPos - 1) => Std.atof => rTar;
    info.substring(pPos, sPos - pPos - 1) => Std.atof => pTar;
    info.substring(sPos, bPos - sPos - 1) => Std.atof => s;
    info.substring(bPos, cPos - bPos - 1) => Std.atof => s1;
    info.substring(cPos, dPos - cPos - 1) => Std.atof => s2;
    info.substring(dPos, ePos - dPos - 1) => Std.atof => s3;
}

// function to read the serial port
fun void serialListener() {
    SerialIO arduino; //object of type SerialIO (input output) named arduino
    arduino.open(serialId, SerialIO.B115200, SerialIO.ASCII); // Open port 3 with BaudRate 115200 and read as ASCII

    while(true) {
        arduino.onLine() => now;          // Wait a line to continue reading
        arduino.getLine() => string line; // read a line into string
        if(line$Object != null)           // verify that the line as an object is not null
           processLine(line);             // process the line
    }
}

// function to print data every half a second
fun void printer() {
    while(true){
      chout <= "Note (midi Note) = " <= (uCur$int);
      chout <= "\t Amplitude (dB) = " <= (rCur$int);
      chout <= "\t Master Volume (dB) = " <= (pCur$int);
      chout <= "\t Switch = " <= s;
      chout <= "\t Button1 = " <= s1;
      chout <= "\t Button2 = " <= s2;
      chout <= "\t Button3 = " <= s3 <= IO.newline();
      1::second/2.0 => now;
    }
}


fun void interpolU(){
    uTar$int => int u;
    uCur + b0 * (n[u] - uCur) => uCur;
}
fun void interpolR(){
    rCur + b1 * (rTar - rCur) => rCur;
}
fun void interpolP(){
    pCur + b2 * (pTar - pCur) => pCur;
}

fun float dbtoamp(float db) {
  return Math.pow(10, db/20.0);
}

spork~ serialListener();
spork ~ printer();
while(true) {
    // Interpolate values and apply transformations before applying to oscillators
    interpolU();
    interpolR();
    interpolP();

    // Vibrato
    vibrato.last() => float freqDelta; // last returns the last value of signal at current time
    uCur => float note;
    note => Std.mtof => float freq; // midi note to frequency

    // Frequency
    freq + freqDelta => osc1.freq;
    freq * 3.0/2.0 + freqDelta => osc2.freq;
    freq/2.0 + freqDelta => osc3.freq;

    // Amplitude
    rCur => dbtoamp => float amp; // dbtolinear
    amp => osc1.gain;
    amp => osc2.gain;
    amp * 0.8 => osc3.gain;

    // MasterVolume
    pCur => dbtoamp => masterVolume.gain;

    // Switches
    s => OnOff.gain;
    s1 => isOn1.gain;
    s2 => isOn2.gain;
    s3 => isOn3.gain;

    1::samp => now; // Advance 1 sample
}
