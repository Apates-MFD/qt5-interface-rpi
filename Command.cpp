#include "Command.h"

qint32* getint32(const char* data, int offset){
    qint32* tmp = (qint32*) malloc(sizeof(qint32));
    memcpy(tmp,data+offset,sizeof(qint32));
    return tmp;
}


t_command* DeserializePackage(QByteArray* buff)
{
    //Get char buffer
    const char* data = buff->constData();
    int index = 0;

    //Magic
    if(data[index] != PACK_MAGIC){
        throw std::runtime_error("Package Magic did not match.");
        return NULL;
    }
    index++;

    //Package Size
    qint32* package_size = getint32(data,index);
    qint32 count = buff->count();

    if(memcmp(package_size,&count,sizeof(qint32)) != 0)
    {
        throw std::runtime_error("Package Size did not match.");
        return NULL;
    }
    free(package_size);
    index += 4;

    //Header Size
    if(data[index++] != HEADER_SIZE){
        throw std::runtime_error("Header Size did not match.");
        return NULL;
    }

    //Command Type and Command
    int command_type_com = data[index];
    index++;

    int type = (command_type_com&0b11000000) >> 6;
    int com = command_type_com&0b00111111;

    //Parameter Count
    int parameter_count = data[index];
    index++;

    //Generating Command
    t_command* command = (t_command*) malloc(sizeof (t_command));
    command->command = com;
    command->type = type;

    if(parameter_count == 0)
    {
        //Command with no parameters
        command->parameters = NULL;
    }
    else
    {
        //Command with 1 or more parameters
        //Generate linked list...
        t_parameter* next_para = (t_parameter*) malloc(sizeof (t_parameter));
        t_parameter* root = NULL;

        for(int i = 0; i < parameter_count; i++)
        {
            t_parameter* param = (t_parameter*) malloc(sizeof (t_parameter));

            //Magic
            if(data[index++] != PARA_MAGIC){                
                throw std::runtime_error("Parameter Magic did not match.");
                return NULL;
            }

            //Parameter Type Size
            qint32* para_type_size = getint32(data,index);
            index+=4;

            //Parameter Size
            qint32* para_size = getint32(data,index);
            index+=4;

            //Get Parameter Type string
            char* para_type = (char*)malloc(*para_type_size + 1);
            memcpy(para_type,data+index,*para_type_size);
            para_type[*para_type_size] = '\0'; //Adding end to string
            index += *para_type_size;

            //Get Parameter
            char* para = (char*)malloc(*para_size + 1);
            memcpy(para,data+index,*para_size);
            para[*para_size] = '\0'; //Adding end to string
            index += *para_size;

            //Free unused vars to prevent memory leak
            free(para_type_size);
            free(para_size);

            //Fill struct
            param->data = para;
            param->type = para_type;
            param->next = NULL;

            //Linked List next...
            if(root == NULL){
                root = param;
                next_para = param;
            }
            else
            {
                next_para->next = param;
                next_para = param;
            }
        }

        //Memory Leak warning for next_Para. Is this true?
        command->parameters = root;
    }

    return command;

}


