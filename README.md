# llp-device

llp-device es un ejemplo de implementación de una estructura generica para representar dispostivos genericos implementados en Arduino. La idea principal es que los dispositivos sean facil de modificar de tal forma que permitan arquitecturas escalabes y faciles de acoplar.

### Conceptos
- POO
- Interfaces
- Herencia
- Estructuras de Datos
- Protocolos de Comunicación

## Clase Device

La idea de esta clase generica es que funcione como interfaz para representar las caracteristicas principales de cualquier dispositivo, ya sea un dispositivo de input, output o transformación.
### Modelo

Para modelar uno de nuestros dispositivos, lo primero que debemos definir, es cuales son las caracteristicas basicas que este debe cumplir.

- Pertenecer a una de las categorias (Input, Output o Transformer)
- Poder interpretar un mensaje del tipo [LLP](https://github.com/Azrrael-exe/ard-llp)
- Tener un ID unico, que le permita identificar los mensajes propios

En este orden de ideas un dispositivo generico deberia estar en capacidad de recibir un objeto del tipo `DataPack` ejecutar su contenido y responder con un mensaje en el mismo formato que pueda ser recibido por un dispositvo siguiente en la linea del mensaje, de tal forma que los dispositivos puedan ser conectados en cascada o en estrella segun sea el caso. (La conexión entre los dispositivos es unidireccionál en la misma linea)

Estas Caracteristicas basicas de las Clase device funcionan como un **Core** partir de las cual se desprenden las siguientes funcionalidades.

### UML

### Sintaxis de Comandos y Mensajes
Para poder operar con una estructura de mensajeria, es necesario definir un protocolo que permita identificar el tipo de mensaje (Esta tabla puede crecer en función de las necesidades)

| Command   | HEX  | Description |
|-----------|------|-------------|
| status    | `0XC0` |             |
| message   | `0XAA` |             |
| report    | `0xAF` |             |
| emergency | `0xD0` |             |
| error     | `0xD1` |             |
## Inputs

Son dispositivos que generan mensajes dentro de la red, tecnicamente lo que hacen es reciben informaciòn externa y a partir de esta genera un mensaje. Este mensaje puede ser representado ya sea por la lectura de un sensor o provenir directamente de la interfaz con el usuario. Este tipo de dispositvo generan mensaje dentro de la linea.

## Transformers

Son dispostivios que reciben un mensaje, transforman una o mas de las variables contenidas y las descarga dentro de la linea del mensaje.

## Outputs

Son dispositivos que toman un mensaje y pueden emitirlo externamente usando alguna interfaz.