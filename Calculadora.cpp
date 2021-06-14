//Trabalho Calculadora V1.3

#include <Keypad.h> // A biblioteca para o teclado matricial 4x4
#include <LiquidCrystal_I2C.h> // biblioteca para o display + i2c
LiquidCrystal_I2C lcd(0x3F, 16, 2); // inclui o display


char Key;
String X, Y;
byte z = 0;
char a;
long dado1, dado2, rpt1;
double dado3, dado4, rpt2;
const byte ROWS = 4; // A quantidade de linhas do teclado
const byte COLS = 4; // A quantidade de colunas do teclado
char keys[ROWS][COLS] = { // Define linhas e colunas
  // define os digitos do teclado
  {'1', '2', '3', 'A'},
  {'4', '5', '6', '+'},
  {'7', '8', '9', '-'},
  {'*', '0', '=', '/'}
};
bool SmartDoor = true;
// os pinos para conectar no teclado
byte rowPins[ROWS] = {10, 9, 8, 7};
byte colPins[COLS] = {3, 4, 5, 6};
Keypad myKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); // obtém os dados do teclado


void setup()
{
  lcd.init(); // Inicia o display
  lcd.backlight(); // liga a luz de fundo do lcd
  lcd.setCursor(2, 0); // define o cursor no lcd
  lcd.print("Calculadora"); // imprime o texto
  lcd.setCursor(1, 1); // define o cursor no lcd
  lcd.print("Andressa-611M2"); // imprime o texto
  delay(2500); // Espera
  lcd.clear();
  lcd.setCursor(1, 0); // define o cursor no lcd
  lcd.print("* = x"); // imprime o texto
  lcd.setCursor(10, 0); // define o cursor no lcd
  lcd.print("B = +"); // imprime o texto
  lcd.setCursor(1, 1); // define o cursor no lcd
  lcd.print("C = -"); // imprime o texto
  lcd.setCursor(10, 1); // define o cursor no lcd
  lcd.print("D = /"); // imprime o texto
  delay(4000);
  lcd.clear();
  lcd.setCursor(4, 0); // define o cursor no lcd
  lcd.print("A = del"); // imprime o texto
  lcd.setCursor(4, 1); // define o cursor no lcd
  lcd.print("# = igual"); // imprime o texto
  delay(2000); 
  lcd.clear();


}

void loop()
{

  char key = myKeypad.getKey();
  if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9') {

    if (z == 0) {
      lcd.print(key);
      X += key;
      dado1 = X.toInt();
    }

    else if (z == 1) {
      lcd.print(key);
      Y += key;
      dado2 = Y.toInt();
    }

  }

  if (key == 'A') {

    Y = "";
    X = "";
    dado1 = 0;
    dado2 = 0;
    dado3 = 0;
    dado4 = 0;
    z = 0;
    rpt1 = 0;
    rpt2 = 0;
    lcd.clear();
  }
  else if ((key == '=') && (a == '+'))
  {

    z++;
    lcd.setCursor(0, 1);
    lcd.print("=");
    rpt1 = (dado1 + dado2);
    lcd.setCursor(1, 1);
    lcd.print(rpt1);
  }

  else if (key == '=' && a == '-') {
    z++;
    lcd.setCursor(0, 1);
    lcd.print("=");
    rpt1 = dado1 - dado2;
    lcd.setCursor(1, 1);
    lcd.print(rpt1);

  }
  else if (key == '=' && a == '*') {
    z++;
    lcd.setCursor(0, 1);
    lcd.print("=");
    rpt1 = dado1 * dado2;
    lcd.setCursor(1, 1);
    lcd.print(rpt1);
  }
  else if (key == '=' && a == '/') {
    z++;
    lcd.setCursor(0, 1);
    lcd.print("=");
    dado3 = dado1;
    dado4 = dado2;
    lcd.print("ANS=");
    rpt2 = (dado3 / dado4);
    lcd.setCursor(1, 1);
    lcd.print(rpt2);
  }


  else if ((key == '+' || key == '-' || key == '*' || key == '/') && (z == 0)) {
    z++;
    a = key;
    lcd.print(a);
  }
}

