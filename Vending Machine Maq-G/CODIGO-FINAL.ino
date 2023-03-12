
#include <LiquidCrystal.h>
const int rs = A0, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
long duration;
#define motor_1 9
#define motor_2 10
#define motor_3 11
#define motor_4 12
char opcion;
int motor;
int i, j = 0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(38400);
  Serial3.begin(38400);
  //Pines driver 1
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
 // analogWrite(3, 200);
}

void loop() {
  digitalWrite(2, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("  Bienvenido ");
  lcd.setCursor(0, 1);
  lcd.print("Vincule su cel");

  if (Serial3.available() > 0) {
    opcion = Serial3.read();
    lcd.clear();

    if (opcion == '1') {
      motor = motor_1;
      lcd.print("  Producto 1 ");
      Serial.println("Porducto 1");
    }
    else if (opcion == '2') {
      motor = motor_2;
      lcd.print("  Producto 2 ");
      Serial.println("Porducto 2");
    }
    else if (opcion == '3') {
      motor = motor_3;
      lcd.print("  Producto 3 ");
      Serial.println("Porducto 3");
    }
    else if (opcion == '4') {
      motor = motor_4;
      lcd.print("  Producto 4 ");
      Serial.println("Porducto 4");
    }

    lcd.setCursor(0, 0);
    lcd.setCursor(0, 1);
    lcd.print("  Seleccionado ");
    delay(3000);
    for(i=0; i<5; i++){
      digitalWrite(motor, HIGH);
      delay(100); 
      digitalWrite(motor, LOW);
      delay(200);
    }
   // digitalWrite(motor, HIGH);
    //delay(1000);
    //digitalWrite(motor, LOW);
    //delay(2000);

    delay(5000);
    Serial.print(5);
    Serial3.print(5);
    lcd.setCursor(0, 0);
    lcd.print(" Muchas Gracias ");
    lcd.setCursor(0, 1);
    lcd.print(" Vuelva pronto ");
    delay(5000);
    lcd.clear();
    delay(1000);

    opcion = 0;
    j = 0;
  }
}
