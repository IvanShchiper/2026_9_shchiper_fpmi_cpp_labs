#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//
#include <chrono>
#include <ctime>
#include <iomanip>
#include <locale>

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format
        ? std::put_time(std::gmtime(&time), "%x %X")
        : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}
//
std::string CamelCase_To_snake_case(std::string string, std::string delimeters) {
    
    int size = string.size();
    if (isupper(string[0])) {
        string[0] = std::tolower(string[0]);
    }
    for (int i = 1; i < size; i++) {
        if (isupper(string[i])) {
            string[i] = std::tolower(string[i]);
            if (delimeters.find(string[i - 1]) == std::string::npos) {
                string.insert(i, "_");
                i++;
                size++;
            }
        }
    }
    return string;
}

bool FileIsEmpty(std::ifstream& fin) {
    return fin.peek() == EOF;
}

//читать с файла
std::vector<std::string> ReadFromFile(std::string filename, std::ofstream& fout_log) {
    std::vector<std::string> sentenses;
    std::ifstream fin{filename};
    fout_log << FormatTime(Now(), false) << '|' << " opening file " << filename <<"\n";
    if (!fin.is_open()) {
        throw "Error, file is not open";
    }
    fout_log << FormatTime(Now(), false) << '|' << " file "<< filename <<" has been opened successfully \n";
    if (FileIsEmpty(fin)) {
        throw "Error, file is empty";
    }
    std::string x;
    fout_log << FormatTime(Now(), false) << '|' << " reading lines from " << filename<< "\n";
    while (std::getline(fin,x)) {
        sentenses.push_back(x);
    }
    for (int i = 0;i < sentenses.size();i++) {
        fout_log << FormatTime(Now(), false) << '|' << " got line : " << sentenses[i] << "\n";
    }
    return sentenses;
}

//записать в файл
void WriteToFile(std::string filename, std::vector<std::string> sentenses, std::ofstream& fout_log){
    std::ofstream fout{ filename };
    fout_log << FormatTime(Now(), false) << '|' << " opening file " << filename << "\n";
    if (!fout.is_open()) {
        throw "Error, file is not open";
    }
    fout_log << FormatTime(Now(), false) << '|' << " file " << filename << " has been opened successfully \n";
    for (std::string x : sentenses) {
        fout << x << "\n";
    }
    fout_log << FormatTime(Now(), false) << '|' << " writing lines to "<< filename <<"\n";
}

int main()
{
    std::string delimeters = " ,>.?/!()";
    std::string input_file = "input.txt";
    std::string output_file = "output1.txt";
    std::string log_file = "log.txt";
    std::ofstream fout_log{ log_file };
    try {
        //
        std::cout.imbue(std::locale("ru_RU.UTF-8"));
        //std::out << FormatTime(Now(), false) << '|';
        //
        std::vector<std::string> v = ReadFromFile(input_file, fout_log);
        fout_log << FormatTime(Now(), false) << '|' << " making CamelCase to snake_case" << "\n";
        for (std::string& x : v) {
            x = CamelCase_To_snake_case(x, delimeters);
        }
        WriteToFile(output_file, v, fout_log);
        
        fout_log << FormatTime(Now(), false) << "| new strings are written to " << output_file << "\n";
        fout_log << FormatTime(Now(), false) << '|' << " progam has ended with code 0 \n";
        std::cout << "Programm works correctly";
    }
    catch (const char* error) {
        std::cout << error;
    }


    return 0;
}

