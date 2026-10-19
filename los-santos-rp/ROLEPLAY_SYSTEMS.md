# Sistemas de Roleplay — Los Santos RP (offline)

Este diseño adapta patrones generales del género Roleplay a una experiencia individual. No copia código, mapas, nombres, modelos ni recursos de Heroi Play, GTA u otros proyectos.

## Bucle principal
1. Cargar el personaje y su progreso local.
2. Explorar la ciudad y hablar/interactuar con NPCs.
3. Elegir un trabajo, servicio o actividad.
4. Completar objetivos visibles y recibir una recompensa calculada por el juego.
5. Usar el dinero en reparaciones, vehículos, ropa, servicios y propiedades.
6. Guardar el progreso y desbloquear nuevas oportunidades.

## Personaje y persistencia
- Identidad interna estable, nombre, apariencia original, empleo y ubicación segura.
- Guardar dinero, vehículos propios, misiones y progreso.
- Guardado versionado y validado; no guardar secretos.
- La carga de una partida debe recuperar un estado coherente aunque la aplicación se cierre inesperadamente.

## Economía offline
- Dinero en efectivo y cuenta bancaria como sistemas separados cuando exista la interfaz bancaria.
- Registrar internamente cada transacción con origen, cantidad y motivo.
- Las recompensas de misiones se conceden una sola vez por objetivo completado.
- Los ingresos y los gastos deben estar equilibrados: salarios frente a reparaciones, servicios y compras.
- Como es un juego individual, la economía no depende de otros jugadores. Los precios y la disponibilidad se simulan localmente.

## Trabajos y misiones
- Centro de empleo con trabajos disponibles y requisitos.
- Una misión activa al principio.
- Marcador en mapa/HUD, pasos claros, comprobación de llegada y recompensa única.
- Primeras actividades recomendadas: entregas, conductor de pasajeros y asistencia mecánica.
- Añadir progresión y nuevos contratos solo después de que el primer trabajo sea estable.

## NPCs y ciudad viva
- NPCs con rutinas sencillas y respuestas contextuales.
- Tráfico y peatones simulados sin necesidad de conexión.
- Servicios representados por NPCs o puntos interactivos: empleo, taller, hospital, tienda y concesionario.
- Eventos locales programados para que la ciudad no se sienta vacía.
- Las interacciones deben dejar claro que son personajes controlados por el juego, no personas reales.

## Vehículos y personalización avanzada\n- La beta debe priorizar modelos de coches de gran detalle, con carrocería, proporciones, luces, cristales, ruedas, cabina visible, materiales y sonidos diferenciados. Los modelos exactos de marcas reales requieren licencias/permisos y recursos apropiadamente autorizados; no se copiarán assets de GTA ni de servidores de terceros.\n- Cada coche tendrá datos propios de potencia, par, masa, tracción, transmisión, aceleración y velocidad máxima. La velocidad que muestra el HUD se calcula desde el movimiento del vehículo y aparece abajo a la derecha en km/h.\n- Piezas: motor, turbo, ECU, transmisión, frenos, suspensión, neumáticos, llantas, pintura y carrocería. La configuración se guarda por coche.\n- Builds de carreras extremas podrán llegar a 5.000–10.000 HP como opción arcade especial, pero la potencia no será lo mismo que velocidad garantizada: agarre, aerodinámica, transmisión y seguridad de rendimiento limitarán el resultado.\n- Puente de carreras permanente en el minimapa, con icono de puente y ruta activa verde; luego se añadirá salida/meta y cronómetro.\n- Garaje de colección con vehículos conseguidos, duplicados bloqueados y persistencia local.\n\n## Taller propio y liderazgo\n- El jugador comienza como dueño/líder del taller y recibe una casa inicial y capital inicial configurable para probar el bucle económico.\n- Los NPCs pueden llegar por cita o evento aleatorio a pedir diagnóstico, reparación, pintura o mejoras. Cada orden muestra coste de piezas, tiempo simulado, pago y beneficio.\n- El jugador acepta o rechaza trabajos; los ingresos se conceden una sola vez cuando se entrega el vehículo.\n- Se guarda reputación del taller, caja, mejoras compradas y órdenes pendientes.\n\n## Teléfono de juego\n- Teléfono con mapa, GPS, contactos de NPCs, mensajes locales, trabajos disponibles, estado del taller y notificaciones. Todo funciona sin red y no finge que son jugadores reales.\n\n## Policía, tráfico y peatones\n- Tráfico en rutas, peatones por zonas seguras y policías NPC con patrulla y respuesta gradual a infracciones/eventos del juego.\n- La densidad se ajusta a la capacidad real de la versión nativa; primero estabilidad, después aumentar cantidad.\n\n## Vehículos
- Catálogo de prototipos originales; coches reales exactos solo con licencias y modelos autorizados, compra y propiedad persistente.
- Entrar/salir, cámara en primera/tercera persona y controles de mando.
- En fases posteriores: daños, combustible, reparación y mejoras de rendimiento.
- Garaje que guarda vehículos y evita duplicados.
- El HUD debe mostrar velocidad real y el minimapa debe seguir al jugador o vehículo activo.

## Servicios y progresión
- Taller: reparar y mejorar vehículos.
- Hospital: recuperar estado y servir como punto de reaparición.
- Policía y servicios de emergencia: primero como NPCs y sistemas sencillos de ciudad; ampliar después.
- Tiendas y vivienda: comprar artículos y propiedades con efectos persistentes.
- Inventario pequeño al principio; cada objeto debe tener una utilidad concreta.

## Reglas de diseño
- No se simulará un multijugador inexistente.
- Las acciones importantes deben dar feedback claro.
- Evitar recompensas duplicadas, compras sin fondos o vehículos duplicados.
- Los sistemas deben ser accesibles con mando y tener una interfaz legible.
- Todos los recursos y nombres del proyecto serán originales.

## Orden recomendado
1. Movimiento y cámaras.
2. Colisiones y entrar/salir del coche.
3. Guardado local mínimo.
4. Una misión de entrega con recompensa única.
5. Garaje y propiedad de vehículos.
6. NPCs y tráfico básicos.
7. Más empleos, servicios, inventario y propiedades.
8. Pruebas de rendimiento y compatibilidad nativa en PS4.

## Pruebas mínimas
- Completar una misión y comprobar que no paga dos veces.
- Intentar comprar algo sin dinero suficiente.
- Guardar, cerrar y cargar la partida.
- Entrar/salir del vehículo y cambiar la cámara en ambos estados.
- Probar límites del mapa y colisiones.
- Desconectar internet y confirmar que el modo offline no depende de red.

## Referencias técnicas de consulta
- FiveM scripting concepts (referencia general de organización de sistemas): https://docs.fivem.net/docs/scripting-manual/introduction/creating-your-first-script/
- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

Estas referencias sirven para estudiar conceptos técnicos. No significan que FiveM pueda ejecutarse en PS4 ni que el prototipo web sea una app nativa.
