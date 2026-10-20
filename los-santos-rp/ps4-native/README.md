# Ruta nativa para PlayStation 4 — Los Santos RP

Esta carpeta documenta la investigación para una futura versión nativa. El antiguo prototipo cenital fue retirado; todavía no hay una implementación nativa jugable aquí.

## Objetivo
Investigar una ruta de renderizado 3D y controles para una PS4 con homebrew compatible. Antes de escribir un motor o prometer un paquete, verificar:
- toolchain y compilador disponibles;
- compatibilidad de bibliotecas gráficas y entrada con el firmware objetivo;
- SDL-PS4 u otra ruta gráfica utilizable;
- compilación, enlace, empaquetado e instalación;
- prueba reproducible en la consola objetivo.

## Estado
- El juego se llama **Los Santos RP**.
- El objetivo actual es offline y de un solo jugador.
- Se añadió `src/main.cpp`, un pequeño scaffold SDL2 para comprobar inicialización, ventana, eventos y entrada básica. Solo es un punto de partida; no contiene la ciudad ni los sistemas del juego.
- El scaffold no se ha compilado ni ejecutado en PS4. La disponibilidad de SDL2, el renderer/superficie, el mapeo del mando y las dependencias deben verificarse en el entorno objetivo.
- No hay PKG compilado o probado.
- La demo web es solo una prueba de mecánicas y no se convierte automáticamente en una aplicación de PS4.

## Checklist reproducible

Antes de compilar o empaquetar, sigue [`BUILD_CHECKLIST.md`](./BUILD_CHECKLIST.md). Esa lista separa validación del entorno, compilación mínima, empaquetado y prueba real; no supone que SDL2 ni el firmware objetivo ya sean compatibles.

## Referencias
- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

La compatibilidad con firmware 13.52 debe demostrarse mediante compilación y prueba real; no se da por supuesta.

## Preparación del build nativo

1. Seleccionar una versión concreta del OpenOrbis PS4 Toolchain y registrar sistema operativo, versión del toolchain y firmware objetivo.
2. Instalar/validar Clang/LLVM y definir `OO_PS4_TOOLCHAIN` según la documentación oficial.
3. Partir de una muestra oficial de SDL2 o gráficos del toolchain para tomar las reglas reales de compilación, módulos y empaquetado; no asumir que un proyecto web puede compilarse directamente.
4. Compilar el scaffold `src/main.cpp` como prueba mínima y corregir cualquier incompatibilidad de SDL2/entrada/presentación.
5. Solo tras una compilación correcta, preparar los metadatos del paquete, `eboot.bin`, módulos requeridos y el proyecto GP4 usando las muestras/documentación del toolchain.
6. Verificar el artefacto resultante y probarlo en el hardware/entorno compatible. El resultado no está garantizado hasta completar esas pruebas.

### Requisitos de empaquetado que hay que verificar

La documentación de OpenOrbis enumera herramientas como `create-eboot`, `create-gp4` y LibOrbisPkg, y sus muestras incluyen `sce_sys/param.sfo`, `pkg.gp4`, `eboot.bin` y, según la muestra, `sce_module`. La lista exacta de archivos y módulos debe salir de la muestra elegida y del build real; no generar un paquete vacío ni declarar que un PKG existe antes de que el proceso termine correctamente.

## Contabilidad del scaffold

- `src/main.cpp`: prueba de inicialización SDL2, ventana, bucle de eventos y estado visual mínimo.
- No es el motor 3D definitivo, no contiene assets y no está validado en PS4.
- Próxima puerta de calidad: compilar y probar este pequeño programa antes de portar mecánicas desde la demo web.
