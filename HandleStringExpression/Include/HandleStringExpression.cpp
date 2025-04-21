#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <sstream>
#include <initializer_list>
#include <vector>

#include "HandleStringExpression.h"

using namespace std;



HandleStringExpression::HandleStringExpression()
{
   RESULT.reset();
   AmountOfErros=0;
   ErrosInString="";
}
HandleStringExpression::~HandleStringExpression()
{
}

HandleStringExpression_Result HandleStringExpression::AddCharacter(string S,int position , string character){
    string copy_1="" , copy_2="";
    for(int i=0 ; i<S.size() ; i++){if(i<=position){copy_1+=S[i];}else{copy_2+=S[i];}}
    S=copy_1+character+copy_2;
    RESULT.Add_result=S;
    return RESULT;
}

HandleStringExpression_Result HandleStringExpression::AddWhiteSpace(string S){
    
    for(int i=0; i<S.size() ; i++){if(S[i]!=' '&&S[i+1]!=' '){S=AddCharacter(S,i," ").Add_result;}}
    RESULT.AddWhiteSpace_Result=S;
    return RESULT;
};
HandleStringExpression_Result HandleStringExpression::RemoveWhiteSpace(string S){
    string copy_1;
    for(int i=0 ; i<S.size() ; i++){if(S[i]!=' '){copy_1+=S[i];}}
    RESULT.RemoveWhiteSpace_Result=copy_1;
    return RESULT;
};


HandleStringExpression_Result HandleStringExpression::FindWhateverSing(string S,int currentIndex, initializer_list<char> IgnoreSing){

    bool ignorePlus=false, ignoreMinus=false , ignoreDiv=false , ignoreMult=false , ignoreExpo=false , ignoreFat=false;
    bool ignoreParenOpen=false,  ignoreParenClouser=false, ignoreBracketsOpen=false, ignoreBracketsClouser=false , ignoreCurlyBraOpen=false;
    bool ignoreCurlyBraClouser=false;
    
    for (char IgnoreS : IgnoreSing){
        if(IgnoreS=='+'){ignorePlus =true;}
        if(IgnoreS=='-'){ignoreMinus =true;}
        if(IgnoreS=='/'){ignoreDiv =true;}
        if(IgnoreS=='!'){ignoreFat =true;}
        if(IgnoreS=='*'){ignoreMult =true;}
        if(IgnoreS=='^'){ignoreExpo =true;}
        if(IgnoreS=='('){ignoreParenOpen =true;}
        if(IgnoreS==')'){ignoreParenClouser =true;}
        if(IgnoreS=='['){ignoreBracketsOpen =true;}
        if(IgnoreS==']'){ignoreBracketsClouser =true;}
        if(IgnoreS=='{'){ignoreCurlyBraOpen =true;}
        if(IgnoreS=='}'){ignoreCurlyBraClouser =true;}
    }

    int i= (currentIndex+1)>S.size()?currentIndex:currentIndex+1;
    for(i; i<S.size(); i++){

        if((S[i]=='+')&&(!ignorePlus)){return FWS_AuxReturn(i , true , S);}
        if((S[i]=='-')&&(!ignoreMinus)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='/')&&(!ignoreDiv)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='!')&&(!ignoreFat)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='*')&&(!ignoreMult)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='^')&&(!ignoreExpo)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='(')&&(!ignoreParenOpen)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]==')')&&(!ignoreParenClouser)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='[')&&(!ignoreBracketsOpen)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]==']')&&(!ignoreBracketsClouser)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='{')&&(!ignoreCurlyBraOpen)){return FWS_AuxReturn(i ,true , S );}
        if((S[i]=='}')&&(!ignoreCurlyBraClouser)){return FWS_AuxReturn(i ,true , S );}
        
        if(isalpha(S[i])||isdigit(S[i])){RESULT.FindWS_FoundedSing="none";RESULT.FindWS_SingPosition=i;break;}

    }
    return RESULT;
}

HandleStringExpression_Result HandleStringExpression::FWS_AuxReturn(int i, bool b , string s){
        RESULT.FindWS_IfSingFounded=b;
        RESULT.FindWS_FoundedSing=s[i];
        RESULT.FindWS_SingPosition=i;
        return RESULT;
}


HandleStringExpression_Result HandleStringExpression::OperationOfNumbersInStringType(string A , char op,string B ){
    
    bool ifAOk=false , ifBOk=false;
    float aux=1 , aux2=1 ;
    double multipliesResult=0, sumResult=0 , eubtractionResult=0 , divisionResult=0, exponetialResult=0, subtractionResult=0;
    if(DoExistNumberInString(A)){ifAOk=true;}
    if(DoExistNumberInString(B)){ifBOk=true;}

    if(ifAOk && ifBOk){
        
        try {
            stringstream AA (A);
            stringstream BB (B);

            AA>>aux;
            BB>>aux2;

            if(op=='*'){multipliesResult=aux*aux2;RESULT.OperationWithString_Number_Result=multipliesResult;RESULT.OperationWithString_String_Result=to_string(multipliesResult);}
            if(op=='/'){divisionResult=aux/aux2;RESULT.OperationWithString_Number_Result=divisionResult;RESULT.OperationWithString_String_Result=to_string(divisionResult);}
            if(op=='+'){sumResult=aux+aux2;RESULT.OperationWithString_Number_Result=sumResult;RESULT.OperationWithString_String_Result=to_string(sumResult);}
            if(op=='-'){subtractionResult=aux;RESULT.OperationWithString_Number_Result=subtractionResult;RESULT.OperationWithString_String_Result=to_string(subtractionResult);}
            if(op=='^'){exponetialResult=pow(aux,aux2);RESULT.OperationWithString_Number_Result=exponetialResult; RESULT.OperationWithString_String_Result=to_string(exponetialResult);}

            return RESULT;
            
        } catch (const std::invalid_argument&) {
            cerr << "Erro: '" << A <<" ou " << B <<"' não é um número válido.\n";
            return RESULT;
        }

    }
    return RESULT;
}
HandleStringExpression_Result HandleStringExpression::verification(string S){
    int consecutive_plus_sing=0, consecutive_mult_sing=0 ,consecutive_div_sing=0,consecutive_expoente_sing=0, consecutive_dot_sing=0;
    int consecutive_minus_sing=0 , consecutive_percent_sing=0 , consecutive_fatorial_sing=0 , amontOfcontentes=0 , Number=0 ;
    
    bool firstLetter=true , checkDivision=false, WhiteSpaceBetweenTwoNumber=false;
    string letter="";

    for(int i=0 ; i<S.size(); i++){
        if(isdigit(S[i])||isalpha(S[i])){
            if(checkDivision){if(S[i]=='0'){ShowErrors("Division for zero");}; checkDivision=false;}
            consecutive_plus_sing=0;
            consecutive_mult_sing=0;
            consecutive_div_sing=0;
            consecutive_expoente_sing=0;
            consecutive_dot_sing=0;
            consecutive_minus_sing=0;
            consecutive_percent_sing=0;
            consecutive_fatorial_sing=0; 
            if(isdigit(S[i]))Number++;
            if(Number>=2){ShowErrors("There_is_a_number_without_operator");}
        }

        if(S[i]=='+'){ consecutive_plus_sing++;Number=0;if(consecutive_plus_sing==2){ShowErrors("consecutive_plus_sing");}}
        if(S[i]=='-'){ consecutive_minus_sing++;Number=0;if(consecutive_minus_sing==2){ShowErrors("consecutive_minus_sing");}}
        if(S[i]=='/'){ consecutive_div_sing++;Number=0;if(consecutive_div_sing==2){ShowErrors("consecutive_div_sing");}; checkDivision=true;}
        if(S[i]=='*'){ consecutive_mult_sing++;Number=0;if(consecutive_mult_sing==2){ShowErrors("consecutive_mult_sing");}}
        if(S[i]=='!'){ consecutive_fatorial_sing++;Number=0;if(consecutive_fatorial_sing==2){ShowErrors("consecutive_fatorial_sing");}}
        if(S[i]=='%'){ consecutive_percent_sing++;Number=0;if(consecutive_percent_sing==2){ShowErrors("consecutive_percent_sing");}}
        if(S[i]=='^'){ consecutive_expoente_sing++;Number=0;if(consecutive_expoente_sing==2){ShowErrors("consecutive_expoente_sing");}}
        if(S[i]=='.'){ consecutive_dot_sing++;Number=0;if(consecutive_dot_sing==2){ShowErrors("consecutive_dot_sing");}}

        if((S[i]=='(')||(S[i]=='[')||(S[i]=='{')){
            consecutive_plus_sing=0;
            consecutive_mult_sing=0;
            amontOfcontentes++;
            Number=0;
        }
        if((S[i]==')')||(S[i]==']')||(S[i]=='}')){
            if(consecutive_plus_sing+consecutive_mult_sing+consecutive_div_sing+consecutive_expoente_sing+consecutive_dot_sing+consecutive_minus_sing>=1){ShowErrors("Lonely_Sing_In_Interval");}
            amontOfcontentes++;
            Number=0;
        }
            
        if( ((consecutive_plus_sing + consecutive_minus_sing +consecutive_div_sing ) ==2) && (!checkDivision) ){ShowErrors("Consecutive_Whatever_sing");}
        if( (consecutive_mult_sing+consecutive_div_sing+consecutive_dot_sing+consecutive_expoente_sing+consecutive_percent_sing+consecutive_fatorial_sing)==2){ShowErrors("Consecutive_Whatever_sing");}    
        if(isalpha(S[i])){
            if(firstLetter){
                letter=S[i];
                firstLetter=false;
            }
            if(S[i]!=letter[0]){
                ShowErrors("Diferent Letters");
            }
        }
    }

    if( consecutive_plus_sing!=0
        ||consecutive_mult_sing!=0
        ||consecutive_div_sing!=0
        ||consecutive_expoente_sing!=0
        ||consecutive_dot_sing!=0
        ||consecutive_minus_sing!=0
        ||consecutive_percent_sing>1
        ||consecutive_fatorial_sing!=0 ){

            ShowErrors("Lonely sing of operation");
        }

    if(amontOfcontentes%2!=0){
        ShowErrors("Lonely paretheses , brackets or braces");
    }

    if(AmountOfErros!=0){Format_ShowErrors();}else{RESULT.Verification_IfFindErros=false;}
    return RESULT;
};

void HandleStringExpression::ShowErrors(string S){
    oss << "\t\t{ \"Error\": \"" << S << "\" },\n";
    AmountOfErros++;
}

void HandleStringExpression::Format_ShowErrors(){
    ErrosInString = oss.str();

    if (!ErrosInString.empty()) {
        ErrosInString.erase(ErrosInString.find_last_of(','), 1);
    }

    ErrosInString = "{\n\t\"ERRO_MSN\": [\n" + ErrosInString + "\n\t],\n";
    ErrosInString += "\t\"TYPE\" : [\n\t\t { \"t\": \"Error\" } \n\t],\n";
    ErrosInString += "\t\"AmountOfErros\": [\n\t\t{ \"a\": " + to_string(AmountOfErros) + " }\n\t]\n}";

    RESULT.Verification_IfFindErros=true;
    RESULT.Verification_Result=ErrosInString;
}

HandleStringExpression_Result HandleStringExpression::Function_or_Expression(string S){
    for(int i=0 ; i<S.size(); i++){if(isalpha(S[i])){RESULT.Function_or_Expression=2;return RESULT;}}
    RESULT.Function_or_Expression=1;
    return RESULT;
};

HandleStringExpression_Result HandleStringExpression::SplitString(string S, int LowerLimit , int UpperLimit , bool With_Automatic_Corrections) {
    int StringSize = S.size();
    for (int i = 0; i < LowerLimit; i++) {S[i] = ' ';}
    for (int i = StringSize - 1; i > UpperLimit; i--) {S[i] = ' ';}

    RESULT.SplitString_Result=S; 

    if(With_Automatic_Corrections){RESULT.SplitString_Result= String_Correction(RESULT.SplitString_Result).Correction_Result;}
    return RESULT;
}

HandleStringExpression_Result HandleStringExpression::String_Correction(string S){

    
    bool lonelySing=false, verification=false, findDigit=false;

    int positioLonelySing=-1;

    for(int i=0 ; i<S.size() ; i++){
        if(isdigit(S[i])){findDigit=true;}
        if((S[i]=='+'||S[i]=='-'||S[i]=='*') && !verification){positioLonelySing=i;verification=true;i++;}
        if(isdigit(S[i])){verification=false;positioLonelySing=-1;}
        if(verification && (i==S.size()-1)){S[positioLonelySing]=' ';}
        if(S[i]=='/' && !findDigit){S[i]=' ';}
    }

    RESULT.Correction_Result=S;
    return RESULT;
}

HandleStringExpression_Result HandleStringExpression::WhoAreInString(string S){

    bool findDigit=false;
    for(int i=0 ; i<S.size(); i++){
        if(S[i]=='+'){RESULT.WhoAreInString_Result.Amount_plusSing++;}
        if(S[i]=='-'){RESULT.WhoAreInString_Result.Amount_MinusSing++;}
        if(S[i]=='*'){RESULT.WhoAreInString_Result.Amount_MutipicationSing++;}
        if(S[i]=='/'){RESULT.WhoAreInString_Result.Amount_DivisionSing++;}
        if(S[i]=='^'){RESULT.WhoAreInString_Result.Amount_ExpoentSing++;}
        if(S[i]=='.'){RESULT.WhoAreInString_Result.Amount_DotSing++;}
        if(S[i]=='!'){RESULT.WhoAreInString_Result.Amount_FatorialSing++;}
        if(S[i]=='%'){RESULT.WhoAreInString_Result.Amount_PercentSing++;}
        if(S[i]=='('||S[i]==')'){RESULT.WhoAreInString_Result.Amount_Parentheses++;}
        if(S[i]=='['||S[i]==']'){RESULT.WhoAreInString_Result.Amount_Brackets++;}
        if(S[i]=='{'||S[i]=='}'){RESULT.WhoAreInString_Result.Amount_CurlyBrackets++;}
        if((S[i]=='{'||S[i]=='}') || (S[i]=='['||S[i]==']') || (S[i]=='{'||S[i]=='}') ){RESULT.WhoAreInString_Result.Amount_ParenthesesBracketsAndCurlyBrackets++;}
        if(isdigit(S[i])){findDigit=true;}
        if(findDigit && !isdigit(S[i])){RESULT.WhoAreInString_Result.Amount_Numbers++;findDigit=false;}
        if(isalpha(S[i])){RESULT.WhoAreInString_Result.Amount_Letters++;}

    }

    return RESULT;
};
bool HandleStringExpression::DoExistNumberInString(string S){

    if(S.empty()){return false;}
    
    for(int k=0 ; k<S.size() ; k++){
        if(isdigit(S[k])){return true;}
    }
    return false;
}