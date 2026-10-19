# Ruta nativa para PlayStation 4

Esta carpeta queda como espacio de investigación de la ruta nativa, reiniciado junto con el proyecto. El antiguo prototipo 2D cenital fue retirado; todavía no existe aquí una implementación nativa nueva.

## Objetivo técnico
Investigar una ruta de renderizado 3D y controles para PS4 homebrew. Antes de escribir un motor o prometer un PKG, verificar:
- versión de OpenOrbis y compilador disponibles;
- compatibilidad de bibliotecas gráficas y entrada con el firmware objetivo;
- SDL-PS4 u otra ruta de renderizado realmente utilizable;
- compilación, enlace, empaquetado e instalación;
- prueba reproducible en la consola objetivo.

## Estado
- Sin código nativo jugable en este reinicio.
- Sin PKG compilado o probado.
- La demo web en `../index.html` es únicamente una prueba de mecánicas y no se convierte automáticamente en una aplicación de PS4.

## Referencias técnicas
- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

Cualquier compatibilidad con firmware 13.52 debe demostrarse con un build y una prueba real; no se da por supuesta.
