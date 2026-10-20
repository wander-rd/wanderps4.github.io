# Los Santos RP

Juego original de Roleplay de mundo abierto, con enfoque **offline y para un solo jugador** en la primera versión. El proyecto toma como referencia patrones generales del género RP y los adapta a una experiencia propia, con personajes y recursos originales.

## Estado actual
- Existe una demo web pequeña para probar movimiento y cámara.
- La demo incluye una ciudad procedural sencilla, un personaje, un vehículo de prueba no realista, perspectiva en primera/tercera persona, controles de teclado y compatibilidad básica con gamepad.\n- Se añadió un puente de carreras de prueba con guía verde e icono en el minimapa, más un indicador de potencia y ajuste experimental del motor; son mecánicas provisionales, no el sistema final de vehículos.
- La sintaxis JavaScript del prototipo se ha comprobado, pero no se ha probado todavía en un navegador real ni en la PS4.
- No hay un paquete nativo PKG compilado y probado.
- La ruta nativa de PS4 y la compatibilidad con el firmware objetivo siguen pendientes de verificación.

## Controles de la demo web
- WASD / flechas: caminar o conducir.
- E: entrar/salir del coche.
- V: alternar primera y tercera persona.
- Gamepad: stick izquierdo; gatillo derecho acelera; gatillo izquierdo frena.

## Objetivos de la beta\n- Coches de alto detalle y personalización profunda; las marcas/modelos exactos requieren licencias o assets autorizados.\n- Velocímetro abajo a la derecha en km/h, ruta verde y puente de carreras siempre identificado en el minimapa.\n- Taller propio desde el inicio, casa, capital inicial, clientes NPC, garaje/colección de vehículos y teléfono offline.\n- Tráfico denso, peatones y policía NPC, con optimización y pruebas de rendimiento para PS4.\n- Potencia extrema de hasta 5.000–10.000 HP en configuraciones especiales de competición, equilibrada por agarre y velocidad máxima.\n\n## Enfoque offline
Como no habrá otros jugadores al principio, las actividades y servicios se apoyarán en NPCs, eventos programados y sistemas locales. La economía, los vehículos y el progreso se guardarán localmente. El multijugador no forma parte del alcance actual.

## Calendario orientativo\n- Beta pequeña con sistemas básicos: aproximadamente 3–6 meses de desarrollo constante.\n- Beta más completa con ciudad detallada, tráfico, policía, taller, teléfono, coches/audio y tuning: aproximadamente 6–12 meses o más.\n- No hay fecha garantizada: el desarrollo nativo y las pruebas en PS4 son el mayor factor incierto. Ahora mismo el proyecto sigue siendo un prototipo pequeño, no un juego casi terminado.\n\n## Documentación
- [DESIGN.md](DESIGN.md): arquitectura, fases y criterios de aceptación.
- [ROLEPLAY_SYSTEMS.md](ROLEPLAY_SYSTEMS.md): personajes, trabajos, economía, vehículos y simulación de NPCs.
- [ps4-native/README.md](ps4-native/README.md): investigación de viabilidad nativa en PS4.

## Transparencia
La demo web es una herramienta de prototipado; no equivale a un juego nativo de PS4. El proyecto usa formas 3D generadas por código y no incluye recursos propietarios de GTA ni de servidores Roleplay de terceros.
