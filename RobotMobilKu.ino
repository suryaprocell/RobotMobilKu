#include <ultrasonic.h>

ultrasonic ultrasoniku(7,8);
double jarak, jarak_kanan, jarak_kiri;

int out1 = 5;
int out2 = 6;
int out3 = 9;
int out4 = 10;

void setup()
{
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  maju();
}

void loop()
{
  jarak = ultrasoniku.baca(CM);
  
  if(jarak<=25)
  {
    berhenti();
    
    mundur();
    delay(500);
    
    berhenti();
    
    putar_kanan();
    delay(500);
    
    berhenti();
    jarak_kanan = ultrasoniku.baca(CM);
    
    putar_kiri();
    delay(1000);
    
    berhenti();
    jarak_kiri = ultrasoniku.baca(CM);
    
    if(jarak_kiri>jarak_kanan)
    {
      maju();
    }
    else
    {
      putar_kanan();
      delay(1000);
      maju();
    }
  }
  else
  {
    maju();
  }

}

void maju()
{
  ban_kiri_maju();
  ban_kanan_maju();
}

void mundur()
{
  ban_kiri_mundur();
  ban_kanan_mundur();
}

void berhenti()
{
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);
  digitalWrite(out4, LOW);
  delay(500);
}

void putar_kanan()
{
  ban_kiri_maju();
  ban_kanan_mundur();
}

void putar_kiri()
{
  ban_kiri_mundur();
  ban_kanan_maju();
}

void ban_kiri_maju()
{
  digitalWrite(out1, HIGH);
  digitalWrite(out2, LOW);
}

void ban_kiri_mundur()
{
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);
}

void ban_kanan_maju()
{
  digitalWrite(out3, HIGH);
  digitalWrite(out4, LOW);
}

void ban_kanan_mundur()
{
  digitalWrite(out3, LOW);
  digitalWrite(out4, HIGH);
}


