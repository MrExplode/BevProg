#include "../std_lib_facilities.h"

// some funny
class UnsupportedGenderError
{
};

int main()
{
    //construct the letter by string concatenation instead of printing each line
    //this way we can avoid interrupting the content with prompts
    string letter = "Dear ";
    cout << "Enter the name of the person you want to write to: ";
    string first_name;
    cin >> first_name;
    letter += first_name + ",\n\n";
    letter += "\tHow are you? We haven't talked for a while now.\n";

    cout << "Enter an other friend's name: ";
    string friend_name;
    cin >> friend_name;
    letter += "\tHave you seen " + friend_name + " lately?\n";

    char friend_sex = 0;
    cout << "Is you friend male (m) or female (f)? ";
    cin >> friend_sex;
    if (friend_sex == 'm')
        letter += "\tIf you see " + friend_name + " please ask him to call me.\n";
    else if (friend_sex == 'f')
        letter += "\tIf you see " + friend_name + " please ask her to call me.\n";
    else
        throw UnsupportedGenderError();

    int age;
    cout << "Enter your friend's age: ";
    cin >> age;
    if (age <= 0 || age >= 110)
        simple_error("you're kidding!");
    letter += "\tI hear you just had a birthday and you are " + to_string(age) + " years old.\n";
    if (age < 12)
        letter += "\tNext year you will be " + to_string(age + 1) + ".\n";
    if (age == 17)
        letter += "\tNext year you will be able to vote.\n";
    if (age >= 70)
        letter += "\tI hope you are enjoying retirement.\n";

    letter += "\nYours sincerely,\n\n\nJános\n";

    //print the constructed letter
    cout << endl
         << letter;
}