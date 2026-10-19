# Los Santos Online RP — objetivo PlayStation 4

Este directorio comienza una **ruta nativa para PS4 homebrew** separada de la demo web. No es todavía un juego completo ni un PKG compilado.

## Fuente actual
- `src/main.cpp`: base C++/SDL2 con ciudad cenital de prueba, bloques con ventanas, tráfico sencillo, seis variantes visuales de coche, aceleración/frenado, minimapa cuadrado propio, velocímetro abajo a la derecha, contador de dinero/trabajos y una misión de entrega de prueba. El HUD usa una fuente bitmap dibujada por código, sin fuentes externas.
- La demo web previa sigue en `../index.html`; no se puede empaquetar directamente como aplicación PS4 sin portar/reimplementar su motor y sus recursos.

## Controles actuales de prototipo
- Teclado: WASD o flechas para conducir; E cerca del destino para completar una entrega.
- Mando compatible con SDL GameController: stick izquierdo para girar, R2 para acelerar, L2 para frenar/reversa, Y para cambiar variante, X para comprar una mejora por $750 y A cerca del destino para completar una entrega por $500.
- Estos controles son provisionales y todavía necesitan pruebas en PS4.

## Ruta de compilación
1. Preparar un ordenador con el OpenOrbis PS4 Toolchain y sus dependencias.
2. Preparar SDL-PS4 para el mismo toolchain.
3. Adaptar este código a la plantilla SDL2/OpenOrbis y enlazar las bibliotecas correctas.
4. Compilar el ejecutable ELF, convertirlo al formato esperado por PS4 y generar el proyecto PKG con las herramientas correspondientes.
5. Probarlo en un entorno compatible antes de distribuirlo.

Referencias oficiales del proyecto de herramientas:
- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

## Estado honesto
Este código **no se ha compilado** en este entorno: aquí no está instalado ni configurado el toolchain PS4 ni SDL-PS4. La fuente es un punto de partida de prototipo 2D cenital, no el juego 3D web portado, y no se garantiza que compile sin adaptar el sistema de construcción y revisar las APIs de SDL-PS4. Todavía faltan modelos 3D, colisiones completas, audio, misiones, guardado nativo, interiores, optimización y pruebas de mando en la consola.
