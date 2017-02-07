#include "option_parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

unsigned short int N_flag;
unsigned short int M_flag;
unsigned short int p_flag;
unsigned short int s_flag;

unsigned int num_lvl;
unsigned int num_chd;
unsigned int slp_tim;

int initializeOptions(int argc, char** argv, char* option_string){
  N_flag = FALSE;
  M_flag = FALSE;
  p_flag = FALSE;
  s_flag = FALSE;

  num_lvl = 0;
  num_chd = 1;
  slp_tim = 1;
  
  int opt = getopt(argc, argv, option_string); 
  opterr = 1;

  while(opt != -1){
    switch(opt){
    case 'u':
      {
	fprintf(stderr, "prog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time>]\n");
	exit(0);
	break;
      }
    case 'N':
      {
	if(N_flag){
	  fprintf(stderr, "Duplicate %c option. Ignoring\n", optopt);
	  break;
	}
	N_flag = TRUE;
	num_lvl = atoi(optarg);

	if(num_lvl > 4){
	  fprintf(stderr, "Error: Number levels should be an integer between 0 and 4 inclusive.\n");
	  exit(1);
	}else if(num_lvl > 1){
	  *optarg -= 1;
	}
	break;
      }
    case 'M':
      {
	if(M_flag){
	  fprintf(stderr, "Duplicate %c option. Ignoring\n", optopt);
	  break;
	}
	M_flag = TRUE;
	num_chd = atoi(optarg);
	if(num_chd > 3 || num_chd == 0){
	  fprintf(stderr, "Error: Number of children should be an integer between 1 and 3 inclusive.\n");
	  exit(1);
	}
	break;
      }
    case 'p':
      {
	if(p_flag){
	  fprintf(stderr, "Duplicate %c option. Ignoring\n", optopt);
	  break;
	}
	if(s_flag){
	  fprintf(stderr, "Error: p option and s option cannot be used together\n");
	  break;
	}
	p_flag = TRUE;
	break;
      }
    case 's':
      {
	if(s_flag){
	  fprintf(stderr, "Duplicate %c option. Ignoring\n", optopt);
	  break;
	}
	if(p_flag){
	  fprintf(stderr, "Error: p option and s option cannot be used together\n");
	  exit(1);
	  break;
	}
	s_flag = TRUE;
	slp_tim = atoi(optarg);
	break;
      }
    case '?':
      //Getopt already returns an informative string
      fprintf(stderr, "Unrecognized option: -%c\n", optopt);
      return 1;
     
    case ':':
      //Getopt already returns an informative string
      //fprintf(stderr, "Option -%c requires an argument\n", optopt);
      fprintf(stderr, "Cannot pass in values through the command line\n");
      return 1;
    default:
      {
	fprintf(stderr, "Cannot pass in values through the command line\n");
	return 1;
	break;
      }
    }
    opt = getopt(argc, argv, option_string);
  }
  return 0;
}


/*
  if(access(optarg, F_OK) == -1){
  fprintf(stderr,"The file %s does not exist\n", optarg);
  FREEFILE;
  exit(1);
  }
*/
