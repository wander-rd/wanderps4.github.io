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
- Empleos offline simulados: repartidor, taxista, mecánico y conductor de autobús.
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

## Preparar una APK de Android (requiere ordenador)

Se incluye una configuración inicial de Capacitor para empaquetar la versión web como app Android. No es una APK ya compilada: hay que instalar Node.js y Android Studio, ejecutar los comandos de `ANDROID_BUILD.md`, generar la carpeta nativa Android y compilar desde Android Studio. La escena 3D usa Three.js desde internet, así que esta primera APK necesita conexión para descargar esa biblioteca. La compilación aún no se ha ejecutado ni probado en un teléfono.

## Estado y limitaciones
Esto sigue siendo un **prototipo**, no un juego AAA ni un multijugador real. Los trabajos se simulan localmente; no hay servidor ni otros jugadores; el tráfico es una simulación sencilla (no una IA avanzada), no hay peatones animados, misiones persistentes complejas ni modelos artísticos finales. Las colisiones y la conducción son aproximadas. El código aún necesita pruebas en navegadores y dispositivos reales.

**No es un PKG de PS4.** GitHub almacena el código, pero no lo convierte en una aplicación de consola. Para llegar a PS4 habrá que evaluar una ruta compatible, adaptar el renderizado y los controles, compilar con un toolchain adecuado y probar el paquete en el hardware objetivo. No se garantiza compatibilidad hasta realizar esas pruebas.
