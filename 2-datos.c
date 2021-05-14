#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int edad, totales, casados, solteras, mujeres, hombres, divorciados, viudas, viudas_acum;
    char sexo, estado, x;

    casados = solteras = mujeres = hombres = divorciados = viudas = viudas_acum = 0;
    do{

        totales++;
        printf("Ingrese la edad: ");
        scanf("%i%*c", &edad);

        do{

            printf("Ingrese el sexo (m/f): ");
            scanf("%c%*c", &sexo);
            

            if(sexo == 'm' || sexo == 'f'){
                break;

            }else{
                printf("Opcion incorrecta, vuelva a intentarlo.\n");
            }

        }while(1);

        do{
            
            printf("Ingrese el estado civil (s/c/d/v): ");
            scanf("%c%*c", &estado);

            if(estado == 's' || estado == 'c' || estado == 'd' || estado == 'v'){
                break;

            }else{
                printf("Opcion incorrecta, vuelva a intentarlo.\n");
            }

        }while(1);

        if(sexo == 'f'){
            
            mujeres++;
            if (estado == 's' && (edad >= 20 && edad <= 35)){
                solteras++;
            }
        }
        
        if(sexo == 'm'){

            hombres++;
            if(estado == 'd'){
                divorciados++;
            }

        }

        if(estado == 'v'){
            viudas++;
            viudas_acum += edad;
        }

        if(estado == 'c' && edad >= 50){
            casados++;
        }

        do{
            
            printf("Desea ingresar los datos de otra persona? (s/n): ");
            scanf("%c%*c", &x);
            

            if(x == 's' || x == 'n'){
                break;

            }else{
                printf("Opcion incorrecta, vuelva a intentarlo.\n");
            }

        }while(1);

    }while(x == 's');

    printf("\n");
    if(solteras > 0){
        printf("Cantidad de personas del sexo femenino solteras con edad entre 20 y 35 años de edad: %i\n", solteras);       
    }else{
        printf("No existen personas del sexo femenino solteras con edad entre 20 y 35 años de edad en el registro.\n");
    }
    
    if(divorciados > 0){
        printf("Cantidad de personas del sexo masculino que estan divorciados: %i\n", divorciados);
    }else{
        printf("No existen personas del sexo masculino que estan divorciados.\n");
    }

    if(viudas > 0){
        printf("Edad promedio entre las personas viudas: %i\n", viudas_acum/viudas);
    }else{
        printf("No existen pesonas viudas en el registro.\n");
    }

    if(hombres > 0){
        printf("El porcentaje de hombres en el grupo es de: %i\n", (hombres*100)/totales);
    }else{
        printf("No existen pesonas de sexo masculino en el registro.\n");
    }

    if(mujeres > 0){
        printf("El porcentaje de mujeres en el grupo es de: %i\n", (mujeres*100)/totales);
    }else{
        printf("No existen pesonas de sexo femenino en el registro.\n");
    }

    if(casados > 0){
        printf("La cantidad de personas casadas con edad superior a 50 años son: %i\n", casados);
    }else{
        printf("No existen personas casadas con edad superior a 50 años de edad en el registro.\n");
    }

    system("pause");
	return 0;
}
