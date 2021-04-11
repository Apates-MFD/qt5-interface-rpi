#ifndef COMMAND_H
#define COMMAND_H
//Includes
#include <QByteArray>

//Static Stuff
#define PACK_MAGIC (char)0b10101010
#define PARA_MAGIC (char)0b01010101
#define HEADER_SIZE 8
#define PARA_SIZE_COUNT 4
#define PARA_TYPE_COUNT 4

//Command Types
#define BUTTONS 0
#define CENTER 1

//Button Commands
#define SET_TEXT 0
#define CLEAR 1
#define SET_DISPLAY_SETTINGS 2

//Center Commands

//Structs
struct t_parameter{
    char* type;
    char* data;
    t_parameter* next;
};

struct t_command {
    int type;
    int command;
    t_parameter* parameters;
};

//Prototypes
t_command* DeserializePackage(QByteArray* buff);
#endif // COMMAND_H
