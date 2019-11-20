// Esto es un ejemplo de una base que puedes usar para el proyecto



// Hacer las conexiones primero:
// Conectar un oscilador con forma de onda triangular (src)
// a una ganancia g
// y a la salida dac (digital to analog converter)
TriOsc src => Gain g => dac;

// la nota inicial 69 es A4
69 => float note;
// la frecuencia inicial 440 es A4
440 => float freq;
// la ganancia inicial 1
1 => float gain;

// esto declara una funcion que va a leer el estado del mouse. algo así debería
// leer el estado del puerto serial.
fun void mouseListener() {

    // Declarar un objeto HID (Human Interface device)
    Hid hid;
    // Declarar un mensaje para poder poner la informacion del HID ahí
    HidMsg msg;
    // Abrir el puerto HID
    hid.openMouse(0);
    // Imprimir el nombre el puerto HID (chout es igual q cout pero más gracioso)
    chout <= hid.name() <= IO.nl();

    // hacer esto por siempre... esta estructura es muy comun en chuck porque los
    // programas muchas veces no tienen final
    while(true){
        // en chuck el tiempo solo corre si se le hace chuck (=>) a now.
        // en este caso hacer hid => now es esperar a que el puerto hid haga algo
        hid => now;
        // Ya que el puerto entrego información vamos a leer la información
        // se hace en un while para leer todos los mensajes disponibles
        while(hid.recv(msg)){
            // Los mensajes pueden ser de tipo mouse Moution si el mouse se mueve
            if(msg.isMouseMotion()){
                // y pueden contener un delta horizontal o vertical
                if(msg.deltaX){
                    // usamos el horizontal para cambiar las notas ( se multiplica
                    // por 0.1 porque deltaX es 1 o -1 o 0 entonces para movernos
                    // en pasos mas pequeños)
                    0.1 * msg.deltaX +=> note;
                    // Definimos unos limites para las notas (no mayor a 80 y no
                    // menor a 20)
                    Math.max(Math.min(note, 80), 20) => note;
                    // convertimos la nota a frecuencie (midi to frecuency)
                    note => Std.mtof => freq;
                    // Esta es una manera alternativa de imprimir cosas al terminal
                    <<< freq >>>;
                }
                if(msg.deltaY) {
                    // multiplicamos la altura por 0.001 porque la ganncia solo va
                    // de 0 a 1 y esta invertido para que arriba sea más y abajo menos
                    // (usualmente deltaY positivo significa q el mouse se movió
                    // hacia abajo)
                    -0.001 * msg.deltaY +=> gain;
                    // limites para la ganacia
                    Math.max(Math.min(gain, 1), 0) => gain;
                    // imprimimos la ganacia
                    <<< gain >>>;
                }
                // También puede haber mensajes con los botones del mouse
                // en este caso si se oprime la ganancia se hace 1 y se no se
                // oprime la ganancia se vuelve 0.
                // Fíjate que hay dos ganancias separadas, una es la ganancia
                // del source q cambia con la posicion del mouse y la otra
                // es más como un boton de mute
            } else if(msg.isButtonDown()){
                1 => g.gain;
            } else if(msg.isButtonUp()) {
                0 => g.gain;
            }
        }
    }
}

fun void setFreq() {
    // Esto es una forma de solucionar un problema q vas a tener y es que
    // la velocidad del puerto serial no es tan rápida como la del audio
    // entonces es bueno interpolar para q la frecuencia no salte abruptamente
    // si te fijas esta ecuación esta diciendo que cada vez q se reciba la nueva
    // frecuencia (freq) la frecuencia del src solo va a cambiar por el 10% de
    // la diferencia con su frecuencia actual
    src.freq() + 0.1 * (freq - src.freq()) => src.freq;
}

fun void setGain() {
    // lo mismo que para la frecuencia
    src.gain() + 0.1 * (gain - src.gain()) => src.gain;
}

// Spork es un concepto importante. En C o C++ las instrucciones se dan de manera
// consecutiva, pero a veces es necesario hacer acciones en paralelo. A eso
// se le llama multithreading. En chuck para hacer acciones en paralelo podemos
// hacer SPORK q significa que esa funcion se va a ejecutar pero el codigo va a
// seguir sin esperar a que la funcion retorne! Recuerda que mouseListener() fue
// declarado anteriormente y que esa funcion de hecho nunca termina entonces es
// importante hacer spork o si no el codigo nunca pasaría de este punto
spork ~mouseListener();

// ahora que ya estamos escuchando el mouse, también vamos a hacer por siempre
// tres acciones: actualizar la frecuencia, actualizar la ganancia y adelantar
// el tiempo por un solo sample.
while(true) {
    setFreq();
    setGain();
    1::samp => now;
}

400.     600.       800
L.       L.         L.          L.         L.         L.         L.        
IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
         500 510 519 700