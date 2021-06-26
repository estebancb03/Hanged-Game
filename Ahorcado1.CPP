#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <11-4.h>
#include <dos.h>

#define ABC 26 //Constante que controla la impresión del abecedario

//VARIABLES GLOBALES

int j, largo, intento = 0, compara, contop = 0;
int option;
char letra;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//VECTORES Y MATRICES

char palabras[30][20]; //Matriz que almacena todas las palabras
char palabra[20]; //Vector que controla el almacenamiento de la palabra introducida por el usuario
char respuesta[20]; //Vector que controla la cantidad de letras que el usuario puede digitar segun la palabra
int partidas[] = {0}; //Vector que controla el número de partidas jugadas
int derrotas[] = {0}; //Vector que controla el número de derrotas
int victoria[] = {0}; //Vector que controla el número de derrotas
int letras[] = {0}; //Vector que guarda la cantidad de letras digitadas

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//FUNCIONES

//Función que determina el número de derrotas que ha tenido el jugador

int itsover(int d[])
{
   int derr = 0;
   if(intento >= 20) //Si el usuario gasta todos sus intentos
   {
   	d[derr] += 1; //Se acumula las derrotas dentro del vector
   }
   return d[derr]; //Se retorna el resultado de acumulado por el vector
}

//Función que determina el número de vicorias que ha tenido el jugador

int victorias(int v[])
{
   int victory = 0;
   if(intento < 20) //Si el usuario gasta todos sus intentos
   {
   	v[victory] += 1; //Se acumula las derrotas dentro del vector
   }
   return v[victory] - 1; //Se retorna el resultado de acumulado por el vector - 1 ya que cuando se inicia el programa siempre los intentos
   						     //serán menores que 20 por lo que se acumulará un "1" indeseable para la cuenta desde el principio y al retarle 1
                          //se nivela la estadística en 0 desde el inicio.
}

//Función que determina el número de letras digitadas

int partida(int p[])
{
   int sumapartidas = 0;
	if(intento == 0)
   {
   	p[sumapartidas] += 1; //Cuenta cada letra que se digita
   }
   return p[sumapartidas];
}

//Función que determina el promedio de victorias del jugador

float promvictorias(int v[], int p[])
{
   int promvic = 0;
   if(partida(partidas) != 0 && victorias(victoria) != 0)
   {
   	promvic = partida(partidas) / victorias(victoria); //Cuenta cada letra que se digita
   }
   else
   	promvic = 0;
   return promvic;
}

//Función que determina el promedio de derrotas del jugador

float promderrotas(int d[], int p[])
{
   int promderr = 0;
   if(partida(partidas) != 0 && itsover(derrotas) != 0)
   {
   	promderr = itsover(derrotas) / partida(partidas); //Cuenta cada letra que se digita
   }
   else
   	promderr = 0;
   return promderr;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

//PROCEDIMIENTOS

//Procedimiento que crea una interfaz para jugar

void cuadroprincipal()
{
   horizontal(18,50,6); // Invocación de función para dibujar lineas horizontales #1
	horizontal(18,50,26); // Invocación de función para dibujar lineas horizontales #2
   vertical(7,25,18); // Invocación de función para dibujar lineas verticales #1
   vertical(7,25,50); // Invocación de función para dibujar lineas verticales #2
   esquina(18,6,201); // Invocación de función para dibujar esquina #1
   esquina(18,26,200); // Invocación de función para dibujar esquina #2
   esquina(50,6,187); // Invocación de función para dibujar esquina #3
   esquina(50,26,188); // Invocación de función para dibujar esquina #4
}

//Procedimiento que crea una interfaz para jugar

void cuadro()
{
   horizontal(2,78,3); // Invocación de función para dibujar lineas horizontales #1
   horizontal(2,78,7); // Invocación de función para dibujar lineas horizontales #2
	horizontal(2,78,30); // Invocación de función para dibujar lineas horizontales #3
   vertical(4,29,2); // Invocación de función para dibujar lineas verticales #1
   vertical(4,29,78); // Invocación de función para dibujar lineas verticales #2
   esquina(2,3,201); // Invocación de función para dibujar esquina #1
   esquina(2,30,200); // Invocación de función para dibujar esquina #2
   esquina(78,3,187); // Invocación de función para dibujar esquina #3
   esquina(78,30,188); // Invocación de función para dibujar esquina #4
}

//Lista predeterminada de palabras que se copian y guardan dentro de la matriz

void determinapalabras()
{
	strcpy(palabras[0],"SAPRISSA"); //Copia el contenido de una cadena de caracteres  a otra
   strcpy(palabras[1],"ALAJUELENSE");
   strcpy(palabras[2],"BOCAJR");
   strcpy(palabras[3],"RIVERPLATE");
   strcpy(palabras[4],"REALMADRID");
   strcpy(palabras[5],"BARCELONA");
   strcpy(palabras[6],"ATLETICODEMADRID");
   strcpy(palabras[7],"JUVENTUS");
	strcpy(palabras[8],"MILAN");
   strcpy(palabras[9],"INTERDEMILAN");
   strcpy(palabras[10],"LIVERPOOL");
   strcpy(palabras[11],"CHELSEA");
   strcpy(palabras[12],"ARSENAL");
   strcpy(palabras[13],"LAGALAXY");
   strcpy(palabras[14],"MANCHESTERUNITED");
   strcpy(palabras[15],"MANCHESTERCITY");
   strcpy(palabras[16],"AJAX");
   strcpy(palabras[17],"ROMA");
   strcpy(palabras[18],"NAPOLI");
   strcpy(palabras[19],"BAYERMUNCHEN");
   strcpy(palabras[20],"DOURTMUND");
   strcpy(palabras[21],"SEVILLA");
   strcpy(palabras[22],"LEICESTER");
   strcpy(palabras[23],"FIORENTINA");
   strcpy(palabras[24],"PARMA");
   strcpy(palabras[25],"HEREDIANO");
   strcpy(palabras[26],"CARTAGUITO");
   strcpy(palabras[27],"SANTOS");
   strcpy(palabras[28],"CHIVAS");
   strcpy(palabras[29],"TIGRES");
}

//Procedimiento que imprime los títulos del juego

void imprimetitulos()
{
   gotoxy(35,5);	printf("AHORCADO");
   gotoxy(15,11);	printf("A D I V I N A  L O S  E Q U I P O S  D E  S O C C E R");
	for(int i = 0; i < ABC;i++)//Ciclo que imprime las letras del abecedario
   {
   	gotoxy(i * 2 + 15,8); //Se multiplica el "i" * 2 para que las letras no queden pegadas
      printf("%c",65 + i); //Se imprimen los caracteres ASCII desde el 65 osea la "A" hasta la "Z"
	}
   gotoxy(65,5);	printf("PARTIDA #%d",partida(partidas));
   gotoxy(15,14);	printf("Introduzca una letra: ");
}

//Procedimiento que genera palabras aleatoriamente desde una lista preestablecida

void generapalabras()
{
	srand(time(0)); //Permite que cada vez que juguemos no se repita la misma palabra
   randomize();
   j = (rand()%30); //Genera una opción entre 0 y 28 que es el numero de campos que posee la matriz
	strcpy(palabra,palabras[j]); //Copia lo encontrado aleatoriamente en la matriz, por lo que hace alución a un campo específico de la misma
   largo = strlen(palabra); // "strlen" mide el largo o la longitud de la palabra
   for(int i = 1; i <= largo;i++) //Ciclo que imprime las rayitas
   {
   	gotoxy(15 + i * 4,19); // El "i * 4" determina el numero de espacios que hay entre cada rayita
      putchar(95); //Imprime el caracter 95 del código ASCII que sería la barra baja
   }
}

//Prtocedimiento que permite inglesar caracteres y los valida

void digitapalabra()
{
	do //Ciclo para que solo se pueda leer letras
   {
   	letra = toupper(getch()); //Si el usuario digita una letra en minúscula el "toupper" la transforma en mayúscula
   }while(!isalpha(letra)); // "!isalpha(letra)" solo dejará introducir letras, no permitirá introducir otros caracteres
   gotoxy(15,22);	printf("Letras digitadas: ");
   gotoxy(intento + 35,22);	printf("%c",letra);
   gotoxy(15,16); printf("Intento #%d de 20",intento + 1);
	}

//Procedimiento que compara las letras digitadas con la palabra en la matriz y determina si pertenece o no a ella

void comparapalabra()
{
	for(int i = 0; i <= largo; i++)  //Ciclo para comparar palabras
   {
   	if(letra == palabra[i])//Condicional si la letra digitada coincide con alguna de las letras en algun campo de la matriz
      {
      	gotoxy(19 + i * 4,19);	printf("%c",letra);
         respuesta[i] = letra; //Se guarda la letra digitada en el vector "respuesta"
      }
      compara = strcmp(palabra,respuesta); // strcmp compara el caracter introducido con el caracter generado a leatoriamente
      //strcmp arroja dos tipos de resultado según si se ha encontrado el caracter digitado en el vector "palabra":
      //0 = la letra si se encontro en el vector (resultado positivo)
      //1 = la letra no se encontro en el vector (resultado negativo)
      if(compara == 0) //Condicional si compara es positivo
      {
      	gotoxy(15,24);		printf("CORRECTO, ACERTASTE LA PALABRA!!!");
         system("color 2F"); //Si el usuario gana la pantalla se pondra en verde y blanco
      }
      if(compara == 1) //Condicional si compara es negativo
      {
      	gotoxy(25,23);	printf("Incorrecto :c");
      }
   }
   intento++;
}

//Procedimiento por si el usuario no adivina la palabra y pierde

void gameover()
{
	if(intento >= 20)
   {
      clreol();
      gotoxy(78,16);	putchar(186);
      system("color 4F");//Si el usuario pierde la pantalla se pondra en rojo y blanco
   	gotoxy(15,24);	printf("PERDISTE, LA PALABRA ERA: %s",palabra);
   }
}

void ahorcado()
{
		clrscr();
      intento = 0; //Inicializa la variable intento en 0 para que cada vez que el usuario entre en la opción 2 el número de intentos se reinicie
      system("Color 1F"); //Color azul y texto blanco
      cuadro();
      determinapalabras();
   	generapalabras();
   	do //Ciclo que controla la cantidad de intentos permitidos
   	{
      	imprimetitulos();
      	digitapalabra();
         comparapalabra();
   	}while(intento < 20 && compara != 0);
      gameover();
  		gotoxy(23,28);	printf("Presione TECLA para continuar...");
   	getch();
}

//Proceso de estadísticas

void estadisticas()
{
	clrscr();
   system("Color 1F"); //Color azul y texto blanco
   horizontal(10,70,3); // Invocación de función para dibujar lineas horizontales #1
   horizontal(10,70,7); // Invocación de función para dibujar lineas horizontales #2
	horizontal(10,70,40); // Invocación de función para dibujar lineas horizontales #3
   vertical(4,39,10); // Invocación de función para dibujar lineas verticales #1
   vertical(4,39,70); // Invocación de función para dibujar lineas verticales #3
   esquina(10,3,201); // Invocación de función para dibujar esquina #1
   esquina(10,40,200); // Invocación de función para dibujar esquina #2
   esquina(70,3,187); // Invocación de función para dibujar esquina #3
   esquina(70,40,188); // Invocación de función para dibujar esquina #4
   esquina(70,7,185); // Invocación de función para dibujar esquina #5
   esquina(10,7,204); // Invocación de función para dibujar esquina #6
	gotoxy(33,5); 	printf("ESTADISTICAS");
   gotoxy(25,9); 	printf("Partidas Jugadas         : %d",partida(partidas));
   gotoxy(25,10); printf("Partidas Ganadas         : %d",victorias(victoria));
   gotoxy(25,11); printf("Partidas Perdidas        : %d",itsover(derrotas));
   gotoxy(25,12); printf("Promedio de Victorias    : %.2f",promvictorias(victoria,partidas));
   gotoxy(25,13); printf("Promedio de Derrotas     : %.2f",promderrotas(derrotas,partidas));
   gotoxy(25,14); printf("Total de Letras Digitadas: ");

   gotoxy(20,23); system("pause");
}

//Procedimiento que imprime las palabras que pueden salir en el ahorcado

void palabrasadivinansa()
{
   clrscr();
	system("Color 1F"); //Color azul y texto blanco
   horizontal(10,70,3); // Invocación de función para dibujar lineas horizontales #1
   horizontal(10,70,7); // Invocación de función para dibujar lineas horizontales #2
	horizontal(10,70,40); // Invocación de función para dibujar lineas horizontales #3
   vertical(4,39,10); // Invocación de función para dibujar lineas verticales #1
   vertical(8,39,39); // Invocación de función para dibujar lineas verticales #2
   vertical(4,39,70); // Invocación de función para dibujar lineas verticales #3
   esquina(10,3,201); // Invocación de función para dibujar esquina #1
   esquina(10,40,200); // Invocación de función para dibujar esquina #2
   esquina(70,3,187); // Invocación de función para dibujar esquina #3
   esquina(70,40,188); // Invocación de función para dibujar esquina #4
   esquina(70,7,185); // Invocación de función para dibujar esquina #5
   esquina(10,7,204); // Invocación de función para dibujar esquina #6
   esquina(39,40,202); // Invocación de función para dibujar esquina #7
   esquina(39,7,203); // Invocación de función para dibujar esquina #8
	gotoxy(33,5); 	   printf("LAS PALABRAS");
   gotoxy(14,10); 	printf("1. SAPRISSA");
   gotoxy(14,12); 	printf("2. ALAJUELENCE");
   gotoxy(14,14); 	printf("3. BOCAJR");
   gotoxy(14,16); 	printf("4. RIVERPLATE");
   gotoxy(14,18); 	printf("5. REALMADRID");
   gotoxy(14,20); 	printf("6. BARCELONA");
   gotoxy(14,22); 	printf("7. ATLETICODEMADRID");
   gotoxy(14,24); 	printf("8. JUVENTUS");
   gotoxy(14,26); 	printf("9. MILAN");
   gotoxy(14,28); 	printf("10. INTERDEMILAN");
   gotoxy(14,30); 	printf("11. LIVERPOOL");
   gotoxy(14,32); 	printf("12. CHELSEA");
   gotoxy(14,34); 	printf("13. ARSENAL");
   gotoxy(14,36); 	printf("14. LAGALAXY");
   gotoxy(14,38); 	printf("15. MANCHESTERUNITED");
   gotoxy(42,10); 	printf("16. MANCHESTERCITY");
   gotoxy(42,12); 	printf("17. AJAX");
   gotoxy(42,14); 	printf("18. ROMA");
   gotoxy(42,16); 	printf("19. NAPOLI");
   gotoxy(42,18); 	printf("20. BAYERMUNCHEN");
   gotoxy(42,20); 	printf("21. DOURTMUND");
   gotoxy(42,22); 	printf("22. SEVILLA");
   gotoxy(42,24); 	printf("23. LEICESTER");
   gotoxy(42,26); 	printf("24. FIORENTINA");
   gotoxy(42,28); 	printf("25. PARMA");
   gotoxy(42,30); 	printf("26. HEREDIANO");
   gotoxy(42,32); 	printf("27. CARTAGUITO");
   gotoxy(42,34); 	printf("28. SANTOS");
   gotoxy(42,36); 	printf("29. CHIVAS");
   gotoxy(42,38); 	printf("30. TIGRES");
   gotoxy(22,41);		system("Pause");
   clrscr();
}

//Procedimiento que imprime las instrucciones del juego

void instrucciones()
{
   clrscr();
	system("Color 1F"); //Color azul y texto blanco
   horizontal(10,71,3); // Invocación de función para dibujar lineas horizontales #1
   horizontal(10,71,7); // Invocación de función para dibujar lineas horizontales #2
	horizontal(10,71,30); // Invocación de función para dibujar lineas horizontales #3
   vertical(4,29,10); // Invocación de función para dibujar lineas verticales #1
   vertical(4,29,71); // Invocación de función para dibujar lineas verticales #2
   esquina(10,3,201); // Invocación de función para dibujar esquina #1
   esquina(10,30,200); // Invocación de función para dibujar esquina #2
   esquina(71,3,187); // Invocación de función para dibujar esquina #3
   esquina(71,30,188); // Invocación de función para dibujar esquina #4
   esquina(71,7,185); // Invocación de función para dibujar esquina #5
   esquina(10,7,204); // Invocación de función para dibujar esquina #6

   gotoxy(35,5); 	   printf("INSTRUCCIONES");
   gotoxy(14,10); 	printf("1. El juego esta relacionado con equipos de soccer por ");
   gotoxy(17,11);		printf("lo que todas las palabras que  puedan  salir  seran ");
   gotoxy(17,12);		printf("sobre equipos de soccer.");
   gotoxy(14,14); 	printf("2. Usted tiene que digitar letras al azar hasta  poder ");
   gotoxy(17,15);		printf("rellenar todos los espacios en blanco que aparecen.");
   gotoxy(14,17); 	printf("3. Tendras 20 intentos para rellenar los espacios  que ");
   gotoxy(17,18);		printf("aparecen.");
   gotoxy(14,20); 	printf("4. Si llegas  a los 20 intentos y aun no has terminado ");
   gotoxy(17,21);		printf("de rellenar los espacios,  perderas   la   partida.");
   gotoxy(14,23); 	printf("5. Si   adivinaste  la  palabra  entonces  ganaste  la ");
   gotoxy(17,24);		printf("la partida y la pantalla cambiara su color a verde.");
   gotoxy(14,26); 	printf("6. Si pierdes se  va  a  revelar  la  palabra  que  no ");
   gotoxy(17,27);		printf("adivinaste y la pantalla cambiara su color a  rojo.");
   gotoxy(22,32);		system("Pause");
}

//Procedimiento de menu principal

void menuprincipal()
{
   SetConsoleTitle("AHORCADO"); // Cambia el nombre de la consola
   do
   {
   	clrscr();
      cuadroprincipal();
      system("Color 1F"); //Color azul y texto blanco
   	gotoxy(25,9);	printf("PRINCIPAL MENU");
   	gotoxy(25,12);	printf("1. Instrucciones");
      gotoxy(25,14);	printf("2. Jugar!");
      gotoxy(25,16);	printf("3. Estadisticas");
      gotoxy(25,18);	printf("4. Lista de Palabras");
      gotoxy(25,20);	printf("5. Salir");
   	gotoxy(25,23);	printf("Opcion a procesar: ");
      option = validarenteros(1,5,44,23); // Validación de las opciones disponibles del menu principal
   	switch(option)
   	{
   		case 1:
      	{
         	instrucciones();
      	}	break;
			case 2:
      	{
            ahorcado();
      	}	break;
         case 3:
      	{
         	estadisticas();
      	}	break;
         case 4:
      	{
            palabrasadivinansa();
            clrscr();
      	}	break;
      } // Termina el switch
   }while ((option >= 1) && (option < 5)); // Termina el ciclo do - while
}


//PROGRMA PRINICPAL

main()
{
	menuprincipal();
   return 0;
}