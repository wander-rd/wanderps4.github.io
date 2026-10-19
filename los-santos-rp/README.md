# Los Santos Online RP

Proyecto reiniciado desde cero el 19 de octubre de 2026. El código de la demo anterior no se usa como base. El historial Git permanece como respaldo; el resto del sitio no se modifica.

## Qué es hoy
Un prototipo web mínimo para probar el ciclo de movimiento y cámara. **No es el juego final ni una aplicación nativa de PS4.** La ruta de PS4 requiere validar el toolchain, el renderer y el empaquetado antes de afirmar que se puede instalar.

## Controles del prototipo web
- WASD / flechas: caminar o conducir
- E: entrar/salir del coche
- V: alternar primera y tercera persona
- Gamepad: stick izquierdo para moverse/girar, gatillo derecho para acelerar, gatillo izquierdo para frenar

## Prioridad de desarrollo
1. Viabilidad nativa de PS4.
2. Personaje y vehículo con ambas cámaras.
3. Mundo y colisiones.
4. Guardado, economía y trabajos.
5. Sistemas de Roleplay.
6. Multijugador.

Lee [DESIGN.md](DESIGN.md) para la arquitectura, criterios de aceptación y límites del proyecto. El prototipo web depende de Three.js desde CDN y requiere conexión a internet para cargar esa librería.

## Transparencia
No hay PKG nativo compilado ni probado en esta versión. La demo web sirve para iterar sobre mecánicas, no demuestra compatibilidad con PS4. Todos los recursos visuales son formas originales generadas por código.
