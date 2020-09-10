// https://funduino.de/nr-41-stromstaerkesensor-arduino#:~:text=In%20diesem%20Beispiel%20soll%20die,512.
int Sensor = A0; // Der Stromstärkesensor wird am Pin A0 (Analog "0") angeschlossen.
int VpA = 185; // Millivolt pro Ampere (100 für 20A Modul und 66 für 30A Modul)
int trafo = 0;
int Nullpunkt = 2500; // Spannung in mV bei dem keine Stromstärke vorhanden ist
double SensorSpannung = 0;
double Ampere = 0;

// 477 - 501 == links
// 501 - 502 == null
// 502 - 525 == rechts


void setup(){ 
  Serial.begin(9600);
  Serial.println("SETUP DONE");
}

void loop(){
  trafo = analogRead(Sensor);

  if (trafo < 501) {
    Serial.print("links lank"); 
  } else if (trafo >= 501 && trafo <= 504) {
    Serial.print("stop"); 
  } else if (trafo > 504) {
    Serial.print("rechts rum"); 
  }

  Serial.println(" - " + String(trafo)); 
  
  delay(1000); 
}
