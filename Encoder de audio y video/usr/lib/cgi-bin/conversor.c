#include "cgilib.c"


/** 
 * @title: conversor
 * @description: Programa que tomará los parámetros pasados por el 
 * convertidor web y ejecutará el mencoder con esas opciones, 
 * devolviendo un enlace al mismo.
 */
int main() {
    char **cgivars ;
    int i ;
	char *filename; char *outfile;
	char command[400]; // Esta cantidad de caracteres para el comando lo puse duro porque no me sale con punteros
	
	strcpy(command, "mencoder ");
	
    // Obtiene las variables CGI y las coloca en una lista de Strings
    cgivars= getcgivars() ;
    
	// Obtiene el nombre del archivo. El parámetro 'file' será reservado para ello.
	filename = getParam("file", cgivars);
	
	outfile = getParam("-o", cgivars);
	
	// El nombre del archivo va como primer parámetro para el mencoder.
	strcat(command, filename);
	strcat(command, " ");
	
	for (i = 0; cgivars[i]; i++) {
		// Saltea 'file' y el nombre del archivo, concatena las demás opciones y sus valores al comando.
		if (strcmp(cgivars[i], "file") != 0) {
			strcat(command, cgivars[i]);
			strcat(command, " ");
		} else {
			i++;
		}
	}
	
	// TODO: Agregar el nombre del archivo de salida al comando -> Separar otro parámetro desde el formulario (vamos a necesitar javascript)

	// Ejecuta el comando
	system(command); // <======== Cuidado con esto!
	
	
	
	/***** TEMPLATE *****/
    
    // Imprime el header HTML
    printf("Content-type: text/html\n\n") ;
    
    // Imprime el contenido de la respuesta HTML
    printf("<html>\n") ;
    printf("<head><title>Conversor - Bajar video</title></head>\n") ;
    printf("<body>\n") ;


	printf("%s\n", command); // TODO: Comentar/eliminar esta línea al terminar.
	printf("<br><a href=\"%s\">Descargar video</a>\n", outfile);
        
    printf("</body>\n") ;
    printf("</html>\n") ;

    /** Free anything that needs to be freed **/
    for (i=0; cgivars[i]; i++) free(cgivars[i]) ;
    free(cgivars) ;

    exit(0) ;
}