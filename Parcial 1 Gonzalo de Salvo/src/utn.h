#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
/// \fn int getValidInt(char[], char[])
/// \brief Valida un string de numeros y lo convierte a numero entero. En caso de no ser posible envia un mensaje de error
/// \param mensaje
/// \param error
/// \return El entero validado
int getValidInt(char mensaje[], char error[]);
/// \fn float getValidFloat(char[], char[])
/// \brief Valida un string de numeros y lo convierte a numero flotante. En caso de no ser posible envia un mensaje de error
/// \param mensaje
/// \param error
/// \return El flotante validado
float getValidFloat(char mensaje[], char error[]);
/// \fn int getInt(char[], int, int)
/// \brief Recibe un mensaje y dos intervalos de minimo y maximo para pedir un numero entero entre estos dos intervalos
/// \param mensaje
/// \param min
/// \param max
/// \return El numero ingresado en caso de ser posible, un mensaje de error en caso de no ser valido
int getInt(char mensaje[],int min,int max);
/// \fn float getFloat(char[], int, int)
/// \brief Recibe un mensaje y dos intervalos de minimo y maximo para pedir un numero flotante entre estos dos intervalos.
/// \param mensaje
/// \param min
/// \param max
/// \return El numero ingresado en caso de ser posible, un mensaje de error en caso de no ser valido
float getFloat(char mensaje[],int min,int max);
/// \fn void getString(char[], char[], int)
/// \brief Pide una cadena de string y la guarda luego de corregirla, tambien solicita el tamaño de la cadena a corregir.
/// \param mensaje
/// \param cadena
/// \param tam
void getString (char mensaje [], char cadena[],int tam);
/// \fn void corregirString(char[])
/// \brief Corrige la cadena recibida asignandole mayusculas al principio de la misma y poniendo en minusculas el resto de caracteres.
/// \param cadena
void corregirString(char cadena[]);
int StringAEntero(char cadena[], int* entero);
int ValidarStringComoEntero(char cadena[]);
int getValidCuit(char mensaje[], char error[],char cuit[]);
