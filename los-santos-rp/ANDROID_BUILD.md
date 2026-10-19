# Preparar una APK de Android

Esta es una guía de compilación; el repositorio no contiene una APK compilada todavía.

## Requisitos
- Ordenador Windows, macOS o Linux.
- Node.js LTS y npm.
- Android Studio con Android SDK instalado.
- Conexión a internet para descargar dependencias y Three.js.

## Pasos
1. Descarga o clona el repositorio y abre una terminal en la carpeta `los-santos-rp`.
2. Instala dependencias:
   ```bash
   npm install
   ```
3. Genera el proyecto Android nativo (solo la primera vez):
   ```bash
   npx cap add android
   ```
4. Sincroniza la app web con Android:
   ```bash
   npm run android:sync
   ```
5. Abre Android Studio:
   ```bash
   npx cap open android
   ```
6. En Android Studio, espera a que termine Gradle y usa **Build > Build Bundle(s) / APK(s) > Build APK(s)**.
7. Android Studio mostrará la ruta de la APK generada. Instálala primero en un dispositivo de prueba y revisa rendimiento, controles táctiles y pantalla.

## Importante
- Esto empaqueta la versión web; no la convierte mágicamente en un GTA completo.
- La escena importa Three.js desde jsDelivr y necesita internet al iniciar. Para una versión sin conexión hay que empaquetar Three.js localmente.
- La configuración de compilación no se ha ejecutado aquí. Pueden aparecer errores de SDK/Gradle que deban resolverse en Android Studio.
- Una APK es para Android. PS4 usa otro formato y otro proceso; esta guía no genera un PKG de PS4.
