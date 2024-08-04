#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[])
{

 struct state {
    char cs;
    int ns1_idx;
    int ns0_idx;
};
  char input[20];
  struct state states[8];
  struct state dummy[8];
//{a,b,c,d,e,f,g,h}
 struct state *garbage = (struct state *)malloc(8 * sizeof(struct state));
  struct state *delte = (struct state *)malloc(8 * sizeof(struct state));
  int  m = 0;
   int k = 0;
  for (int i = 0;i<8;i++){
    states[i].cs = 'A'+i;
 switch(states[i].cs){
   case 'A' :states[i].ns0_idx=6; states[i].ns1_idx=7 ;break;
        case 'B' :states[i].ns0_idx=5;states[i].ns1_idx=4 ;  break;
	     case 'C' :states[i].ns0_idx=0;states[i].ns1_idx=7 ; break;
	          case 'D' :states[i].ns0_idx=1;states[i].ns1_idx=6 ;  break;
		       case 'E' :states[i].ns0_idx=2; states[i].ns1_idx=4 ; break;
    case 'F' :states[i].ns0_idx = 3; states[i].ns1_idx=0 ; break;
      		       case 'G' :states[i].ns0_idx=4; states[i].ns1_idx=3 ; break;
  case 'H' :states[i].ns0_idx=5; states[i].ns1_idx=1 ; break;
 }
  //  printf("%c  %c  %c \n",states[i].cs, states[ns0_idx].cs, states[ns1_idx].cs);
  } 
  for (int i = 0; i < 8; i++) {
        dummy[i] = states[i];
    }
 for (int i = 0;i<8;i++){ if (states[i].cs!= '\0') {  printf("%c  %c  %c \n",states[i].cs, states[states[i].ns0_idx].cs, states[states[i].ns1_idx].cs);}}
 
 
struct state s = states[0];
  printf("%c",states[0].cs);


while (1) {
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            if (input[0] == 'e') break;
            switch(input[0]) {

  case '0' :printf("%c\n",states[s.ns0_idx].cs);s = states[s.ns0_idx]; break;
  case '1' :printf("%c\n",states[s.ns1_idx].cs);s = states[s.ns1_idx]; break;
  case 'P' : 
  case 'p': for (int i = 0;i<8;i++){    if (states[i].cs!= '\0') { printf("%c  %c  %c \n",states[i].cs, states[states[i].ns0_idx].cs, states[states[i].ns1_idx].cs);}} ;break;
  case 'g':
  case 'G': 
   for(int l =0 ; l< 8 ; l++){for(int i =0 ; i<8 ; i++){
       int is_garbage = 1; 
        for (int j = 0; j < 8; j++) {
            if (i != j) {
                if (dummy[i].cs == dummy[dummy[j].ns0_idx].cs || dummy[i].cs == dummy[dummy[j].ns1_idx].cs) {
                    is_garbage = 0;
                    break;}}}
 int x = 1; for(int s =0;s<8;s++){if(dummy[i].cs==garbage[s].cs) x = 0;}
        if (is_garbage&&x) {
         
            garbage[k++] = dummy[i];
           dummy[i].cs = '\0';
              dummy[i].ns1_idx =i;
              dummy[i].ns0_idx = i;
            }
          
 }}  if(k>0)
        { printf("Garbage: <");
            for (int i =0 ; i <k ; i++)
            {printf(" %c, ", garbage[i].cs);} printf(">\n");}
        else printf("No garbage\n");
       break;
    case 'c':
    case 'C':
 if (strlen(input) >= 5) {
   
                        char newState = input[4];
                        int exist = 0;
                        for(int i = 0 ; i<8 ; i++){
                            if( states[i].cs == newState){
                               exist = 1; 
                            }
                        } if (!exist) { printf("This State was delted or did not exist"); break;}
                        if (input[2] == '0') {
                            for (int i = 0; i < 8; i++) {
                                if (states[i].cs == s.cs) {
                                    states[i].ns0_idx = newState - 'A';
                                  printf("The change was appllied. You are now in state %c \n", s.cs);    break;
                                }
                            }
                        } else if (input[2] == '1') {
                            for (int i = 0; i < 8; i++) {
                                if (states[i].cs == s.cs) {
                                    states[i].ns1_idx = newState - 'A';
                               printf("The change was appllied. You are now in state %c \n", s.cs);     break;

  } } } break;  }
  
  case 'd':
  case 'D':
  int dnexist = 1;
  for (int i = 0 ;i<8 ; i++)
{  if (input[2] == states[i].cs || input[2] == garbage[i].cs )
    dnexist = 0;
}
if (dnexist){ printf("This state %c does not exist", input[2]);
break;}
  if (input[2] == '\0'){
   
     // int u = 0;
  for(int l =0 ; l< 8 ; l++){for(int i =0 ; i<8 ; i++){
       int is_garbage = 1; 
        for (int j = 0; j < 8; j++) {
            if (i != j) {
                if (states[i].cs == states[states[j].ns0_idx].cs || states[i].cs == states[states[j].ns1_idx].cs) {
                    is_garbage = 0;
                    break;}}}
 int x = 1; for(int s =0;s<8;s++){if(states[i].cs==delte[s].cs) x = 0;}
        if (is_garbage&&x) {
            delte[m++] = states[i];
           states[i].cs = '\0';
              states[i].ns1_idx =i;
              states[i].ns0_idx = i;
            }
          
 }}  if(m>0)
        { printf("Deleted: <");
            for (int i =0 ; i <m ; i++)
            {printf(" %c, ", delte[i].cs);} printf(">\n");}
        else printf("No states deleted.\n"); m = 0; k = 0; 
 for (int i = 0; i < 8; i++) {
        dummy[i] = states[i];
    }

        break;}
        else { int del = -1;
            for(int i =0 ; i<8 ; i++){
                if (states[i].cs == input[2])
           {     del = i;}
            }
       int is_garbage = 1; 
       if(del == -1)
        { printf("Not deleted."); break;}
           else{
                              for (int j = 0; j < 8; j++) {
           
                                             if (states[del].cs == states[states[j].ns0_idx].cs || states[del].cs == states[states[j].ns1_idx].cs) {
                                       is_garbage = 0;
                                                 break;}}
                                              if (is_garbage) {
                                         delte[m++] = states[del];
                                                states[del].cs = '\0';
                                                      states[del].ns1_idx =del;
              states[del].ns0_idx = del;
              printf("Deleted.");
   }
          
 
            
        }
     
     
        } 
 for (int i = 0; i < 8; i++) {
        dummy[i] = states[i];
    }
 k = 0; m = 0; break;
      }}
    for (int i =0; i<8;i++){
        if(s.cs==states[i].cs)
        {s = states[i];
        break;
            
        }
    } for (int i = 0; i < 8; i++) { if (dummy[i].cs!='\0')
        dummy[i] = states[i];
    }
    
}}