# Los Santos Online RP — diseño técnico inicial

## Objetivo
Crear un juego original de mundo abierto con mecánicas de Roleplay, dirigido a PS4 con jailbreak y herramientas homebrew compatibles. No copiar código, mapas, marcas, personajes, modelos ni otros recursos protegidos de GTA.

## Estado y transparencia
- El prototipo web sirve únicamente para iterar mecánicas.
- No hay un paquete nativo PKG compilado o probado.
- La compatibilidad con firmware 13.52 y la ruta gráfica 3D deben verificarse en un entorno real.
- El código previo no es base del nuevo prototipo; el historial Git queda como respaldo técnico.

## Fases
1. **Viabilidad PS4:** comprobar toolchain, renderer 3D, bibliotecas, compilación, empaquetado y método de prueba.
2. **Movimiento:** personaje a pie, vehículo, entrar/salir, cámara primera/tercera persona, mando.
3. **Mundo:** calles, colisiones, edificios, iluminación, tráfico y navegación.
4. **Persistencia:** personaje, dinero, vehículos propios, guardado versionado.
5. **Roleplay civil:** trabajos, objetivos, pagos, tiendas, mecánico, hospital y policía.
6. **Multijugador:** servidor autoritativo, persistencia, sincronización y validación de acciones.
7. **QA:** builds reproducibles, pruebas de rendimiento, errores y pruebas reales en PS4.

## Arquitectura prevista
- Separar simulación, representación, entrada, interfaz y persistencia.
- Máquina de estados explícita: menú, a pie, conduciendo e interfaz.
- Entrada normalizada para teclado de prototipo y mando de consola.
- Misiones/economía separadas del HUD.
- Guardados versionados y migrables.
- En multijugador, servidor autoritativo: el cliente no decide su dinero ni recompensas.
- Recursos visuales y nombres originales.

## Criterios de aceptación del primer vertical slice
- Movimiento y colisiones coherentes.
- Entrar/salir del vehículo sin teletransportes inesperados.
- Primera y tercera persona tanto a pie como conduciendo.
- Cámara y minimapa siguen al actor correcto.
- Velocímetro representa la velocidad real.
- Mando documentado y funcional.
- Guardado/carga sin duplicación de dinero ni vehículos.
- Cada build indica claramente si es demo web o nativa probada.

## Fuera de alcance inicialmente
Multijugador, mundo enorme, interiores detallados, economía compleja y afirmaciones de rendimiento antes de estabilizar el movimiento y la ruta gráfica.
