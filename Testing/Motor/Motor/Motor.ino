#include <Servo.h>
Servo motore1;  // Viene creato l'oggetto per il controllo del motore 1
Servo motore2;  // Viene creato l'oggetto per il controllo del motore 2
typedef enum Dir { front, back ,left, right, v_stop };
void setup() {
  motore1.attach(4);  // left
  motore2.attach(5);  // right wheel  
}
void drive_verichel (char direct, char angle_rad , char distance_cm ) 
{
  switch ( direct) 
  {
    case front : 
        motore1.writeMicroseconds(1300); //left foreward
        motore2.writeMicroseconds(1283);  //right backward 
        delay(1800*distance_cm); // distance
        stop_function();
        break ;
    case back : 
        motore1.writeMicroseconds(1300); //left turn around 
        motore2.writeMicroseconds(1800);  //right backward 
        delay(1800*angle_rad); // distance
        motore1.writeMicroseconds(1300); // left foreward
        motore2.writeMicroseconds(1283);  //right backward 
        delay(1800*distance_cm); // distance
        stop_function();
        break ;
    case left : 
        motore1.writeMicroseconds(1300); //left foreward
        motore2.writeMicroseconds(1800);  //right backward 
        delay(1800*angle_rad); // angle
        stop_function();
        break ;
    case right : 
        motore1.writeMicroseconds(1800); //left foreward
        motore2.writeMicroseconds(1300); //right backward 
        delay(1800*angle_rad); // angle
        stop_function();
        break ;
    case v_stop: 
       stop_function();
        break ;
  }
}
void stop_function()
{
        motore1.writeMicroseconds(1500); // left foreward
        motore2.writeMicroseconds(1500);  //right backward 
}
void loop() {
  drive_verichel (1,  2,2);
  while (1);
}


