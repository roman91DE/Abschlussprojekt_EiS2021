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
   1.  Betriebssystem: Ubuntu 20.10
   2.  IDE: QT Creator 4.13.2

## Notizen an die Korrigierenden

### Implementierte Features ###
- Grund
- ...

## Quellen
- Die verwendeten .wav Files stammen aus dem Ubuntu apt Package <sound-icons> Version 0.1-5 Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
- Die im Rahmen der Veranstaltung bereitgestelle Konsolenbibliothek wird verwendet, an einer Stelle habe ich diese außerdem modifiziert (X_Taste als Usereingabe erkennen)
- 
- ...
