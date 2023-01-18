# COLISIONES EN FIGURAS 2D
Antes que todo este código puede ser usado en proyectos que usen un plano en 3D .

### Solución a problemas de ejecución
Al momento de querer ejecutar el programa les saldra error, pero tranquilos, este error tiene una solución sencilla,
para solucionarlo tenemos que seguir lo siguiente:
> Copia lo siguiente: _CRT_SECURE_NO_WARNINGS

![Solucion](https://user-images.githubusercontent.com/96871746/212933383-9f5548fb-c07f-4a61-9e86-019d7020e7e3.gif)

### Modificar fuente de letras
El siguiente código solo es para ejemplo , no esta completo.
Para modificar la fuente de letra nos guiaremos de esta pag.

> https://www.opengl.org/resources/libraries/glut/spec3/node76.html#SECTION000111000000000000000

Cada *font_style* guarda el tipo de fuente de la letra , quizas no hay muchas fuentes , pero hay librerias que ayudan con mas variedad.
```C++
void Texto::printw(int val, float x, float y, float z, const char* format, ...) {
	if (val == 1) {
		font_style = GLUT_BITMAP_TIMES_ROMAN_10; 
	}
	else {
		font_style = GLUT_BITMAP_TIMES_ROMAN_24;
	}
}
```
### Uso de la geometría analítica básica
Para saber cuando una figura geométrica colisiona con otra, debemos saber su posición en X y Y en ambas figuras. Para ello se ha usado la formula de distancia entre dos puntos:

$$d = \sqrt {\left( {x_1 - x_2 } \right)^2 + \left( {y_1 - y_2 } \right)^2 }$$

Realizado en el mismo código (Codigo de ejemplo):

```C++
void Actualizar(){
  distancia = sqrt(pow(posX1 - posX2, 2) + pow(posY1 - posY2,2));
  if(distancia <= 10){
    //hay colision
  }
}
```
### Mas colisiones
Para mas colisiones puede usar la siguiente pagina : https://ants.inf.um.es/staff/jlaguna/tp/tutoriales/colisiones/index.html

![Pag](https://user-images.githubusercontent.com/96871746/213083139-1235fc83-b47a-41d4-8bd7-67a14fff48f5.gif)

### Programa en Ejecución:

![Ejec](https://user-images.githubusercontent.com/96871746/213079652-f2bf2436-5b84-439d-8771-295325a5c746.gif)
