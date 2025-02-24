# Conversor de Audio y Video

Este proyecto es un sistema basado en CGI escrito en C que permite subir y convertir archivos de audio y video utilizando `mencoder`. Incluye un componente para subir archivos al servidor (`upload.c`) y otro para procesar y convertir los archivos subidos (`conversor.c`), además de una librería auxiliar (`cgilib.c`) para manejar parámetros CGI. El sistema está diseñado para integrarse con un formulario web simple que facilita la carga y descarga de videos.

## Descripción General

El proyecto consta de los siguientes componentes:

- **`conversor.c`**: Programa principal que toma parámetros enviados desde un formulario web, construye un comando para `mencoder`, lo ejecuta y devuelve un enlace al archivo convertido.
- **`upload.c`**: Script CGI que permite subir archivos al servidor utilizando formularios HTML. Soporta configuraciones personalizables mediante un archivo `.cfg`.
- **`cgilib.c`**: Librería auxiliar para procesar variables CGI, incluyendo la extracción de parámetros clave-valor.
- **`upload.cfg`**: Archivo de configuración para `upload.c`, que define rutas, máscaras de archivos y otras opciones.
- **Mini proyecto web**: Un conjunto de páginas HTML (como `OkPage.html` y `BadPage.html`) que complementan la interfaz de usuario.

El sistema está pensado para ejecutarse en un servidor web con soporte CGI (como Apache) y requiere que `mencoder` esté instalado para realizar las conversiones.

## Requisitos

- **Sistema operativo**: Compatible con Unix/Linux o Windows (con ajustes menores).
- **Compilador**: GCC o cualquier compilador compatible con C (por ejemplo, MSVC para Windows).
- **Dependencias externas**:
  - `mencoder` instalado en el sistema (parte de MPlayer).
  - Servidor web con soporte CGI habilitado (por ejemplo, Apache).
- **Librerías estándar**: `<stdio.h>`, `<stdlib.h>`, `<string.h>`, etc.

## Instalación

1. **Clonar o descargar el proyecto**:
   ```bash
   git clone <URL_DEL_REPOSITORIO>
   cd conversor-audio-video
2. **Compilar los archivos**:
   - **Para conversor.c**:
        ```bash 
        gcc -o conversor.cgi conversor.c
   - **Para upload.c**:
        ```bash
        gcc -o upload.cgi upload.c
   - **Nota**: cgilib.c se incluye directamente en conversor.c mediante #include "cgilib.c", por lo que no requiere compilación separada.
3. **Configurar el servidor web**:
   - Coloca los ejecutables (conversor.cgi y upload.cgi) en el directorio CGI del servidor (por ejemplo, /var/www/cgi-bin/ en Apache).
   - Asegúrate de que tengan permisos de ejecución:
        ```bash
        chmod +x conversor.cgi upload.cgi
   - Copia upload.cfg al directorio adecuado (por ejemplo, junto a upload.cgi) y ajusta las rutas según tu servidor.
4. **Instalar mencoder**:
   - En sistemas basados en Debian/Ubuntu:
        ```bash
        sudo apt-get install mencoder
   - En sistemas basados en Red Hat/Fedora:
        ```bash
        sudo dnf install mencoder
5. **Configurar el mini proyecto web**:
   - Coloca las páginas HTML (como OkPage.html y BadPage.html) en las rutas especificadas en upload.cfg.
   - Asegúrate de que el formulario web apunte a los scripts CGI (upload.cgi para subir y conversor.cgi para convertir).

## Uso:
1. **Subir un archivo**:
   - Accede al formulario web para cargar un archivo (por ejemplo, mediante upload.cgi).
   - El archivo se guardará en la carpeta definida en upload.cfg (por defecto: /var/www/encoder_audio_video/upload).
2. **Convertir un archivo**:
   - Usa un formulario web que envíe parámetros a conversor.cgi. 
   - Los parámetros mínimos son:
     - file: Nombre del archivo a convertir.
     - -o: Nombre del archivo de salida.
     - Otras opciones de mencoder (por ejemplo, -ovc, -oac).

   - Ejemplo de solicitud:
        ```bash
        http://<servidor>/cgi-bin/conversor.cgi?file=video.avi&-o=video.mp4&-ovc=lavc
   - El script ejecutará mencoder y devolverá un enlace al archivo convertido.
3. **Descargar el archivo**:
   - Haz clic en el enlace proporcionado en la respuesta HTML de conversor.cgi.

## Estructura del Proyecto
    conversor-audio-video/
    ├── usr/
    |   └── lib/
    |       └── cgi-bin/
    |           ├── conversor.c          # Script CGI para convertir archivos con mencoder
    |           ├── upload.c             # Script CGI para subir archivos al servidor
    |           ├── cgilib.c             # Librería para manejar parámetros CGI
    |           └── upload.cfg           # Archivo de configuración para upload.c
    └── var/
        └── www/
            └── encoder_audio_video/         # Mini proyecto web (HTML)
                ├── index.html      # Página de inicio
                ├── styles.css      # Página de estilos
                ├── OkPage.html     # Página de éxito
                ├── BadPage.html    # Página de error
                └── upload/         # directorio donde se guardan los archivos subidos

## Configuración

### upload.cfg
- Edita este archivo para ajustar:
   - Root: Directorio donde se guardan los archivos subidos.
   - FileMask: Máscara de archivos permitidos (por ejemplo, *.avi).
   - LogFile: Ruta del archivo de log.
   - OkPage y BadPage: Rutas a las páginas HTML de éxito y error.

- Ejemplo:
    ```bash
    Config = Default
    Root = /var/www/encoder_audio_video/upload
    FileMask = *
    LogFile = /var/www/encoder_audio_video/upload/upload.log
    OkPage = /var/www/encoder_audio_video/OkPage.html
    BadPage = /var/www/encoder_audio_video/BadPage.html

## Contribuciones
Si deseas contribuir:
1. **Haz un fork del repositorio.**
2. **Crea una rama para tu funcionalidad:**
    ```bash
    git checkout -b feature/nueva-funcion
    ```
3. **Envía un pull request con tus cambios.** 

## Créditos
- Conversor: Desarrollado específicamente para este proyecto.
- Upload: Basado en el trabajo de Jeroen C. Kessels (2000).
- CGILib: Adaptado del código de James Marshall (1996).

## Licencia
Este proyecto no especifica una licencia explícita. Los componentes derivados de upload.c y cgilib.c están sujetos a los términos originales de sus autores.