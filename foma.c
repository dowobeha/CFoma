//   Foma: a finite-state toolkit and library.                                 
//   Copyright © 2008-2015 Mans Hulden                                         

//   This file is part of foma.                                                

//   Licensed under the Apache License, Version 2.0 (the "License");           
//   you may not use this file except in compliance with the License.          
//   You may obtain a copy of the License at                                   

//      http://www.apache.org/licenses/LICENSE-2.0                             

//   Unless required by applicable law or agreed to in writing, software       
//   distributed under the License is distributed on an "AS IS" BASIS,         
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  
//   See the License for the specific language governing permissions and       
//   limitations under the License.                                            
/*
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <readline/readline.h>
*/
#include "foma.h"

// Front-end behavior variables 
int pipe_mode = 0;
int quiet_mode = 0;
static int use_readline = 1;

int promptmode = PROMPT_MAIN;
int apply_direction;

// Variable to pass the position of rl completion to our completer 
static int smatch;

char *usagestring = "Usage: foma [-e \"command\"] [-f run-once-script] [-l startupscript] [-p] [-q] [-s] [-v]\n";

static char** my_completion(const char*, int ,int);
char *my_generator(const char* , int);
char *cmd [] = {"ambiguous upper","apply down","apply med","apply up","apropos","assert-stack","clear stack","close sigma","compact sigma","complete net","compose net","concatenate net","crossproduct net","define","determinize net","echo","eliminate flags","eliminate flag","export cmatrix","extract ambiguous","extract unambiguous","factorize","help license","help warranty","ignore net","intersect net","invert net","label net","letter machine","load defined","lower-side net","minimize net","name net","negate net","one-plus net","pop stack","print defined","print dot","print lower-words","print cmatrix","print name","print net","print random-lower","print random-upper","print random-words","print sigma","print size","print shortest-string","print shortest-string-length","print words","print pairs","print random-pairs","print upper-words","prune net","push defined","quit","read att","read cmatrix","read prolog","read lexc","read regex","read spaced-text","read text","reverse net","rotate stack","save defined","save stack","sequentialize","set","show variables","show variable","shuffle net","sigma","sigma net","source","sort in","sort net","sort out","substitute defined","substitute symbol","system","test unambiguous","test star-free","test equivalent","test functional","test identity","test lower-universal","test upper-universal","test non-null","test null","test sequential","turn stack","twosided flag-diacritics","undefine","union net","upper-side net","view net","write att","write prolog","zero-plus net",NULL};

char *abbrvcmd [] = {"ambiguous","close","down","up","med","size","loadd","lower-words","upper-words","net","random-lower","random-upper","words","random-words","regex","rpl","au revoir","bye","exit","saved","seq","ss","stack","tunam","tid","tfu","tlu","tuu","tnu","tnn","tseq","tsf","equ","pss","psz","ratt","tfd","hyvästi","watt","wpl","examb","exunamb","pairs","random-pairs",NULL};

// #include "yy.tab.h" 

int view_net(struct fsm *net);

extern int input_is_file;
extern int add_history (const char *);
extern int my_yyparse(char *my_string);
void print_help();
void xprintf(char *string) { return ; printf("%s",string); }
char disclaimer[] = "Foma, version 0.9.18alpha\nCopyright © 2008-2015 Mans Hulden\nThis is free software; see the source code for copying conditions.\nThere is ABSOLUTELY NO WARRANTY; for details, type \"help license\"\n\nType \"help\" to list all commands available.\nType \"help <topic>\" or help \"<operator>\" for further help.\n\n";

// A static variable for holding the line. 

static char *command = (char *)NULL;
char *flex_command = NULL;
static char *line_read = (char *)NULL;
char no_readline_line[512]; 
int swift_demo() { return 7; } 
// Read a string, and return a pointer to it.
//   Returns NULL on EOF. 
/*
char *rl_gets(char *prompt) {
    
    // If the buffer has already been allocated,
       return the memory to the free pool. 
    if (use_readline == 1) {
        if (line_read) {
            free(line_read);
            line_read = (char *)NULL;
        }
    }
    if (use_readline == 0) {
        printf("%s",prompt);
        line_read = fgets(no_readline_line, 511, stdin);
        if (line_read != NULL) {
            strip_newline(line_read);
        }
    } else {
        line_read = readline(prompt);
    }
    
    // If the line has any text in it,
       save it on the history. 
    if (use_readline == 1) {
        if (line_read && *line_read)
            add_history(line_read);        
    }
    return (line_read);
}



void print_help() {
    printf("%s",usagestring);
    printf("Options:\n");
    printf("-e \"command\"\texecute a command on startup (-e can be invoked several times)\n");
    printf("-f scriptfile\tread commands from scriptfile on startup, and quit\n");
    printf("-l scriptfile\tread commands from scriptfile on startup\n");
    printf("-p\t\tpipe-mode\n");
    printf("-q\t\tquiet mode (more quiet than pipe-mode)\n");
    printf("-r\t\tdon't use readline library for input\n");
    printf("-s\t\tstop execution and exit\n");
    printf("-v\t\tprint version number\n");
}

static char **my_completion(const char *text, int start, int end) {
    char **matches;

    matches = (char **)NULL;
    smatch = start;
    matches = rl_completion_matches ((char*)text, &my_generator);
    
    return (matches);    
}

char *my_generator(const char *text, int state) {
    static int list_index, list_index2, len, nummatches;
    char *name;
    text = rl_line_buffer;
    if (!state) {
        list_index = 0;
        list_index2 = 0;
        nummatches = 0;
        len = strlen(text);
    }
    
    while ((name = cmd[list_index])) {
        list_index++;

        if (strncmp (name, text, len) == 0) {
            nummatches++;            
            // Can't use xxstrdup here 
            return(strdup(name+smatch));
        }
    }
    
    if (rl_point > 0) {
        while ((name = abbrvcmd[list_index2])) {
            list_index2++;
            
            // Can't use xxstrdup here 
            if (strncmp (name, text, len) == 0)
                return(strdup(name+smatch));
        }        
    }
    
    // If no names matched, then return NULL. 
    return ((char *)NULL);
}
*/