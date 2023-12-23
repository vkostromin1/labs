#include <iostream>
#include <windows.h>
#include <vector>


#pragma pack(push,1)
using namespace std;

struct headvol
{
    WORD header_crc;
    BYTE header_type;
    WORD header_flags;
    WORD header_size;
};

struct headfile
{
    DWORD pack_size;
    DWORD unpsize;
    BYTE HostOS;
    DWORD fileCRC;
    DWORD FileTime;
    BYTE unpver;
    BYTE method;
    WORD namesize;
    DWORD fileattr;
};

#pragma pack(pop)


const BYTE signatures[] = { 0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x00 };
void PrintHeader(const vector <char>&, DWORD filesize);

int main()
{
    setlocale(LC_ALL,"ru");
    HANDLE hFile = CreateFile("Example.rar", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        wcout << L"Ошибка открытия файла" << endl;
        return 1;
    }
    else
	{
		cout << "Файл открыт" << endl;
	}
    DWORD fileSize = GetFileSize(hFile, NULL);
    vector<char> buffer(fileSize);
    DWORD bytesRead;
    ReadFile(hFile, &buffer[1], fileSize, &bytesRead, NULL);
    PrintHeader(buffer, fileSize);
    CloseHandle(hFile);
    return 0;
}


void PrintHeader(const vector <char>& bufer, DWORD filesize)
{
    cout << "\nFile size : " << filesize << endl;
    headvol header_main;
    headfile file_header;
    int index_to_cut = sizeof(signatures);
    int filecounts = 0;
    while (index_to_cut < filesize)
    {
        memcpy(&header_main, &bufer[index_to_cut], sizeof(header_main));
        if (header_main.header_type == 0x74)
        {
            int temporary = index_to_cut;
            filecounts++;
            index_to_cut += sizeof(header_main);
            memcpy(&file_header, &bufer[index_to_cut], sizeof(file_header));
            index_to_cut += sizeof(file_header);
            char* FileName = new char[file_header.namesize];
            for (int index_to_file = 0; index_to_file < file_header.namesize; index_to_file++)
            {
                FileName[index_to_file] = bufer[index_to_cut];
                index_to_cut++;
                cout << FileName[index_to_file];
            }

            cout << "\n";
            index_to_cut = temporary;
            index_to_cut += file_header.pack_size + header_main.header_size;
            delete[] FileName;
        }
        else
        {
            index_to_cut += sizeof(header_main.header_size);
        }
    }
    wcout << L"Кол-во файлов в архиве:" << filecounts;

}
