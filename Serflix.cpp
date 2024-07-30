//Serflix  
 
#include <iostream>   //libreria estandar
#include <string.h>   //Libreria que nos permite usar funciones especificas de cadenas
#include <cstdlib>   //Libreria para funcion Random
#include <ctime>     //Sincroniza el tiempo de la funcion srandom con el tiempo de la pc 

using namespace std;

//Subprogramas 

void Carga_de_datos(string series[50],int temporadas[10][15][50]);
//Carga las visualizaciones manualmente.

void CargaAutomatica(string series[50],int temporadas[10][15][50]);
//Carga las visulizaciones automaticamente.

void MasVistos(string series[50],int temporadas[10][15][50]);
//Busca el capitulo con mayor visualizaciones.

void MenosVistos(string series[50],int temporadas[10][15][50]);
//Busca el capitulo con menor visualizaciones.

int obtener_indice(string nombre_serie, string series[50]);
// Devuelve el indice de la serie con el nombre ingresado.

void MostrarSeries(string series[50]);
//Muestra las series por pantalla 

//Programa principal
int main(){                                                              
	string series[50];
	string advertencia = ""; //Declara la cadena string vacia 
	int temporadas[10][15][50];
	int opcion_elegida;
	bool datos_cargados = false;

	while(true){
            /*
            OPCION DE MENU PRINCIPAL:
            como aun no se cargaron series, no se da la opcion de mostrar datos.
            */
            system("CLS");
            cout<<"\t.: Serflix :."<<endl<<endl<<endl;
       	    cout<<"\t -- M E N U --"<<endl<<endl;
            cout<<"1. Cargar datos manualmente"<<endl;
            cout<<"2. Cargar datos automaticamente"<<endl;
            cout<<"3. Mostrar series cargadas"<<endl;
            cout<<"4. Mostrar los mejores capitulos [Por temporada]"<<endl;
            cout<<"5. Mostrar los peores capitulos  [Por temporada]"<<endl;
            cout<<"6. Salir"<<endl<<endl;
            cout<<advertencia<<endl<<endl;
            cout<<"Ingrese una opcion: ";cin>>opcion_elegida;

	        switch(opcion_elegida){ //Evalua la opcion elegida 
		        case 1:
		            Carga_de_datos(series,temporadas);
                    datos_cargados = true;
                    advertencia = "";
                    break;

	            case 2:
	                CargaAutomatica(series, temporadas);
	                datos_cargados = true;
                    advertencia = "";
                    break;

                case 3:
                    if (datos_cargados == true){
                        MostrarSeries(series);
                        advertencia = "";
                    }
                    else{
                        advertencia = "ADVERETNCIA: Primero debes cargar los datos!";
                    }
                    break;

                case 4:
                    if (datos_cargados == true){
                        MasVistos(series,temporadas);
                        advertencia = "";
                    }
                    else{
                        advertencia = "ADVERETNCIA: Primero debes cargar los datos!";
                    }
                    break;

                case 5:
                    if (datos_cargados == true){
                        MenosVistos(series,temporadas);
                        advertencia = "";
                    }
                    else{
                        advertencia = "ADVERETNCIA: Primero debes cargar los datos!.";
                    }
                    break;
                case 6:
                    exit(1);

                default:
                    advertencia = "ADVERETNCIA: La opcion ingresada es incorreta!";
                }
            system("CLS");
	}
}

int obtener_indice(string nombre_serie, string series[50]){
    /*
    Devuelve el índice de la serie ingresada.
    Si no encuentra ningún índice válido devuelve -1.
    */
    for(int i=0; i<50 ; i++){
        if(series[i] == nombre_serie){
            return i;
        }
    }
    return -1;
}


void CargaAutomatica(string series[50],int temporadas[10][15][50]){
   
	string series_default[50] = {"Dexter", "kidvscat", "BreakinBad", "HeyArnold", "LosSimpson", "RickAndMorty", "BreakingBad", "LaCasaDePapel", "JhonnyBravo", "CatDog", "TheTwilightZone", "YOU", "GameOfThrones", "TheWalkingDead", "LosSoprano", "TheWire", "MadMen", "Seinfeld", "BobEsponja", "StarTrek", "Cheers", "Louie", "Veep", "Deadwood","Friends", "ExpedienteX", "SesameStreet", "SouthPark", "Law&Order", "Lost", "TheShield", "Columbo", "Taxi", "Fargo", "SexAndTheCity", "HappyDays", "DowntonAbbey", "Transparent", "MrShow", "Girls", "InLivingColor", "TheFugitive", "Dallas", "TheJeffersons", "HouseOfCards", "TheRealWorld", "DoctorWho", "Homeland", "BroadCity", "Gunsmoke"};
	int series_generadas;
	int vistas_random;
	char estadisticas;
    srand(time(0));

	system("CLS");
    cout<<"\t\t .: Carga de datos automatica :.";
    cout<<"\n\nIngrese la cantidad de series a generar [50 Max]: ";
    cin>>series_generadas;
    cout<<"\nMostrar estadisicas (Y/N): ";
    cin>>estadisticas;

	for(int s=0;s<50;s++){
        system("CLS");
        cout<<"\t\t .: Carga de datos automatica :.\n\n";
     	for(int t=0; t < 15; t++){
     		for(int c=0;c < 10;c++){

     		    //Carga visualizaciones
	    	    if (s < series_generadas){
                    series[s] = series_default[s];
                    vistas_random = rand() % 999 + 1;
                    temporadas[c][t][s] = vistas_random;
                    
                    if (estadisticas == 'Y' || estadisticas == 'y'){
                     cout<<"\nSerie ["<<s+1<<"] Temporada ["<<t+1<<"] Capitulo ["<<c+1<<"]: " << vistas_random << " vistas." << endl;
                    }
	    	    }else{
                    temporadas[c][t][s] = -1;
	    	    }
			}
        }
        
        if (s < series_generadas && (estadisticas == 'Y' || estadisticas == 'y') ){
            system("PAUSE");
        }
        else{
            cout<<"\n\nCargando...";
        }
    }
}


void Carga_de_datos(string series[50],int temporadas[10][15][50]){
	char continuar_cargando;

	system("CLS");

	//Carga de las series
	for(int s=0;s<50;s++){

        cout<<"Digite las series a continuacion (Max 50) [Ingrese X como nombre serie para salir] "<<endl;
		cout<<"\nSeries Cargadas: "<<s<<endl;

		cout<<"\nSerie "<<s+1<<": ";
		cin>>series[s];

		if(series[s] == "x" || series[s] == "X"){
            series[s] = "";
	    	break;
		}

		//Carga de las temporadas y capitulos
     	for(int t=0; t < 15; t++){

            cout<<"\n[Ingrese -1 para pasar a otra temporada]\n"<<endl;

     		for(int c=0;c < 10;c++){

     		    //Carga visualizaciones
	    	    cout<<"Cantidad de visualizaciones del temporada ["<<t+1<<"] capitulo ["<<c+1<<"]: ";
	    	    cin>>temporadas[c][t][s];


	    	    //Si el usuario ingrea -1:
	    	    if(temporadas[c][t][s] == -1){
                    for (int i = c; i < 10; i++){
                        //Iguala a -1 los capítulos no cargados
                        temporadas[i][t][s] = -1;
                    }
					break;
				}
            }
            
           //Repite hasta que se digite alguna de las opciones establecidas
           while(true){
 	    	    cout<<"\nContinuar cargando temporadas? [Y/N]: ";cin>>continuar_cargando;
 	    	
	    	    if(continuar_cargando == 'n' || continuar_cargando == 'N' || continuar_cargando == 'y' || continuar_cargando == 'Y'){
			    	break;
		    	}
	       }	    
		   
		   if(continuar_cargando== 'N' || continuar_cargando == 'n'){
                for(int j = t+1; j < 15; j++){
        	        //Iguala a -1 los capítulos de las temporadas no cargadas
				    for (int c = 0; c < 10; c++){
                        temporadas[c][j][s] = -1;
                    }
               }
				break;   	         	
			}
       }
    	system("CLS");
	}
}

void MasVistos(string series[50], int temporadas[10][15][50]){
	int cap_mas_visto;      // Numero de vistas del capitulo mas famoso.
	int s;                  // Indice de la serie.
    string serie;           // Nombrea de la serie.
    string advertencia;     // Contiene la advertencia.

    while(true){
        system("CLS");
        cout<<"\t.: CAPITULOS MAS VISTOS POR TEMPORADA :.\n";
        cout<<"\nOpciones: [Ingrese X para salir]\n\n";
        cout<<advertencia<<endl;
        cout<<"\nIngrese el nombre de la serie: ";
        cin>>serie;

        if (serie == "X" || serie == "x"){
            break;
        }

        s = obtener_indice(serie, series);
		
        if (s == -1){
            advertencia = "ADVERTENCIA: La serie ingresada es inexistente!";
        }
        else{
            advertencia = "";
            for(int t=0; t<15; t++){
                cap_mas_visto = 0;

                if(temporadas[0][t][s] == -1){
                    break;
                }

                for(int c=0; c<10; c++){
                    if(temporadas[c][t][s] > cap_mas_visto){
                        cap_mas_visto = temporadas[c][t][s];
                        }
                }
                    cout<<"\n-La mayor cantidad de visualizaciones es "<<cap_mas_visto<< " de la temporada "<<t+1<<"\n";
                }
            cout<<"\n\n";
            system("PAUSE");
        }
        }
   }


void MenosVistos(string series[50],int temporadas[10][15][50]){
	int cap_menos_visto;      // Numero de vistas del capitulo menos famoso.
	int s;                  // Indice de la serie.
    string serie;           // Nombre de la serie.
    string advertencia;     // Contiene la advertencia.

    while(true){
        system("CLS");
        cout<<"\t.: CAPITULOS MENOS VISTOS POR TEMPORADA :.\n";
        cout<<"\nOpciones: [Ingrese X para salir]\n\n";
        cout<<advertencia<<endl;
        cout<<"\nIngrese el nombre de la serie: ";
        cin>>serie;

        if (serie == "X" || serie == "x"){
            break;
        }

        s = obtener_indice(serie, series);

        if (s == -1){
            advertencia = "ADVERTENCIA: La serie ingresada es inexistente!";
        }

        for(int t=0; t<15; t++){
            cap_menos_visto=99999999;

            if(temporadas[0][t][s] == -1 || s == -1){
                break;
            }

            for(int c=0; c<10; c++){
                if((temporadas[c][t][s] < cap_menos_visto) && ((temporadas[c][t][s] > -1)) ){
                    cap_menos_visto = temporadas[c][t][s];
                    }
            }

            cout<<"\n-La menor cantidad de visualizaciones es "<<cap_menos_visto<< " de la temporada "<<t+1<<"\n";

        }
        cout<<"\n\n";
        system("PAUSE");
   }
}

void MostrarSeries(string series[50]){
    int longitud_max = 20;
    string serie_local;
    system("CLS");
    cout<<"\t\tSERIES CARGADAS:\n\n";

    for (int i = 0; i<50; i++){
        serie_local = series[i];
		
        if(serie_local == ""){
            break;
        }
		
        while (serie_local.length() < longitud_max){
            serie_local += " ";
        }
        cout<<"- "<<serie_local<<"\t\t\t\t\t";
		
		if ((i+1) % 2 == 0){ //ordena por columna
			cout<<"\n";
		}
		
    }
    cout<<"\n\n";
    system("PAUSE");
 }
