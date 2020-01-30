/* BUG-REPORT DAEMON */
/* bug_data = ([ (int)nro : (str)wiz_name ; (str)path ; (str)report, (str)reporter, (str)bug_time ]); */
/*               nro:           running number */
/*               wiz_name:      wiz's name (creator / pointed to) */
/*               path:          path to bugging object */
/*               report:        what bugs. */
/*               reporter:      ppl who reported */
/*               bug_time:      time when reported */

// DEFINES
#define SAVEDIR "/data/bug_data"

#define BUG_NAME(X) bug_data[X,0]
#define BUG_PATH(X) bug_data[X,1]
#define BUG_REPORT(X) bug_data[X,2]
#define BUG_REPORTER(X) bug_data[X,3]
#define BUG_TIME(X)     bug_data[X,4]

// VARS

mapping bug_data = ([ ]);

// PROTOS

void add_bug(string name, string path, string report, string reporter, string bug_time);
void sort_mapping();
void remove_bug(int id);
void print_all_bugs();
void print_by_name(string str);


// CODE

void reset() {
        // +".o" added by Rag 11.5.2004
        if(file_size(SAVEDIR+".o") != -1) restore_object(SAVEDIR);
}

// Add bug to bug_data
void add_bug(string name, string path, string report, string reporter, string bug_time) {
        int i;
        
        sort_mapping();

        i = m_sizeof(bug_data);       

        bug_data += ([ i : name; path; report; reporter; bug_time, ]);
        
        save_object(SAVEDIR);
        return;
}

// remove data from bug_data
void remove_bug(int id) {       
                
        bug_data -= ([ id ]);
        sort_mapping();
        
        save_object(SAVEDIR);
        return;
}


// Sort bug_data mapping
void sort_mapping() {

        mapping temp_map;
        int i;
        
        //Added ([ ]) -- Rag 11.5.2004
        //Not sure if it's needed or not, man said that it has to be there...
        temp_map = ([ ]) + bug_data;
        
        bug_data = ([ ]);
        
        for(i = 0 ; i < m_sizeof(temp_map); i++) {
                
                bug_data += ([ i: temp_map[i,0]; temp_map[i,1]; temp_map[i,2]; temp_map[i,3]; temp_map[i,4], ]);
        }
        return;
}

// Prints every bug from the mapping
void print_all_bugs() {
        
        int i;
        
        write("-=-=-=-=-=-=-=- LISTING ALL REPORTED BUGS -=-=-=-=-=-=-=-=-=-\n");
        for(i=0; i < m_sizeof(bug_data) ; i++) {
        
        write("ID: "+i+" NAME: "+BUG_NAME(i)+"\n");
        write("PATH: "+BUG_PATH(i)+"\n");
        write("BY: "+BUG_REPORTER(i)+"  TIME:"+BUG_TIME(i)+"\n");
        write("REPORT: "+BUG_REPORT(i)+"\n\n");         
        }
        return;
}

// need i say more?
void print_by_name(string str) {
        int i;
        
        if(!str)return;

        for(i = 0; i < m_sizeof(bug_data); i++) {
                
                if(BUG_NAME(i) == str) {
                        write("ID: "+i+" NAME: "+BUG_NAME(i)+"\n");
                        write("PATH: "+BUG_PATH(i)+"\n");
                        write("BY: "+BUG_REPORTER(i)+"  TIME:"+BUG_TIME(i)+"\n");
                        write("REPORT: "+BUG_REPORT(i)+"\n\n");
                }
        }

return;
}



mapping query_bugdata() {
        return bug_data;
}
