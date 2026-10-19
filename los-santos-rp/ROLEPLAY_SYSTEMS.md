# Investigación de sistemas de Roleplay — Los Santos Online RP

Este documento convierte patrones comunes del género RP en un diseño propio. No se copian recursos, nombres, mapas ni código de otros juegos o servidores.

## Qué significa Roleplay en el diseño
El jugador interpreta a un ciudadano persistente en una ciudad compartida o simulada. Las actividades tienen contexto, reglas y consecuencias; los trabajos y servicios dependen unos de otros; las decisiones forman una historia del personaje.

## Bucle principal
1. Entrar con un personaje y cargar su estado guardado.
2. Elegir una actividad: explorar, trabajar, conducir, socializar o gestionar una propiedad.
3. Completar objetivos y recibir recompensas calculadas por el sistema.
4. Gastar o ahorrar recursos: combustible/reparaciones, ropa, vehículos, vivienda o servicios.
5. Guardar progreso y desbloquear nuevas posibilidades.

## Sistemas que se construirán
### 1. Identidad y personaje
- Identificador interno estable, nombre de rol y apariencia original.
- Estado: ubicación segura, dinero, empleo, inventario y vehículos propios.
- Creación y edición con límites claros; guardado versionado.
- No guardar secretos ni confiar en datos enviados por un cliente en modo multijugador.

### 2. Economía
- Efectivo y cuenta separados cuando exista una interfaz bancaria.
- Cada transacción registra origen, destino, cantidad y razón.
- Pagos por misión validados en el sistema de juego; nunca pagar repetidamente por mantener pulsado un botón.
- Precios equilibrados: ingresos por trabajo frente a reparación, servicios, vehículos y vivienda.
- Para el primer prototipo: moneda local simulada y una única recompensa de trabajo.

### 3. Trabajos y misiones
- Centro de empleo para seleccionar trabajos.
- Una misión activa por personaje al principio.
- Objetivo visible en mapa/HUD, estado de progreso, validación de llegada y pago único.
- Tipos iniciales: entrega, conductor de pasajeros y mecánico de servicio.
- Futuro: niveles, reputación y requisitos, evitando tareas repetitivas sin propósito.

### 4. Vehículos
- Catálogo de modelos ficticios, compra, propiedad y selección.
- Entrada/salida segura; cámara en primera y tercera persona.
- Conducción, colisiones, daños, reparación y mejoras en fases separadas.
- Garaje que guarda vehículos y evita duplicación.
- En multijugador, el servidor valida propiedad, compras y transacciones.

### 5. Servicios y ciudad
- Hospital: recuperar estado y servir como punto de reaparición.
- Mecánico: reparación y mejoras.
- Policía: sistema de reglas y multas solo cuando el resto del bucle sea estable.
- Tiendas y vivienda: fases posteriores.
- Calles, señales, zonas, puntos de interés y tráfico deben tener datos comunes para el mapa y la navegación.

### 6. Inventario y objetos
- Empezar con inventario pequeño y tipos de objeto definidos.
- Límites de capacidad, transferencias y consumo validados por el sistema.
- No implementar objetos que no tengan una función jugable clara.

### 7. Juego social y reglas
- Interacciones contextuales, mensajes y emotes en etapas posteriores.
- Reglas visibles contra acoso, spam, exploits y sabotaje del juego de otros.
- Herramientas de moderación antes de abrir un servidor público.
- La primera versión será individual; el multijugador no se simulará como si ya existiera.

### 8. Guardado y servidor
- Modo individual: archivo/almacenamiento local con versión de esquema y valores validados.
- Multijugador futuro: servidor autoritativo; el cliente solicita acciones, el servidor comprueba reglas y confirma resultados.
- Registrar transacciones importantes y manejar reconexión, duplicados y estados incompletos.
- No exponer credenciales ni secretos en el cliente.

## Orden recomendado de implementación
1. Movimiento/cámara y conducción.
2. Colisiones y entrada/salida del vehículo.
3. Guardado local mínimo.
4. Una misión de entrega con recompensa única.
5. Garaje y catálogo con propiedad persistente.
6. Más trabajos y servicios.
7. Inventario y propiedades.
8. Diseño de servidor y multijugador después de estabilizar lo anterior.

## Pruebas mínimas para cada sistema
- Caso normal.
- Intento de repetir una acción o cobrar dos veces.
- Falta de dinero o recurso.
- Guardar, cerrar y cargar.
- Entrar/salir de una interfaz durante la acción.
- Límites de mapa y colisiones.
- En multijugador futuro: datos manipulados por cliente, desconexión y repetición de solicitudes.

## Referencias de investigación técnica
- FiveM — introducción a scripting y recursos: https://docs.fivem.net/docs/scripting-manual/introduction/creating-your-first-script/
- FiveM — conceptos de networking: https://docs.fivem.net/docs/scripting-manual/networking/
- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

## Limitación importante de plataforma
OpenOrbis es una ruta homebrew útil para investigar, pero su documentación incluye funciones gráficas que siguen en desarrollo. No se da por hecho que un motor 3D de escritorio o un prototipo web se pueda compilar sin cambios para PS4. La decisión de renderer depende de una prueba nativa real.
