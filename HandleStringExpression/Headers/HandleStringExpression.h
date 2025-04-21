#ifndef HANDLESTRINGEXPRESSION_H
#define HANDLESTRINGEXPRESSION_H

/*  ENGLISH
    This is a collection of functions used to handle mathematical expressions represented as strings.
    Although still under development, all features will be available soon.

    Available functions:

    - AddCharacter(string, position):
        Inserts a character or string at the given position. If the position exceeds the string size, it appends to the end.

    - FindWhateverSing(string, start_position, {'restrictions'}):
        Finds the next mathematical symbol to the right, based on the given restrictions.

    - verification(string):
        Analyzes a mathematical expression and returns any errors found in JSON format.

    - Function_or_Expression(string):
        Determines if the input is a simple mathematical operation (returns 1) or a function (returns 2).

    - SplitString(string, lower_limit, upper_limit, auto_correction):
        Extracts a substring within the specified range. If `auto_correction` is true, invalid symbols at the borders are removed.

    - String_Correction(string):
        Fixes the expression by correcting duplicated or missing symbols.

    - AddWhiteSpace(string):
        Adds white spaces where needed.

    - RemoveWhiteSpace(string):
        Removes all white spaces from the expression.

    - OperationOfNumbersInStringType(string number1, char operator, string number2):
        Performs the operation and returns the result as both `string` and `double`.

    - WhoAreInString(string):
        Returns the number of letters, numbers, and symbols in the string.

    - DoExistNumberInString(string):
        Checks if the string contains valid numbers, even if padded with empty characters.
*/

//************************************************************************************************************************************************ */
//************************************************************************************************************************************************ */

/*  PORTUGUÊS
    Esta é uma coleção de funções utilizadas para manipular expressões matemáticas representadas como strings.
    Embora ainda esteja em desenvolvimento, em breve todas as funcionalidades estarão disponíveis.

    Funções disponíveis:

    - AddCharacter(string, posição):
        Insere um caractere ou string na posição indicada. Caso a posição exceda o tamanho da string, o conteúdo será adicionado ao final.

    - FindWhateverSing(string, posição_inicial, {'restrições'}):
        Localiza o próximo símbolo matemático à direita, obedecendo a restrições especificadas.

    - verification(string):
        Analisa uma expressão matemática e retorna, em formato JSON, os erros encontrados.

    - Function_or_Expression(string):
        Informa se a entrada representa uma operação matemática simples (retorna 1) ou uma função (retorna 2).

    - SplitString(string, limite_inferior, limite_superior, correção_automática):
        Recorta a string conforme os limites indicados. Se correção_automática for verdadeira, remove sinais inválidos nas extremidades.

    - String_Correction(string):
        Corrige a expressão, ajustando sinais duplicados ou ausentes.

    - AddWhiteSpace(string):
        Adiciona espaços em branco onde for necessário.

    - RemoveWhiteSpace(string):
        Remove todos os espaços em branco da expressão.

    - OperationOfNumbersInStringType(string número1, char operador, string número2):
        Realiza a operação matemática e retorna o resultado como `string` e `double`.

    - WhoAreInString(string):
        Informa a quantidade de letras, números e operadores presentes na string.

    - DoExistNumberInString(string):
        Verifica se há números válidos na string, mesmo que contenha caracteres vazios.
*/

//************************************************************************************************************************************************ */
//************************************************************************************************************************************************ */


/*  ESPAÑOL
    Esta es una colección de funciones utilizadas para manejar expresiones matemáticas representadas como cadenas.
    Aunque aún está en desarrollo, todas las funcionalidades estarán disponibles pronto.

    Funciones disponibles:

    - AddCharacter(string, posición):
        Inserta un carácter o cadena en la posición indicada. Si la posición excede el tamaño, se añade al final.

    - FindWhateverSing(string, posición_inicial, {'restricciones'}):
        Encuentra el próximo símbolo matemático a la derecha, respetando las restricciones.

    - verification(string):
        Analiza una expresión matemática y devuelve los errores encontrados en formato JSON.

    - Function_or_Expression(string):
        Determina si la entrada es una operación matemática simple (devuelve 1) o una función (devuelve 2).

    - SplitString(string, límite_inferior, límite_superior, corrección_automática):
        Extrae una subcadena en el rango especificado. Si `corrección_automática` es verdadera, se eliminan símbolos inválidos en los bordes.

    - String_Correction(string):
        Corrige la expresión ajustando símbolos duplicados o faltantes.

    - AddWhiteSpace(string):
        Añade espacios donde sea necesario.

    - RemoveWhiteSpace(string):
        Elimina todos los espacios en blanco de la expresión.

    - OperationOfNumbersInStringType(string número1, char operador, string número2):
        Realiza la operación y devuelve el resultado como `string` y `double`.

    - WhoAreInString(string):
        Devuelve la cantidad de letras, números y símbolos presentes en la cadena.

    - DoExistNumberInString(string):
        Verifica si hay números válidos en la cadena, incluso si contiene caracteres vacíos.
*/


#include <string>
#include <iostream>
#include <initializer_list>
#include <cmath>
#include <sstream>


using namespace std;

struct WhoAreInString_ResultT{

    int Amount_plusSing;
    int Amount_MinusSing;
    int Amount_DivisionSing;
    int Amount_MutipicationSing;
    int Amount_ExpoentSing;
    int Amount_DotSing;
    int Amount_ParenthesesBracketsAndCurlyBrackets;
    int Amount_Parentheses;
    int Amount_Brackets;
    int Amount_CurlyBrackets;
    int Amount_Letters;
    int Amount_Numbers;
    int Amount_PercentSing;
    int Amount_FatorialSing;


    void reset(){
         Amount_plusSing=0;
         Amount_MinusSing=0;
         Amount_DivisionSing=0;
         Amount_MutipicationSing=0;
         Amount_ExpoentSing=0;
         Amount_DotSing=0;
         Amount_ParenthesesBracketsAndCurlyBrackets=0;
         Amount_Parentheses=0;
         Amount_Brackets=0;
         Amount_CurlyBrackets=0;
         Amount_Letters=0;
         Amount_Numbers=0;
         Amount_PercentSing=0;
         Amount_FatorialSing=0;
     
    }

};


struct HandleStringExpression_Result
{
    string Add_result;
    string FindWS_FoundedSing;
    int FindWS_SingPosition;
    bool FindWS_IfSingFounded;
    string Verification_Result;
    bool Verification_IfFindErros;
    int Function_or_Expression;
    string SplitString_Result;
    string Correction_Result;
    string AddWhiteSpace_Result;
    string RemoveWhiteSpace_Result;
    double OperationWithString_Number_Result;
    string OperationWithString_String_Result;
    WhoAreInString_ResultT WhoAreInString_Result;
    void reset() {
        Add_result = "";
        AddWhiteSpace_Result="";
        RemoveWhiteSpace_Result="";
        FindWS_FoundedSing = "";
        FindWS_SingPosition = -1;
        FindWS_IfSingFounded = false;
        OperationWithString_Number_Result=NAN;
        OperationWithString_String_Result="";
        Verification_Result = "";
        Verification_IfFindErros = false;
        Function_or_Expression = 0;
        WhoAreInString_Result.reset();
    }

};


class HandleStringExpression
{
    private:
        void ShowErrors(string S);
        void Format_ShowErrors();
        HandleStringExpression_Result FWS_AuxReturn(int i, bool b , string s);
        HandleStringExpression_Result RESULT;
        ostringstream oss;
        int AmountOfErros;
        string ErrosInString;
    public:
        HandleStringExpression_Result AddCharacter(string S,int position , string character);
        HandleStringExpression_Result FindWhateverSing(string S,int currentIndex, initializer_list<char> IgnoreSing);
        HandleStringExpression_Result verification(string S);
        HandleStringExpression_Result Function_or_Expression(string s);
        HandleStringExpression_Result SplitString(string S, int LowerLimit , int UpperLimit , bool With_Automatic_Corrections);
        HandleStringExpression_Result String_Correction(string S);
        HandleStringExpression_Result AddWhiteSpace(string S);
        HandleStringExpression_Result RemoveWhiteSpace(string S);
        HandleStringExpression_Result OperationOfNumbersInStringType(string A, char Operatorr, string B);
        HandleStringExpression_Result WhoAreInString(string S);
        bool DoExistNumberInString(string S);
        HandleStringExpression();
        ~HandleStringExpression();
};



#endif
