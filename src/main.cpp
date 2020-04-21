#include <Arduino.h>

//#include <SPI.h>
#include </home/peter/Nextcloud/documents/CAD_und_Co/Projekte/ContourScan/Arduino/ContourScan/lib/SD-master/src/SD.h>  // In diesem Sketch verwenden wir die <SD.h> library

File Textdatei;          // An dieser Stelle wird die Variable "Textdatei" als File (dts. Datei) deklariert.

void setup() {

  //start serial connection
  Serial.begin(9600);

  Serial.println("Initialisiere SD-Karte");
  if (!SD.begin(4)) {                                     // Wenn die SD-Karte nicht (!SD.begin) gefunden werden kann, ...
    Serial.println("Initialisierung fehlgeschlagen!");    // ... soll eine Fehlermeldung ausgegeben werden. ....
    return;
  }
  Serial.println("Initialisierung abgeschlossen");        // ... Ansonsten soll die Meldung "Initialisierung abgeschlossen." ausgegeben werden.


  Textdatei = SD.open("messwerte.txt", FILE_WRITE);            // An dieser Stelle wird die Textdatei erstellt. Unsere Textdatei soll "test" heißen und im Format ".txt" (Text) erstellt werden.


  if (Textdatei)
{                                        // Wenn die Textdatei ("test.txt") gefunden wurde....

    Serial.println("Schreibe in Textdatei...");           // ... soll eine Meldung im seriellen Monitor erscheinen...
    Textdatei.println("X");
    Textdatei.print(";");
    Textdatei.print("Y");
    for (int i = 0; i < 10; i++)
    {
      Textdatei.println(i);
      Textdatei.print(";");
      Textdatei.print((i*i));
    }

    Textdatei.close();                                    // Anschließend wird die Textdatei wieder geschlossen...
    Serial.println("Abgeschlossen.");                     // ... und eine erneute Meldung im seriellen Monitor ausgegeben.
    Serial.println();
}
  else
{                                                        // Wenn !keine! Textdatei gefunden werden kann ...
    Serial.println("Textdatei konnte nicht ausgelesen werden");   // ... erscheint eine Fehlermeldung im seriellen Monitor.
}

                                                         // NUN WIRD DIE TEXTDATEI AUSGELESEN


  Textdatei = SD.open("messwerte.txt");                            // Die Textdatei auf der SD-Karte wird wieder geoeffnet...

  if (Textdatei)

{
  Serial.println("Checking contents of messwerte.txt: ");                              // ... und der Name der Datei wird ausgegeben.

    while (Textdatei.available())                             // Anschließend wird die Datei so lange ausgelesen (while)...
    {
      Serial.write(Textdatei.read());                         // ... bis keine Daten mehr gefunden werden können.
    }

  Textdatei.close();                                        // Im Anschluss wird die Textdatei wieder geschlossen.
}

   else                                                             // Sollte keine Textdatei (also test.txt) gefunden werden können...

    {
    Serial.println("Textdatei konnte nicht geoeffnet werden");      // ... erscheint eine Fehlermeldung im seriellen Monitor.
    }

}

void loop()    // Der Loop bleibt leer.
{
}
