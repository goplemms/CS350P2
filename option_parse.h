#ifndef OPTION_PARSE_H
#define OPTION_PARSE_H

extern unsigned short int N_flag;
extern unsigned short int M_flag;
extern unsigned short int p_flag;
extern unsigned short int s_flag;

extern unsigned int num_lvl;
extern unsigned int num_chd;
extern unsigned int slp_tim;

int initializeOptions(int argc, char** argv, char* option_string);

#endif
