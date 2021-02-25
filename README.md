# Prüfung: „Einführung in die Softwareentwicklung“

## Instruktionen zum Bauen des Projektes
1. Das Programm wird über (die von qtcreator erzeugte) qmake Datei <PacmanProject.pro> erstellt. Das Bauen funktioniert ebenfalls über die Kommandozeile 
   wie in der Aufgabenstellung beschrieben (qmake->make). 
2. Neben den qt Standardmodulen core und gui wird das qt multimedia Paket benötigt um Soundeffekte ins Spiel einzubeziehen
3. Die Standard Level-Karten für ein Spiel müssen relativ zum Projekt im Ordner ./txt_maps unter den Namen <level1.txt>, <level2.txt> und <level3.txt> abgelegt werden,
   Für zusätzliche Karten kann im Hauptmenü der Dateipfad über eine Texteingabe spezifiziert werden, wo diese liegen ist also egal.
4. Drei .wav Dateien für die Soundeffekte müssen in dem relativen Ordner ./wav_sounds abgelegt werden, die Dateien tragen den Namen <cembalo-1.wav> <cembalo-2.wav> <cembalo-3.wav>
   Beim Bauen des Projekts sollten diese Dateien dann in als .qrc Verzeichniss eingebunden werden (ich hoffe das habe ich so richtig verstanden..)
5. Mein Set Up beim Programmieren:
   1.  Qt version 5.14.2
   2.  QMake version 3.1
   3.  Compiler: Sowohl mit GCC x86 64bit als auch CLANG 11 x86 64bit getestet und voll funktionsfähig
       - gcc (Ubuntu 10.2.0-13ubuntu1) 10.2.0
       - Ubuntu clang version 11.0.0-2
   4.  Betriebssystem: Ubuntu 20.10
   5.  IDE: QT Creator 4.13.2
   
Wie ich das Projekt zum Test gebaut habe: Der Ordner PacmanProject wird mitsamt aller Unterdateien und Ordner heruntergeladen, die .pro Datei wird mit QtCreator als neues Projekt geöffnet und das automatische Builden und Starten des Programms funktioniert problemlos auf allen Rechnern die ich getestet habe.
   

## Notizen an die Korrigierenden

### Implementierte Features ###
- Basisversion: Steuerung von Pacman im Labyrinth, Pillen essen, einfache Geister mit randomisiertet Steuerung, Karten als .txt Files laden
- Verbesserte Geister Steuerung auf Basis von Distanz zu Pacman 
- Das Hauptmenü ist ein von QMainWindow abgeleitetes GUI namens mainMenu. Aus dem Hauptmenü aus können die drei vorgegebenen Level gestartet werden um zu spielen (die Pfade sind als statische
- Stringvariablen implementiert, die Karten müssen wie oben beschrieben im richtigen Ordner liegen). Zusätzlich kann man im Hauptmenü über die Custom Level Option einen Pfad zu alternativen 
- Levels angeben und diese im Anschluss direkt aus dem Hauptmenü heraus starten. Das Hauptmenü bietet außerdem über ein Drop Down Menü die Möglichkeit den Schwierigkeitsgrad in drei Stufen auszuwählen.
- Während einer aktiven Spielrunde kann das Spiel einmalig über das Drücken der x Taste pausiert und mit Sicherheitsabfrage abgebrochen werden.
- Soundeffekte sind zusätzlich implementiert (Level erfolgreich beendet, gestorben, Pille gegessen)

- 
- ...

## Quellen
- Die verwendeten .wav Files stammen aus dem Ubuntu apt Package <sound-icons> Version 0.1-5 Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
- Die im Rahmen der Veranstaltung bereitgestelle Konsolenbibliothek wird verwendet, an einer Stelle habe ich diese außerdem modifiziert (X_Taste als Usereingabe erkennen)
- 
- ...
