#include <LiquidCrystal_I2C.h> //lcd erknan ve ı2c modülü için kütüphane ekliyoruz.
#include <virtuabotixRTC.h>    //RTC kütüphanemizi ekliyoruz.   
#include <Keypad.h>//keypad kütüphanesi.

LiquidCrystal_I2C lcd(0x27, 16 , 2);                   

int CLK_PIN = 6;                                        //6. pini clock pini olarak tanımladık
int DAT_PIN = 7;                                        //7. pini data pini olarak tanımladık
int RST_PIN = 8;                                        //8. pini reset pini olarak tanımladık.
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);        // Kütüphanemizi pinlere atıyoruz.4

const byte satirsayisi=4;
const byte sutunsayisi=4;
char tuslar[satirsayisi][sutunsayisi]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};// satır ve sutunların karakterlerini char olarak içinde tutan bir dizi tanımladım.
byte satir_pinleri[satirsayisi]={13,12,11,10};
byte sutun_pinleri[sutunsayisi]={5,4,3,2};
Keypad tustakimi=Keypad(makeKeymap(tuslar),satir_pinleri,sutun_pinleri,satirsayisi,sutunsayisi);//Keypad sınıfından tustakimi adlı bir nesne oluşturdum ve içinde makeKeymap adlı fonksiyonu kullanarak tusları haritaladım,ve satır sutun pin ve sayılarını girdim.

int i1,i2,i3,i4;

char c1,c2,c3,c4;

char keypressed,keypressedx;


int A_hour=NULL;

int A_minute=NULL;

int AlarmIsActive=NULL;


int buzzer = 13;






void setup() {

  Serial.begin(9600);

  lcd.begin (); 

  

  lcd.home ();

                                                   

}


void loop() {

   

  while(keypressed == NO_KEY){ 

                              

  keypressed = tustakimi.getKey();

  lcd.clear(); 

  myRTC.updateTime();


  if(myRTC.hours==A_hour && myRTC.minutes==A_minute && AlarmIsActive==1 && myRTC.seconds >= 0 && myRTC.seconds <= 2){

    while(keypressedx == NO_KEY){

    tone(buzzer, 1000); 

    delay(100);

    tone(buzzer, 2000);

    delay(100);

    lcd.clear();

    lcd.print("  AFIYET OLSUN!!    "); //Alarm çaldığında ekrana yazan yazı.(i,ü,ö,ğ,ş,küçük j,ç harflerini ve benzeri şeyleri kullanmayın.)

    keypressedx = tustakimi.getKey();

    }

  }

  keypressedx = NO_KEY;

  noTone(buzzer);

  lcd.setCursor(0,0);

  lcd.print(myRTC.dayofmonth);

  lcd.print("/");

  lcd.print(myRTC.month);

  lcd.print("/");

  lcd.print(myRTC.year);

  lcd.setCursor(0,1);

  lcd.print(myRTC.hours);

  lcd.print(":");

  lcd.print(myRTC.minutes);

  lcd.print(":");

  lcd.print(myRTC.seconds);

  delay(100);

  }

 


         if (keypressed == 'C') //Ayarlar menüsü tuşu. 

             {

              lcd.clear();

              lcd.print("     Ayarlar");

             delay(1000);

              lcd.clear();

              lcd.print("Yil Ayari");






              

             char keypressed2 = tustakimi.waitForKey();  

                    if (keypressed2 != NO_KEY && keypressed2 !='*' && keypressed2 !='#' && keypressed2 !='A' && keypressed2 !='B' && keypressed2 !='C' && keypressed2 !='D' )

                      {

                       c1 = keypressed2;

                       lcd.setCursor(0, 1);

                       lcd.print(c1);

                       }

                 char      keypressed3 = tustakimi.waitForKey();

                    if (keypressed3 != NO_KEY && keypressed3 !='*' && keypressed3 !='#' && keypressed3 !='A' && keypressed3 !='B' && keypressed3 !='C' && keypressed3 !='D' )

                      {

                       c2 = keypressed3;

                       lcd.setCursor(1, 1);

                       lcd.print(c2);

                       }

                   char  keypressed4 = tustakimi.waitForKey();

                   if (keypressed4 != NO_KEY && keypressed4 !='*' && keypressed4 !='#' && keypressed4 !='A' && keypressed4 !='B' && keypressed4 !='C' && keypressed4 !='D' )

                      {

                       c3 = keypressed4;

                       lcd.setCursor(2, 1);

                       lcd.print(c3);

                       }

                   char   keypressed5 = tustakimi.waitForKey();

                   if (keypressed5 != NO_KEY && keypressed5 !='*' && keypressed5 !='#' && keypressed5 !='A' && keypressed5 !='B' && keypressed5 !='C' && keypressed5 !='D' )

                      {

                       c4 = keypressed5;

                       lcd.setCursor(3, 1);

                       lcd.print(c4);

                       }


                     i1=(c1-48)*1000;        

                     i2=(c2-48)*100;

                     i3=(c3-48)*10;

                     i4=c4-48;

                     int N_year=i1+i2+i3+i4;

                   delay(500);

                     lcd.clear();

                     lcd.print("Ay Ayari");


////////////////////////////////////////////////////////////////

                     char keypressed6 =tustakimi.waitForKey();  

                    if (keypressed6 != NO_KEY && keypressed6 !='*' && keypressed6 !='#' && keypressed6 !='A' && keypressed6 !='B' && keypressed6 !='C' && keypressed6 !='D' )

                      {

                       c1 = keypressed6;

                       lcd.setCursor(0, 1);

                       lcd.print(c1);

                       }

                    char   keypressed7 = tustakimi.waitForKey();

                    if (keypressed7 != NO_KEY && keypressed7 !='*' && keypressed7 !='#' && keypressed7 !='A' && keypressed7 !='B' && keypressed7 !='C' && keypressed7 !='D' )

                      {

                       c2 = keypressed7;

                       lcd.setCursor(1, 1);

                       lcd.print(c2);

                       }



                     i1=(c1-48)*10;

                     i2=c2-48;

                    int N_month=i1+i2;

                     delay(500);

                     


                     lcd.clear();

                     lcd.print("Gun Ayari");

                     

 ////////////////////////////////////////////////////////////////                    

                      char keypressed8 = tustakimi.waitForKey();  

                    if (keypressed8 != NO_KEY && keypressed8 !='*' && keypressed8 !='#' && keypressed8 !='A' && keypressed8 !='B' && keypressed8 !='C' && keypressed8 !='D' )

                      {

                        c1 = keypressed8;

                       lcd.setCursor(0, 1);

                       lcd.print(c1);

                       }

                      char keypressed9 = tustakimi.waitForKey();

                    if (keypressed9 != NO_KEY && keypressed9 !='*' && keypressed9 !='#' && keypressed9 !='A' && keypressed9 !='B' && keypressed9 !='C' && keypressed9 !='D' )

                      {

                        c2 = keypressed9;

                       lcd.setCursor(1, 1);

                       lcd.print(c2);

                       }



                     i1=(c1-48)*10;

                     i2=c2-48;

                    int N_day=i1+i2;

                    delay(500);

                     lcd.clear();

                     lcd.print("Saat Ayari");

////////////////////////////////////////////////////////////////////////////////////:                     

                     char keypressed10 = tustakimi.waitForKey();  

                    if (keypressed10 != NO_KEY && keypressed10 !='*' && keypressed10 !='#' && keypressed10 !='A' && keypressed10 !='B' && keypressed10 !='C' && keypressed10 !='D' )

                      {

                       c1 = keypressed10;

                       lcd.setCursor(0, 1);

                       lcd.print(c1);

                       }

                    char   keypressed11 = tustakimi.waitForKey();

                    if (keypressed11 != NO_KEY && keypressed11 !='*' && keypressed11 !='#' && keypressed11 !='A' && keypressed11 !='B' && keypressed11 !='C' && keypressed11 !='D' )

                      {

                        c2 = keypressed11;

                       lcd.setCursor(1, 1);

                       lcd.print(c2);

                       }



                     i1=(c1-48)*10;

                     i2=c2-48;

                    int N_hour=i1+i2;

                    delay(500);

                     lcd.clear();

                     lcd.print("Dakika Ayari");

////////////////////////////////////////////////////////////////////////////////////:

                    char keypressed12 = tustakimi.waitForKey();  

                    if (keypressed12 != NO_KEY && keypressed12 !='*' && keypressed12 !='#' && keypressed12 !='A' && keypressed12 !='B' && keypressed12 !='C' && keypressed12 !='D' )

                      {

                        c1 = keypressed12;

                       lcd.setCursor(0, 1);

                       lcd.print(c1);

                       }

                   char    keypressed13 = tustakimi.waitForKey();

                    if (keypressed13 != NO_KEY && keypressed13 !='*' && keypressed13 !='#' && keypressed13 !='A' && keypressed13 !='B' && keypressed13 !='C' && keypressed13 !='D' )

                      {

                        c2 = keypressed13;

                       lcd.setCursor(1, 1);

                       lcd.print(c2);

                       }



                     i1=(c1-48)*10;

                     i2=c2-48;

                    int N_minutes=i1+i2;

                    delay(500);

                     lcd.clear();


                    myRTC.setDS1302Time(22, N_minutes, N_hour, 1, N_day, N_month, N_year);


                    

                    keypressed=NO_KEY; 

              }

/////////////////////////////////////////Alarm Ayarı/////////////////////////////////

              

             if (keypressed == 'A'){

              lcd.clear();

              lcd.print("  Alarm Ayari  ");

              delay(1000);

              lcd.clear();

              lcd.print("Alarm Saati");

               

               char keypressed14 = tustakimi.waitForKey(); 

                    if (keypressed14 != NO_KEY && keypressed14 !='*' && keypressed14 !='#' && keypressed14 !='A' && keypressed14 !='B' && keypressed14 !='C' && keypressed14 !='D' )

                      {

                       c1 = keypressed14;

                       lcd.setCursor(0, 1);

                       lcd.print(c1);

                       }

                    char   keypressed15 = tustakimi.waitForKey();

                    if (keypressed15 != NO_KEY && keypressed15 !='*' && keypressed15 !='#' && keypressed15 !='A' && keypressed15 !='B' && keypressed15 !='C' && keypressed15 !='D' )

                      {

                        c2 = keypressed15;

                       lcd.setCursor(1, 1);

                       lcd.print(c2);

                       }



                     i1=(c1-48)*10;

                     i2=c2-48;

                     A_hour=i1+i2;

                    delay(500);

                     lcd.clear();

                     lcd.print("Alarm Dakikasi");

                      char keypressed16 = tustakimi.waitForKey(); 

                    if (keypressed16 != NO_KEY && keypressed16 !='*' && keypressed16 !='#' && keypressed16 !='A' && keypressed16 !='B' && keypressed16 !='C' && keypressed16 !='D' )

                      {

                       c1 = keypressed16;

                       lcd.setCursor(0, 1);

                       lcd.print(c1);

                       }

                    char   keypressed17 = tustakimi.waitForKey();

                    if (keypressed17 != NO_KEY && keypressed17 !='*' && keypressed17 !='#' && keypressed17 !='A' && keypressed17 !='B' && keypressed17 !='C' && keypressed17 !='D' )

                      {

                        c2 = keypressed17;

                       lcd.setCursor(1, 1);

                       lcd.print(c2);

                       }



                     i1=(c1-48)*10;

                     i2=c2-48;

                     A_minute=i1+i2;

                    delay(500);

                     lcd.clear();

                      AlarmIsActive=1;

                      keypressed=NO_KEY;

             }

             if (keypressed == 'B')

             {

              lcd.clear();

              lcd.print("Alarm yok");

              AlarmIsActive=0;

              keypressed=NO_KEY;

              delay(500);

             }

             else {

              myRTC.updateTime();

              keypressed=NO_KEY;

             }

             


}
