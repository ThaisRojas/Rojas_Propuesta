#include <stdio.h>
#include <stdlib.h>


struct Paciente {
    char nombre[50];
    int edad;
    float peso;
    float altura;
};

// Función para calcular el IMC
float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

int main() {
    FILE *archivo;
    struct Paciente paciente;

    archivo = fopen("historia_clinica.txt", "a+");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer la información del paciente
    printf("Ingrese el nombre del paciente: ");
    fgets(paciente.nombre, sizeof(paciente.nombre), stdin);
    
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &paciente.edad);

    printf("Ingrese el peso del paciente (en kilogramos): ");
    scanf("%f", &paciente.peso);

    printf("Ingrese la altura del paciente (en metros): ");
    scanf("%f", &paciente.altura);

    // Calcular el IMC
    float imc = calcularIMC(paciente.peso, paciente.altura);

    // Información en el archivo
    fprintf(archivo, "Nombre: %sEdad: %d\nPeso: %.2f kg\nAltura: %.2f m\nIMC: %.2f\n\n",
            paciente.nombre, paciente.edad, paciente.peso, paciente.altura, imc);

    fseek(archivo, 0, SEEK_SET);

    // Mostrar la información almacenada en el archivo
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        printf("%s", buffer);
    }

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}