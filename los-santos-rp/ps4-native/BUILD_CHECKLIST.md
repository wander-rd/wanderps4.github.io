# Checklist de compilación nativa — Los Santos RP

Este archivo es una lista de verificación, no un script que fabrique un PKG. El proyecto todavía no se ha compilado para PS4 y no contiene un paquete instalable.

## Puerta 1: entorno

- [ ] Registrar el sistema operativo del equipo de compilación.
- [ ] Instalar una versión publicada del OpenOrbis PS4 Toolchain y guardar su número de versión.
- [ ] Confirmar que `OO_PS4_TOOLCHAIN` apunta a la raíz correcta del toolchain.
- [ ] Confirmar que Clang/LLVM y el enlazador requeridos están disponibles.
- [ ] Revisar la dependencia de .NET indicada por la versión de LibOrbisPkg instalada.
- [ ] Elegir una muestra oficial compatible con el toolchain instalado y guardar una copia intacta para comparar.

## Puerta 2: prueba mínima

- [ ] Compilar primero una muestra oficial sin modificaciones.
- [ ] Registrar los comandos reales que usa esa muestra; no adivinar flags ni rutas.
- [ ] Compilar `src/main.cpp` solo si el SDL-PS4 y las APIs de ventana/superficie usadas por el scaffold coinciden con esa muestra.
- [ ] Corregir errores de compilación y enlace antes de añadir sistemas de juego.
- [ ] Confirmar entrada de mando, salida de vídeo y cierre limpio en un entorno compatible.
- [ ] Guardar los logs y anotar qué firmware/hardware se probó.

## Puerta 3: empaquetado

- [ ] Generar `eboot.bin` con la herramienta y el procedimiento documentados por la versión instalada.
- [ ] Preparar los metadatos de aplicación requeridos por la muestra seleccionada.
- [ ] Incluir únicamente módulos y recursos que el ejecutable realmente necesite.
- [ ] Generar el proyecto GP4 con la herramienta oficial apropiada.
- [ ] Crear el PKG con las herramientas compatibles con ese proyecto GP4.
- [ ] Comprobar que el archivo existe, tiene tamaño razonable y el proceso termina sin errores.
- [ ] Registrar nombre, tamaño y hash del artefacto para distinguir builds.

## Puerta 4: prueba real

- [ ] Instalar y probar solo en un entorno PS4 compatible y autorizado para homebrew.
- [ ] Verificar inicio, renderizado, mando, salida y estabilidad.
- [ ] Anotar fallos y reproducirlos antes de integrar mecánicas adicionales.
- [ ] No llamar “jugable” ni “compatible con firmware 13.52” a un build hasta que esa combinación se haya probado realmente.

## Orden recomendado

Primero demostrar que compila una muestra oficial; luego el scaffold SDL2; después un menú nativo; después controles y movimiento; por último, portar sistemas de RPG en incrementos pequeños. La demo web basada en Three.js no se transforma automáticamente en código nativo.

## Fuentes oficiales de referencia

- OpenOrbis PS4 Toolchain: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain
- Muestras oficiales: https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/tree/master/samples
- SDL-PS4: https://github.com/OpenOrbis/SDL-PS4

Las herramientas y dependencias pueden variar por versión. Usar los archivos y las instrucciones de la release instalada, no copiar comandos de una versión distinta sin verificarlos.
