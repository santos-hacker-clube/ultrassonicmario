
/* ==================================================
 *  
 * Programa desenvolvido na Noite Arduino com Pizza
 *
 * ==================================================
 * 
 * Programa: UltrassonicMario - Theremin ultrassônico MarioBros
 * 
 * Autores: Antonio Braga (github.com/piscaleds)
 *	       Ewald Cordeiro (github.com/ewaldsc)
 *          Filipe Rito (github.com/filipecavalheiro)
 *
 * Protótipo - Instrumento musical eletrônico que lê a distância 
 *             entre o sensor ultrassônico e a mão da pessoa,  
 *             controlando assim a velocidade com que o buzzer 
 *             toca o tema do MarioBros.
 *
 * 
 */



// MATERIAS
 
// arduino 
// sensor ultrassônico hc sr04  
// buzzer 
// jumpers



// CIRCUITO


// arduino uno + sensor HC SR04 + buzzer  https://github.com/santos-hacker-clube/ultrassonicmario/blob/master/ultrassonicmario_theremin_arduino.png

//        sensor

//        5V__________________VCC  [ ultrassonic ]
//        pino 4______________TRIG [ ( (O   O) ) ]
//        pino 5______________ECHO [             ]
//        GND_________________GND  [  HC_SR04    ]

//        buzzer            

//        pino 8______________+ buzzer
//        GND_________________- ((Zz)))  				  




//  REFERÊNCIAS
  
//  1. https://www.filipeflop.com/blog/sensor-ultrassonico-hc-sr04-ao-arduino/
//  2. Arduino Mario Bros Tunes With Piezo Buzzer and PWM by: Dipto Pratyaksa
//  3. Arduino.cc https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
//  4. https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
  



//  biblioteca - Ultrasonic.h


#include <Ultrasonic.h>


#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define melodyPin 8


//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Mario melodia
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melodia
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};
 
void setup(void)
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);//buzzer
  pinMode(13, OUTPUT);//led 
 
}
void loop()
{
  //toca mario
  sing(1);

}
int song = 0;
 
void sing(int s) {

  
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
     
      int noteDuration = 1000 / underworld_tempo[thisNote];
 
      buzz(melodyPin, underworld_melody[thisNote], noteDuration);
 
      
      // a duração da nota + 30% 
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // para
      buzz(melodyPin, 0, noteDuration);
 
    }
 
  } else {
 
    Serial.println(" 'UltrassonicMario Serial'");
    int size = sizeof(melody) / sizeof(int);
    
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 1000 / tempo[thisNote];
      //  Serial.println(noteDuration); //Printa na serial duração da nota
      
      buzz(melodyPin, melody[thisNote], noteDuration);
 
      
      // a duração da nota + 30% 
      int pauseBetweenNotes = noteDuration * 1.30;
      //Serial.println(pauseBetweenNotes); //Printa na serial pausa entre notas
      delay(pauseBetweenNotes);
 
      // para
      buzz(melodyPin, 0, noteDuration);
 
    }
  }
}
 
void buzz(int targetPin, long frequency, long length) {
  float cmMsec, mult;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  if(cmMsec>20)cmMsec=20;
  if(cmMsec<4)cmMsec=4;
  mult = ((cmMsec-4)/16)+0.5;
  Serial.println(mult);
  digitalWrite(13, HIGH);
  long delayValue = mult*1000000 / frequency / 2; //calcular o valor de atraso entre as transições
  //// 1 segundo de microssegundos, dividido pela frequência, depois dividido ao meio 
  //// existem duas fases para cada ciclo
  long numCycles = frequency * length / 1000; // calcular o número de ciclos para o tempo adequado
  //// multiplicar frequência, que é realmente ciclos por segundo, pelo número de segundos a
  //// obter o número total de ciclos para produzir
  for (long i = 0; i < numCycles; i++) { 
    digitalWrite(targetPin, HIGH); 
    delayMicroseconds(delayValue); 
    digitalWrite(targetPin, LOW); 
    delayMicroseconds(delayValue); 
    
  }
  digitalWrite(13, LOW);
 
}
