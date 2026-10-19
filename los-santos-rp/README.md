# Los Santos Online RP — prototipo 3D en desarrollo

Prototipo original de mundo urbano 3D en navegador, con una ciudad procedural de prueba y un coche ficticio conducible. Esta versión amplía la primera demo con interfaz de roleplay, minimapa, velocímetro de 0–300 km/h, controles de mando R2/L2/L3, puntos de interés, empleos simulados, garaje y guardado local.

## Lo que incluye esta versión
- Ciudad 3D generada con avenidas, bloques de edificios, ventanas, parques, árboles y mobiliario urbano.
- Catálogo de seis variantes de vehículos ficticios (deportivo, SUV, compacto, sedán y modelos de lujo), compras con dinero del juego y selección guardada.
- Catorce vehículos de tráfico que circulan por las avenidas, con movimiento básico y reacción ligera a la proximidad del jugador.
- Vehículo conducible con cámara de seguimiento en tercera persona, aceleración, frenado, reversa y giro.
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
- **E:** interactuar cerca de un punto de interés
- **G:** abrir el garaje cuando estés cerca
- **M:** abrir/cerrar el móvil del juego
- **R:** recuperar el coche en el punto inicial

## Cómo probarlo
Abre index.html en un navegador moderno con conexión a internet. Three.js se carga desde jsDelivr. Si lo ejecutas mediante GitHub Pages, habilita Pages en la configuración del repositorio y visita la ruta publicada correspondiente.

## Preparación para PlayStation 4

La ruta objetivo es PS4 homebrew, no Android. En `ps4-native/` se añadió una base C++/SDL2 cenital y una guía para investigar la compilación con OpenOrbis y SDL-PS4. Es un prototipo separado de la demo 3D web: no es todavía un port de esa escena ni un PKG listo para instalar.

La creación de un PKG requiere compilar con un toolchain compatible, preparar el ejecutable y el paquete, y probarlo en el entorno de destino. No se ha compilado ni probado en una PS4 desde este entorno.

Referencias del proyecto de herramientas:
- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

## Estado y limitaciones
Esto sigue siendo un **prototipo**, no un juego AAA ni un multijugador real. Los trabajos se simulan localmente; no hay servidor ni otros jugadores; el tráfico es una simulación sencilla (no una IA avanzada), no hay peatones animados, misiones persistentes complejas ni modelos artísticos finales. Las colisiones y la conducción son aproximadas. El código aún necesita pruebas en navegadores y dispositivos reales.

**No hay un PKG compilado todavía.** GitHub almacena el código, pero no lo convierte en una aplicación de consola. La carpeta `ps4-native/` contiene el comienzo de una ruta nativa para PS4; falta configurar OpenOrbis y SDL-PS4, compilar, preparar el paquete y probarlo en hardware compatible.
