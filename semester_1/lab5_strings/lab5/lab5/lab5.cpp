//Найти в строке слова, написанные в формате CamelCase ("lowerCamelCase UpperCamelCase"),
// и заменить их на те же слова, но в формате snake_case ("lower_camel_case upper_camel_case").
// Всё остальное должно быть сохранено в исходном порядке и количестве.

#include <iostream>
#include <string>
int main()
{
    std::string delimeters;
    std::string str;

    std::cout << "enter delimeters";
    std::getline(std::cin,delimeters);
    std::cout << "enter string";
    std::getline(std::cin,str);

    int size = str.size();
    if (isupper(str[0])) {
        str[0] = std::tolower(str[0]);
    }
    for (int i = 1; i < size; i++) {
        if (isupper(str[i])) {
            str[i] = std::tolower(str[i]);
            if (delimeters.find(str[i-1]) == std::string::npos) {
                str.insert(i, "_");
                i++;
                size++;
            }
        }  
    }
    std::cout << str;

    return 0;
}
