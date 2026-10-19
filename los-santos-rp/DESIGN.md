# Los Santos RP — diseño técnico

## Visión
Juego original de mundo abierto de Roleplay, inicialmente **offline, para un solo jugador**. El jugador crea una vida en una ciudad simulada: explora, conduce, trabaja, gana dinero, compra vehículos y progresa sin depender de otros jugadores ni de conexión a un servidor.

## Principios
- Priorizar un bucle jugable pequeño, estable y comprobable.
- La primera y tercera persona deben funcionar tanto a pie como conduciendo.
- Usar recursos, nombres, personajes y diseños propios.
- La demo web no se presenta como aplicación nativa de PS4.
- No prometer compatibilidad con firmware 13.52 hasta probar un build real.
- No desarrollar multijugador por ahora.

## Fases
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

## Ruta nativa
OpenOrbis y SDL-PS4 son puntos de investigación, no una garantía de que un motor 3D pueda compilar sin cambios. Hay que validar la ruta gráfica y el empaquetado con pruebas reproducibles antes de afirmar que existe una versión instalable.
