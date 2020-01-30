/* BUG-REPORT DAEMON */
/* bug_data = ([ (int)nro : (str)wiz_name ; (str)path ; (str)report, (str)reporter, (str)bug_time ]); */
/*               nro: 		running number */
/*               wiz_name:	wiz's name (creator / pointed to) */
/*               path:  	path to bugging object */
/*		 report:	what bugs. */
/*		 reporter:	ppl who reported */
/*		 bug_time:	time when reported */

// DEFINES
#define SAVEDIR "/data/bug_data"

#define BUG_NAME(X) bug_data[X,0]
#define BUG_PATH(X) bug_data[X,1]
#define BUG_REPORT(X) bug_data[X,2]
#define BUG_REPORTER(X) bug_data[X,3]
#define BUG_TIME(X)	bug_data[X,4]

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
	
	if(file_size(SAVEDIR) != -1) restore_object(SAVEDIR);
}

// Add bug to bug_data
void add_bug(string name, string path, string report, string reporter, string bug_time) {
	int i;
	string *temp;
	
	sort_mapping();

	temp = m_indices(bug_data);
	i = sizeof(temp);	

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
	string *temp;
	int i,j;
	
	temp_map = bug_data;
	
	bug_data = ([ ]);
	
	temp = m_indices(temp_map);
	
	for(i = 0 ; i < sizeof(temp); i++) {
		
		bug_data += ([ i: temp_map[i]; temp_map[i,1]; temp_map[i,2]; temp_map[i,3]; temp_map[i,4], ]);
	}
	return;
	
}

// Prints every bug from the mapping
void print_all_bugs() {
	
int i;
string *temp;
	
	temp = m_indices(bug_data);

	write("-=-=-=-=-=-=-=- LISTING ALL REPORTED BUGS -=-=-=-=-=-=-=-=-=-\n");
	for(i=0; i < sizeof(temp) ; i++) {
	
	write("ID: "+i+" NAME: "+BUG_NAME(i)+"\n");
	write("PATH: "+BUG_PATH(i)+"\n");
	write("BY: "+BUG_REPORTER(i)+"  TIME:"+BUG_TIME(i)+"\n");
	write("REPORT: "+BUG_REPORT(i)+"\n\n");		
	}
	return;
}

// need i say more?
void print_by_name(string str) {
	int i,j;
	string *temp;
	
	if(!str)return;

	temp = m_indices(bug_data);
	
	for(i = 0; i < sizeof(bug_data); i++) {
		
		if(BUG_NAME(i) == str) {
			write("ID: "+i+" NAME:"+BUG_NAME(i)+"\n");
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
