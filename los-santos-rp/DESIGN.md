# Los Santos RP — diseño técnico

## Visión
Juego original de mundo abierto de Roleplay, inicialmente **offline, para un solo jugador**. El jugador crea una vida en una ciudad simulada: explora, conduce, trabaja, gana dinero, compra vehículos y progresa sin depender de otros jugadores ni de conexión a un servidor.

## Recursos, coches y audio\n- Priorizar coches de alta fidelidad visual con recursos creados por el equipo o adquiridos con licencia. Quitar emblemas no concede permiso para copiar el diseño completo de un modelo protegido.\n- Para sonidos de motor, turbo, admisión, escape, transmisión y cambios, usar grabaciones propias o bibliotecas con licencia compatible; conservar la documentación de permisos. Diseñar capas por RPM, carga del acelerador, marcha y distancia.\n- No copiar archivos, modelos, configuraciones internas ni tuneos propietarios de GTA o servidores RP. Estudiar descripciones públicas para extraer ideas generales de sistemas.\n\n## Principios
- Priorizar un bucle jugable pequeño, estable y comprobable.
- La primera y tercera persona deben funcionar tanto a pie como conduciendo.
- Usar recursos, nombres, personajes y diseños propios.
- La demo web no se presenta como aplicación nativa de PS4.
- No prometer compatibilidad con firmware 13.52 hasta probar un build real.
- No desarrollar multijugador por ahora.

## Prioridades visuales y vehículos\n- **Vehículos:** modelos muy detallados con proporciones, faros, pilotos, cristales, llantas, interior, materiales, reflejos, sonido y animaciones de suspensión. Para marcas/modelos reales exactos se usarán únicamente modelos y marcas con licencia o permiso; mientras tanto, prototipos originales inspirados en categorías reales, sin presentar un modelo ficticio como copia exacta.\n- **Modificaciones:** pintura, llantas, suspensión, frenos, transmisión, turbo, motor y piezas visuales; guardar cada configuración por vehículo. El banco de potencia muestra HP, par y mejoras instaladas.\n- **Potencia:** permitir configuraciones extremas de competición como opción de juego (hasta 5.000–10.000 HP en builds especiales), con límites separados de aceleración, agarre y velocidad máxima para que no se conviertan en cifras engañosas ni rompan la física.\n- **HUD y mapa:** velocímetro digital en km/h abajo a la derecha; minimapa legible y de estilo urbano, ruta activa en verde, icono permanente del puente de carreras y marcadores de taller/casa/garaje. La ruta debe recalcularse y seguir al jugador.\n- **Puente de carreras:** punto de interés fijo en el mapa, acceso por carretera, zona de salida/meta y cronómetro en una fase posterior.\n- **Taller del líder:** taller y casa iniciales asignados al empezar; dinero inicial definido por balance de juego; garaje con propiedad de vehículos sin límite de colección artificial, sujeto al almacenamiento y rendimiento de la consola.\n- **Tráfico, peatones y policía:** densidad ajustable, conducción por carriles, cruces y reacción policial básica, con presupuesto de CPU/GPU para PS4.\n- **Teléfono:** interfaz offline con contactos NPC, mapa/ruta, trabajos, mensajes y servicios simulados; nada requiere conectarse a un servidor.\n\n## Fases
1. **Viabilidad nativa:** comprobar toolchain, renderer 3D, entrada, compilación y empaquetado compatibles con la PS4 objetivo.
2. **Movimiento:** personaje a pie, vehículo, entrar/salir, cámaras primera/tercera persona y mando.
3. **Mundo:** calles conectadas, colisiones, edificios, iluminación, tráfico y puntos de interés.
4. **Vida offline:** guardado local versionado, reloj del juego, dinero y estado del personaje.
5. **Actividades:** una misión de entrega, trabajo de conductor y un taller de reparación.
6. **Vida ciudadana:** tiendas, garaje, compra/propiedad de vehículos, vivienda e interacciones con NPCs.
7. **Sistemas ampliados:** progresión de empleos, servicios de la ciudad, eventos y más barrios.
8. **QA:** builds reproducibles, pruebas de rendimiento y pruebas reales en PS4.

## Arquitectura
- Separar simulación, renderizado, entrada, interfaz y persistencia.
- Estados explícitos: menú, a pie, conduciendo e interfaz.
- Entrada normalizada: teclado para prototipo y mando como objetivo principal de consola.
- La lógica de misiones y economía no debe depender de elementos visuales del HUD.
- Guardados locales con versión de esquema, validación y migraciones.
- Simulación offline de NPCs: rutinas, necesidades sencillas, tráfico y servicios básicos.
- Los eventos de NPC no deben exigir conexión ni fingir que hay jugadores reales.

## Criterios de aceptación del primer vertical slice
- Caminar y conducir sin atravesar edificios.
- Entrar/salir del vehículo de forma coherente.
- Primera y tercera persona a pie y conduciendo.
- Cámara, minimapa y velocímetro siguen el actor correcto.
- El mando se detecta y tiene controles documentados.
- La demo no pierde el control después de alternar estados.
- El progreso local se guarda y carga sin duplicar dinero ni vehículos.
- Cada build identifica claramente si es demo web o nativa probada.

## Fuera de alcance por ahora
Multijugador, servidores, economías dependientes de otros jugadores, mapas enormes e interiores detallados. Solo se reconsiderarán cuando la versión individual sea estable.

## Estimación orientativa de la beta\nEstas cifras son planificación, no una fecha garantizada ni una promesa de trabajo en segundo plano. Con una persona desarrollando de forma constante y recursos disponibles, una beta de alcance reducido podría requerir aproximadamente 3–6 meses; una beta más cercana a la visión completa (ciudad detallada, tráfico, policía, taller, teléfono, garaje, audio y tuning) podría tomar 6–12 meses o más. La ruta nativa de PS4 puede cambiar mucho la estimación: aún hay que validar renderer, mando, rendimiento, empaquetado y compatibilidad real.\n\nHitos para medir progreso: (1) vertical slice estable; (2) economía/guardado/taller; (3) NPC, tráfico y policía; (4) vehículos, audio y minimapa; (5) pruebas de rendimiento; (6) build nativo de prueba y revisión de instalación.\n\n## Ruta nativa
OpenOrbis y SDL-PS4 son puntos de investigación, no una garantía de que un motor 3D pueda compilar sin cambios. Hay que validar la ruta gráfica y el empaquetado con pruebas reproducibles antes de afirmar que existe una versión instalable.
