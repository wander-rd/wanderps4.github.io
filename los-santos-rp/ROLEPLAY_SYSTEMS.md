# Sistemas de Roleplay — Los Santos RP

Este documento describe sistemas originales para un juego de roleplay individual. Tomamos como referencia patrones generales del género —trabajos, economía, personajes, vehículos y progresión— sin copiar código, mapas, nombres, modelos ni recursos de GTA, Heroi Play u otros proyectos.

## Estado actual del prototipo web

- **Movimiento y cámaras:** caminar, entrar/salir del coche y alternar primera/tercera persona.
- **Ciudad básica:** edificios procedurales, puente de carreras, tráfico y peatones simulados.
- **Interacción con NPCs:** pulsa **F** cerca de un peatón para iniciar un encargo.
- **Primer encargo:** lleva un mensaje al puente marcado con la ruta verde del minimapa. Al llegar, se pagan **$1.500** una sola vez por encargo y el saldo se guarda en el almacenamiento local del navegador.
- **Vehículo de prueba:** mejoras de potencia provisionales, velocímetro en km/h y marcha simulada.
- **HUD:** minimapa abajo a la izquierda; velocímetro, marcha y potencia abajo a la derecha mientras se conduce.

**Límites actuales:** los personajes son modelos muy sencillos; el encargo es una prueba local, no un sistema de misiones completo. El saldo se guarda en el navegador y no es una partida nativa de PS4. El audio del motor es sintetizado y provisional. Esta demo web aún no es un PKG instalable.

## Bucle principal

1. Explorar la ciudad y acercarse a un NPC.
2. Hablar con él y aceptar una tarea clara.
3. Seguir el objetivo del HUD/minimapa.
4. Validar la llegada y entregar la recompensa una sola vez.
5. Gastar el dinero en mejoras, servicios, ropa, vehículos y propiedades.
6. Guardar el progreso y desbloquear nuevas oportunidades.

## Personaje y persistencia

- Identidad interna estable, nombre, apariencia original, empleo y ubicación segura.
- Guardar dinero, vehículos propios, misiones y progreso.
- Guardado versionado y validado; no guardar secretos.
- Recuperar un estado coherente aunque la aplicación se cierre inesperadamente.
- Para una futura versión online, la economía y las transacciones importantes deben validarse en el servidor; el prototipo actual es offline y no tiene servidor autoritativo.

## Economía offline

- Separar efectivo y cuenta bancaria cuando exista una interfaz bancaria.
- Registrar internamente cada transacción con origen, cantidad y motivo.
- Conceder recompensas de misiones una sola vez por objetivo completado.
- Equilibrar ingresos y gastos: salarios frente a reparaciones, servicios y compras.
- Precios y disponibilidad simulados localmente en el modo individual.

## Trabajos y misiones

- **Primero:** estabilizar el encargo de mensajería al puente y comprobar el pago único.
- **Después:** trabajos de conductor, asistencia mecánica y entregas entre puntos de la ciudad.
- Cada misión debe tener inicio, objetivo visible, condición de finalización, recompensa y cancelación clara.
- Evitar que una misión se active accidentalmente varias veces o pague dos veces.
- Añadir progresión y contratos nuevos solo después de probar el primer trabajo.

## NPCs y ciudad viva

- NPCs con rutinas sencillas y respuestas contextuales.
- Tráfico y peatones simulados sin conexión.
- Servicios representados por personajes o puntos interactivos: empleo, taller, tienda, hospital y concesionario.
- Eventos locales sencillos para que la ciudad no se sienta vacía.
- Las interacciones deben dejar claro que son personajes controlados por el juego, no personas reales.

## Taller propio

- El jugador empieza con un taller de prueba; más adelante se añadirá una ubicación física reconocible.
- NPCs podrán solicitar diagnóstico, reparación, pintura o mejoras.
- Cada orden debe mostrar piezas, coste, tiempo simulado, pago y beneficio.
- El jugador acepta o rechaza trabajos; el pago se concede una sola vez al completar la orden.
- Guardar reputación, caja, mejoras compradas y órdenes pendientes.
- La mecánica de clientes del taller aún no está implementada en el prototipo.

## Vehículos y personalización

- Catálogo de coches originales; modelos exactos de marcas reales solo con permisos/licencias y recursos autorizados.
- Cada vehículo tendrá datos propios de potencia, par, masa, tracción, transmisión, aceleración y velocidad máxima.
- Piezas futuras: motor, turbo, ECU, transmisión, frenos, suspensión, neumáticos, llantas, pintura y carrocería.
- Las configuraciones se guardan por vehículo.
- Las preparaciones extremas de 5.000–10.000 HP serán una opción arcade especial, pero la potencia no garantizará velocidad: agarre, aerodinámica, transmisión y estabilidad también importan.
- Mantener el puente como punto de interés, con ruta verde; después añadir salida, meta y cronómetro.
- Garaje de colección con propiedad persistente y prevención de duplicados.

## Audio de vehículos

- Sustituir progresivamente el tono sintetizado de prueba por audio original o con licencia.
- Diseñar capas para ralentí, aceleración, altas RPM, desaceleración, admisión/turbo, escape y cambios.
- Variar el sonido con RPM, carga, marcha, mejoras y distancia a la cámara.
- No extraer ni reutilizar pistas de juegos o servidores de terceros sin autorización.

## Teléfono de juego

- Teléfono con mapa, GPS, contactos de NPCs, mensajes locales, trabajos disponibles, estado del taller y notificaciones.
- Todo funciona sin red y no finge que hay jugadores reales conectados.

## Policía, tráfico y peatones

- Tráfico en rutas y peatones en zonas seguras.
- Policías NPC con patrullas y respuestas graduales a eventos del juego.
- Primero estabilidad y comportamiento creíble; después aumentar densidad.
- Mantener los sistemas dentro de una representación ficticia y no gráfica.

## Servicios y progresión

- Taller: reparar y mejorar vehículos.
- Hospital: recuperar estado y servir como punto de reaparición.
- Tiendas y vivienda: comprar artículos y propiedades con efectos persistentes.
- Inventario inicial pequeño; cada objeto debe tener una utilidad concreta.
- Ampliar el sistema de empleo con requisitos, niveles y reputación.

## Reglas de diseño

- No simular un multijugador inexistente.
- Las acciones importantes deben dar feedback claro.
- Evitar recompensas duplicadas, compras sin fondos y vehículos duplicados.
- Interfaz legible y controles accesibles con mando.
- Todos los recursos y nombres del proyecto serán originales o estarán debidamente autorizados.

## Orden recomendado

1. Movimiento, cámaras, colisiones y entrar/salir.
2. Guardado local mínimo.
3. Encargo de entrega y recompensa única.
4. Mejoras de conducción y prueba de estabilidad.
5. Garaje y propiedad de vehículos.
6. Clientes NPC del taller.
7. Más trabajos, servicios, inventario y vivienda.
8. Optimización y pruebas de compatibilidad para una futura versión nativa de PS4.

## Pruebas mínimas

- Completar un encargo y verificar que no paga dos veces.
- Intentar comprar una mejora sin dinero suficiente.
- Guardar, cerrar y cargar el progreso local.
- Entrar/salir del vehículo y cambiar la cámara en ambos estados.
- Probar colisiones y límites del mapa.
- Comprobar que la demo no depende de una conexión después de cargar todos sus recursos; por ahora, Three.js se descarga desde una CDN, así que todavía necesita internet para iniciar.

## Referencias técnicas

- [Documentación oficial de Cfx/FiveM: primer script y organización por recursos](https://docs.fivem.net/docs/scripting-manual/introduction/creating-your-first-script/).
- [Documentación oficial de Cfx/FiveM: funciones nativas](https://docs.fivem.net/docs/scripting-manual/introduction/about-native-functions/).
- [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain).
- [SDL-PS4](https://github.com/OpenOrbis/SDL-PS4).

Estas referencias sirven para estudiar conceptos técnicos; no significan que FiveM pueda ejecutarse en PS4 ni que el prototipo web sea una aplicación nativa.
