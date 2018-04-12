#include <PS2X_lib.h>

#define PS2_DAT    13 
#define PS2_CMD    9
#define PS2_SEL    3
#define PS2_CLK    A2
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false


PS2X ps2x;

int speed = 165 ;

int error = 0;
byte type = 0;
byte vibrate = 0;

int enA_PP = 2;
int in1_PP = 17;
int in2_PP = 16;


int enB_PL = 8;
int in3_PL = 14;
int in4_PL = 15;


int enA_SP = 6;
int in1_SP = 29;
int in2_SP = 23;


int enB_SL = 7;
int in3_SL = 27;
int in4_SL = 25;


int enA_ZP = 5;
int in1_ZP = 19;
int in2_ZP = 20;


int enB_ZL = 4;
int in3_ZL = 18;
int in4_ZL = 21;

void setup(){
  pinMode(36, OUTPUT);
  pinMode(38, OUTPUT);
  
Serial.begin(57600);
  
  delay(300);  //добавляем паузу, чтобы дать беспроводному ps2 модулю время для включения
   
  //ТУТ ИЗМЕНЕНИЯ ДЛЯ ВЕРСИИ v1.6!!! **************БУДЬТЕ ВНИМАТЕЛЬНЫ*************
  
  //установка пинов и настроек: GamePad(clock, command, attention, data, Pressures?, Rumble?) проверка ошибок
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  
  if(error == 0){
    
    // Сонтроллера найден, всё настроено удачно
    Serial.print("Found Controller, configured successful ");
    
    Serial.print("pressures = ");
  if (pressures)
    Serial.println("true ");
  else
    Serial.println("false");
  Serial.print("rumble = ");
  if (rumble)
    Serial.println("true)");
  else
    Serial.println("false");

    // Попробуйте все кнопки, при нажатии X контроллера будет вибрировать, чем дольше нажатие, тем быстрее вибрация
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    
    // Зажмите L1 или R1, будут отображаться показания аналоговых стикеров
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    
    // Дополнительно: Зайдите на www.billporter.info узнайте об обновлениях или сообщите об ошибке
    Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
  }  
  else if(error == 1)
    // Контроллер не найден, проверьте провода, посмотрите readme.txt для включения функции выявления ошибок. Посетите www.billporter.info и узнайте об известных проблемах
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
    // Контроллер найден, но не реагирует на команды. Посмотрите readme.txt для включения функции выявления ошибок. Посетите www.billporter.info и узнайте об известных проблемах
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if(error == 3)
    // Контроллер не принимает режим Pressures, возможно он им не поддерживается.
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  
//  Serial.print(ps2x.Analog(1), HEX);
  
  type = ps2x.readType(); 
  switch(type) {
    case 0:
      // Найден неизвестный тип контроллера
      Serial.print("Unknown Controller type found ");
      break;
    case 1:
      //Найден DualShock контроллер
      Serial.print("DualShock Controller found ");
      break;
    case 2:
      //Найден DualShock контроллер
      Serial.print("GuitarHero Controller found ");
      break;
  case 3:
      // Найден Беспроводной Sony DualShock контроллер
      Serial.print("Wireless Sony DualShock Controller found ");
      break;
   }
pinMode(enA_PP, OUTPUT);
pinMode(enB_PL, OUTPUT);

pinMode(in1_PP, OUTPUT);
pinMode(in2_PP, OUTPUT);

pinMode(in3_PL, OUTPUT);
pinMode(in4_PL, OUTPUT);

pinMode(enA_SP, OUTPUT);
pinMode(enB_SL, OUTPUT);

pinMode(in1_SP, OUTPUT);
pinMode(in2_SP, OUTPUT);

pinMode(in3_SL, OUTPUT);
pinMode(in4_SL, OUTPUT);

pinMode(enA_ZP, OUTPUT);
pinMode(enB_ZL, OUTPUT);

pinMode(in1_ZP, OUTPUT);
pinMode(in2_ZP, OUTPUT);

pinMode(in3_ZL, OUTPUT);
pinMode(in4_ZL, OUTPUT);

}
void move_backward()
{
digitalWrite(in1_PP, HIGH);
digitalWrite(in2_PP, LOW);

digitalWrite(in3_PL, HIGH);
digitalWrite(in4_PL, LOW);


analogWrite(enA_PP,speed );
analogWrite(enB_PL, speed);

digitalWrite(in1_SP, HIGH);
digitalWrite(in2_SP, LOW);

digitalWrite(in3_SL, HIGH);
digitalWrite(in4_SL, LOW);


analogWrite(enA_SP,speed );
analogWrite(enB_SL, speed);

digitalWrite(in1_ZP, LOW);
digitalWrite(in2_ZP, HIGH);

digitalWrite(in3_ZL, LOW);
digitalWrite(in4_ZL, HIGH);


analogWrite(enA_ZP,speed );
analogWrite(enB_ZL, speed);
}
void move_laser_on()
{
  digitalWrite(38, HIGH);
  digitalWrite(36, HIGH);
}
void move_laser_off()
{
  digitalWrite(38, LOW);
  digitalWrite(36, LOW);
}
void move_forward()
{
digitalWrite(in1_PP, LOW);
digitalWrite(in2_PP, HIGH);

digitalWrite(in3_PL, LOW);
digitalWrite(in4_PL, HIGH);


analogWrite(enA_PP,speed );
analogWrite(enB_PL, speed);

digitalWrite(in1_SP, LOW);
digitalWrite(in2_SP, HIGH);

digitalWrite(in3_SL, LOW);
digitalWrite(in4_SL, HIGH);


analogWrite(enA_SP,speed );
analogWrite(enB_SL, speed);

digitalWrite(in1_ZP, HIGH);
digitalWrite(in2_ZP, LOW);

digitalWrite(in3_ZL, HIGH);
digitalWrite(in4_ZL, LOW);


analogWrite(enA_ZP,speed );
analogWrite(enB_ZL, speed);
}

void move_right()
{
digitalWrite(in1_PP, HIGH);
digitalWrite(in2_PP, LOW);

digitalWrite(in3_PL, LOW);
digitalWrite(in4_PL, HIGH);


analogWrite(enA_PP,speed );
analogWrite(enB_PL, speed);

digitalWrite(in1_SP, HIGH);
digitalWrite(in2_SP, LOW);

digitalWrite(in3_SL, LOW);
digitalWrite(in4_SL, HIGH);


analogWrite(enA_SP,speed );
analogWrite(enB_SL, speed);

digitalWrite(in1_ZP, LOW);
digitalWrite(in2_ZP, HIGH);

digitalWrite(in3_ZL, HIGH);
digitalWrite(in4_ZL, LOW);


analogWrite(enA_ZP,speed );
analogWrite(enB_ZL, speed);

}

void move_left()
{
digitalWrite(in1_PP, LOW);
digitalWrite(in2_PP, HIGH);

digitalWrite(in3_PL, HIGH);
digitalWrite(in4_PL, LOW);


analogWrite(enA_PP,speed );
analogWrite(enB_PL, speed);

digitalWrite(in1_SP, LOW);
digitalWrite(in2_SP, HIGH);

digitalWrite(in3_SL, HIGH);
digitalWrite(in4_SL, LOW);


analogWrite(enA_SP,speed );
analogWrite(enB_SL, speed);

digitalWrite(in1_ZP, HIGH);
digitalWrite(in2_ZP, LOW);

digitalWrite(in3_ZL, LOW);
digitalWrite(in4_ZL, HIGH);


analogWrite(enA_ZP,speed );
analogWrite(enB_ZL, speed);
}

void move_stop()
{
digitalWrite(in1_PP, LOW);
digitalWrite(in2_PP, LOW);

digitalWrite(in3_PL, LOW);
digitalWrite(in4_PL, LOW);


analogWrite(enA_PP,speed );
analogWrite(enB_PL, speed);

digitalWrite(in1_SP, LOW);
digitalWrite(in2_SP, LOW);

digitalWrite(in3_SL, LOW);
digitalWrite(in4_SL, LOW);


analogWrite(enA_SP,speed );
analogWrite(enB_SL, speed);

digitalWrite(in1_ZP, LOW);
digitalWrite(in2_ZP, LOW);

digitalWrite(in3_ZL, LOW);
digitalWrite(in4_ZL, LOW);


analogWrite(enA_ZP,speed );
analogWrite(enB_ZL, speed);
}

void loop() {

  if(error == 1) //Цикл «loop» пропускается если джойстик не найден
    return; 
  
  if(type == 2){ //Guitar Hero контроллер
    ps2x.read_gamepad();          //считывание данных с контроллера 
   
    if(ps2x.ButtonPressed(GREEN_FRET))
      Serial.println("Green Fret Pressed");
    if(ps2x.ButtonPressed(RED_FRET))
      Serial.println("Red Fret Pressed");
    if(ps2x.ButtonPressed(YELLOW_FRET))
      Serial.println("Yellow Fret Pressed");
    if(ps2x.ButtonPressed(BLUE_FRET))
      Serial.println("Blue Fret Pressed");
    if(ps2x.ButtonPressed(ORANGE_FRET))
      Serial.println("Orange Fret Pressed"); 

    if(ps2x.ButtonPressed(STAR_POWER))
      Serial.println("Star Power Command");
    
    if(ps2x.Button(UP_STRUM))          //will be TRUE as long as button is pressed
      Serial.println("Up Strum");
    if(ps2x.Button(DOWN_STRUM))
      Serial.println("DOWN Strum");
 
    if(ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");
    
    if(ps2x.Button(ORANGE_FRET)) {     // print stick value IF TRUE
      Serial.print("Wammy Bar Position:");
      Serial.println(ps2x.Analog(WHAMMY_BAR), DEC); 
    } 
  }
  else { //DualShock контроллер
    ps2x.read_gamepad(false, vibrate); //считывание данных с джойстика и установка скорости вибрации
    
    if(ps2x.Button(PSB_START))         //будет TRUE пока кнопка нажата
      Serial.println("Start is being held"); // Start нажат
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held"); // Select нажат

    if(ps2x.Button(PSB_TRIANGLE)) {      //будет TRUE пока кнопка нажата
      Serial.print("Up held this hard: "); // ВВЕРХ нажато, сила нажатия:
      Serial.println(ps2x.Analog(PSAB_TRIANGLE), DEC);
      move_forward();
    }
    else {
      move_stop();
    }
    if(ps2x.Button(PSB_CROSS)) {      //будет TRUE пока кнопка нажата
      Serial.print("Up held this hard: "); // ВВЕРХ нажато, сила нажатия:
      Serial.println(ps2x.Analog(PSAB_CROSS), DEC);
      move_backward();
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.print("Right held this hard: "); // ВПРАВО нажато, сила нажатия:
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
      move_right();
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.print("LEFT held this hard: "); // ВЛЕВО нажато, сила нажатия:
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
      move_left();
    }
  if(ps2x.Button(PSB_CIRCLE)){
      Serial.print("LASER ON "); // ВНИЗ нажато, сила нажатия:
      Serial.println(ps2x.Analog(PSAB_CIRCLE), DEC);
      move_laser_on();
    }     
    else {
      move_laser_off();
    }

    vibrate = ps2x.Analog(PSAB_CROSS);  //Скорость вибрации устанавливаеться в зависимости от силы нажатия кнопки (X)
    if (ps2x.NewButtonState()) {        //будет TRUE если какая то кнопка изменила свой статус (Вкл. на Выкл. или Выкл. на Вкл.)
      if(ps2x.Button(PSB_L3))
        Serial.println("L3 pressed"); // L3 нажата
      if(ps2x.Button(PSB_R3))
        Serial.println("R3 pressed"); // R3 нажата
      if(ps2x.Button(PSB_L2))
        Serial.println("L2 pressed"); // L2 нажата
      if(ps2x.Button(PSB_R2))
        Serial.println("R2 pressed"); // R2 нажата
      if(ps2x.Button(PSB_TRIANGLE)) 
        Serial.println("Triangle pressed"); // Треугольник нажат 
    }

    else {
    }
    if(ps2x.NewButtonState(PSB_CROSS)) //будет TRUE если кнопка в НАЖАТОМ СОСТОЯНИИ нажата ИЛИ отпущена
      Serial.println("X just changed"); // X изменил статус
    if(ps2x.ButtonReleased(PSB_SQUARE)) //будет TRUE если кнопка в ОТПУЩЕНОМ состоянии
      Serial.println("Square just released"); // Квадрат отпущен

    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { // Отображает показания стикеров
      Serial.print("Stick Values:");
      Serial.print(ps2x.Analog(PSS_LY), DEC); // Ось Y Левого стикера
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_LX), DEC); // Ось X Левого стикера
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_RY), DEC); // Ось Y Правого стикера
      Serial.print(",");
      Serial.println(ps2x.Analog(PSS_RX), DEC); // Ось X Правого стикера
    }     
  }
  delay(50);  
}
