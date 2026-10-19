# Los Santos Online RP — prototipo 3D en desarrollo

Prototipo original de mundo urbano 3D en navegador, con una ciudad procedural de prueba y un coche ficticio conducible. Esta versión amplía la primera demo con interfaz de roleplay, minimapa, velocímetro de 0–300 km/h, controles de mando R2/L2/L3, puntos de interés, empleos simulados, garaje y guardado local.

## Lo que incluye esta versión
- Ciudad 3D generada con avenidas, bloques de edificios, ventanas, parques, árboles y mobiliario urbano.
- Catálogo de seis variantes de vehículos ficticios (deportivo, SUV, compacto, sedán y modelos de lujo), compras con dinero del juego y selección guardada.
- Catorce vehículos de tráfico que circulan por las avenidas, con movimiento básico y reacción ligera a la proximidad del jugador.
- Cámara alternable entre primera y tercera persona con **V**, para conducción y desplazamiento a pie.
- Personaje humanoide provisional: camina con W/S y gira con A/D; **E** permite bajar del coche y volver a entrar al acercarse.
- Vehículo conducible con aceleración, frenado, reversa y giro; la cámara sigue al coche o al personaje según el modo.
- HUD de dinero, identidad, estado de empleo, velocidad, zona y objetivo inicial.
- Minimapa con calles y puntos de interés.
- Marcadores para centro de empleo, garaje/taller, hospital, comisaría y concesionario.
- Trabajos offline con destinos: conduce hasta un punto de entrega para cobrar la recompensa.
- Garaje con selección de color, mejora de motor y reparación por dinero del juego.
- Guardado local del dinero, empleo, posición, color, vehículo seleccionado y vehículos adquiridos mediante localStorage.
- Controles táctiles básicos para móviles.

## Controles
- **Mando compatible con Gamepad API:** R2 acelera, L2 frena y entra en reversa, stick izquierdo gira y L3 toca la bocina. El navegador debe reconocer el mando.
- **W / flecha arriba:** acelerar
- **S / flecha abajo:** frenar o ir en reversa
- **A/D / flechas izquierda y derecha:** girar
- **Espacio:** freno
- **V:** alternar cámara de primera/tercera persona
- **E:** bajar/subir del coche; a pie, interactuar cerca de un punto de interés
- **G:** abrir el garaje cuando estés cerca
- **M:** abrir/cerrar el móvil del juego
- **R:** recuperar el coche en el punto inicial

## Cómo probarlo
Abre index.html en un navegador moderno con conexión a internet. Three.js se carga desde jsDelivr. Si lo ejecutas mediante GitHub Pages, habilita Pages en la configuración del repositorio y visita la ruta publicada correspondiente.

## Preparación para PlayStation 4

La ruta objetivo es PS4 homebrew, no Android. La demo web ahora sirve para probar las ideas de cámara y desplazamiento, pero **no es una aplicación de PS4**. En `ps4-native/` hay una base C++/SDL2 cenital de investigación; esa cámara desde arriba no cumple el objetivo final y no debe confundirse con el juego deseado. Aún no existe un port nativo 3D equivalente ni un PKG listo para instalar.

La creación de un PKG requiere compilar con un toolchain compatible, preparar el ejecutable y el paquete, y probarlo en el entorno de destino. No se ha compilado ni probado en una PS4 desde este entorno.

Referencias del proyecto de herramientas:
- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

## Estado y limitaciones
Esto sigue siendo un **prototipo**, no un juego AAA ni un multijugador real. Los trabajos se simulan localmente; no hay servidor ni otros jugadores; el tráfico es una simulación sencilla (no una IA avanzada), no hay peatones animados, misiones persistentes complejas ni modelos artísticos finales. Las colisiones y la conducción son aproximadas. El personaje y los modos de cámara recién añadidos son provisionales y necesitan pruebas en navegador; no se ha verificado que la demo funcione en PS4.

**No hay un PKG compilado todavía.** GitHub almacena el código, pero no lo convierte en una aplicación de consola. La carpeta `ps4-native/` contiene el comienzo de una ruta nativa para PS4; falta configurar OpenOrbis y SDL-PS4, compilar, preparar el paquete y probarlo en hardware compatible.
