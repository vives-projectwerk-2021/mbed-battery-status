# Mbed-battery-status

Klasse die de huidige spanning van de batterij spanning gaat meten. Het geef een float terug in volts.

Om de waarde correct in te lezen maken we gebruik van de ingebouwde calibratie waarde van de microcontroller. Deze waarde staat altijd op dezelfde plek in het geheugen. Dit zie je hier onder:

![img1](img/table.png)


Nu moeten we gewoon de formules toepassen die staan in de reference manual:

![img2](img/formule1.png)

- **V<sub>REF+_Charac</sub>**: Waarde van V<sub>REF+</sub> tijdens calibratie (altijd 3.0v zie tabel 9).
- **V<sub>REFIN_CAL</sub>**: De calibratie waarde in het geheugen.
- **V<sub>REFIN_DATA</sub>**: ADC waarde van V<sub>REF</sub>.


Als Vref+ berekent is kunnen we de spanning van de batterij berekenen:

![img3](img/formule2.png)

- **FULL_SCALE**: Max waarde van de ADC (212 - 1 = 4095).
- **ADC_DATA**: ADC waarde van te meten channel (voor ons V<sub>BAT</dub>).
