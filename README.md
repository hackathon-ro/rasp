rasp  Remote Aquisition Sensor Platform on Raspberry Pi by Virgil Capel
Categoria Best Hardware


RASP este un sistem autonom de achizitie de date avand drept componenta principala Raspberry Pi care centralizeaza datele primite de la senzori ( GPS, Contor Geiger, Anemometru, senzor UV, etc...)
Raspberry Pi este conectat cu ajutorul unui modem 3G la internet si comunica cu un server dedicat ce preia datele si le stocheaza intr-o baza de date MySQL. Evolutia parametrilor in timp real corelarea pe harta, precum si istoricul  pot fi vizualizate online la adresa:  hackathon.capel.ro 

Autonomia este asigurata de alimentarea cu ajutorul panourilor fotovoltaice.
Pentru achizitia low level de la diversi senzori am folosit microcontrollere Microchip seria 16F pentru a putea asigura interfata cu Raspberry Pi.
Un pas inainte ar fi unificarea protocolului de comunicatie senzori-Raspberry-server ( de ex Modbus)
 
====
