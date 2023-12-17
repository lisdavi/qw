#include "file_reader.h"
#include "tele_cons.h"
#include "const.h"
#include <fstream>
#include <cstring>



date convert_date(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
};

void read(const char* file_name, phone_call* array[], int& size)
{

    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            phone_call* item = new phone_call;
            file >> item->phone_number;
            file >> tmp_buffer;
            item->call_date = convert_date(tmp_buffer);
            file >> tmp_buffer;
            file >> item->call_time;
            file >> tmp_buffer;
            file >> item->tariff;
            file >> item->cost;
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}



