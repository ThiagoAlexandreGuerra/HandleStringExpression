#include <iostream>
#include <string>
#include "HandleStringExpression.h"

using namespace std;

int main(){

    HandleStringExpression Test;
    string string_test="x^3-2x^2-5x+6" , Number_A="3" , Number_B="2" , character="K";
    int LowerLimit=0 , UpperLimit= string_test.size()-5 , position=50 , i=0;
    bool With_Automatic_Corrections=true;

    cout<<"HandleStringExpression tests_____________________________________________________________________: "<<endl;
    cout<<"| string test: "<<string_test <<endl;
    cout<<"| LowerLimit: "<<LowerLimit<<endl;
    cout<<"| UpperLimit: "<<UpperLimit<<endl;
    cout<<"| Number_A: "<<Number_A<<endl;
    cout<<"| Number_B: "<<Number_B<<endl;
    cout<<"| position: "<<position<<endl;
    cout<<"| i: "<<i<<endl;
    cout<<"| With_Automatic_Corrections: "<<With_Automatic_Corrections<<endl;
    cout<<"| Test.AddCharacter(string_test, position, M ): "<<Test.AddCharacter(string_test, position, "M" ).Add_result <<endl;
    cout<<"| Test.RemoveWhiteSpace(string_test): "<<Test.RemoveWhiteSpace(string_test).RemoveWhiteSpace_Result <<endl;
    cout<<"| Test.AddWhiteSpace(string_test): "<<Test.AddWhiteSpace(string_test).AddWhiteSpace_Result <<endl;
    cout<<"| Test.Function_or_Expression(string_test): "<<Test.Function_or_Expression(string_test).Function_or_Expression <<endl;
    cout<<"| Test.SplitString(string_test,LowerLimit,UpperLimit,With_Automatic_Corrections): "<<Test.SplitString(string_test,LowerLimit,UpperLimit,With_Automatic_Corrections).SplitString_Result <<endl;
    cout<<"| Test.verification(string_test): "<<Test.verification(string_test).Verification_Result <<endl;
    cout<<"| Test.String_Correction(string_test): "<<Test.String_Correction(string_test).Correction_Result <<endl;
    cout<<"| Test.OperationOfNumbersInStringType(Number_A,'*',Number_B): "<<Test.OperationOfNumbersInStringType(Number_A,'*',Number_B).OperationWithString_Number_Result <<endl;
    cout<<"| Test.WhoAreInString(string_test): "<<Test.WhoAreInString(string_test).WhoAreInString_Result.Amount_Numbers <<endl;
    cout<<"| Test.FindWhateverSing(string_test,i, {'+'}): "<<Test.FindWhateverSing(string_test,i, {'+'}).FindWS_FoundedSing<<endl;
    cout<<"|________________________________________________________________________________________________||"<<endl;

    return 0;
}