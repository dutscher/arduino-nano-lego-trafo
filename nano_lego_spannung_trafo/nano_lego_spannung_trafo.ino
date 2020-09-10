int wert1;
float wert2;

// https://funduino.de/nr-11-spannung-messen 

void setup() {
  Serial.begin(9600); //serielle Verbindung starten
}

void loop() {
  float temp;
  wert1=analogRead(1); //Spannungswert am analogen Eingang 1 auslesen
  temp=wert1/4.092; //Wert mathematisch umwandeln um den Spannungswert in Volt zu erhalten
  wert1=(int)temp;
  wert2=((wert1%100)/10.0);
  Serial.println(String(wert2) + " --- " + String(wert1)); //Endgültigen Spannungswert im seriellen Monitor anzeigen
  delay(1000); //Eine Sekunde warten
}
