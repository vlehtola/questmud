/* BUG-REPORT DAEMON */
/* bug_data = ([ (int)nro : (str)wiz_name ; (str)path ; (str)report, (str)reporter, (int)bug_time ]); */
/*               nro:           running number */
/*               wiz_name:      wiz's name (creator / pointed to) */
/*               path:          path to bugging object */
/*               report:        what bugs. */
/*               reporter:      ppl who reported */
/*               bug_time:      time when reported */

/* Some changes by Nalle - Tue May 11 02:08:46 2004
 * Changed the output, bugs also now show to all wizards who are logged
 * on when they are made and a message is given to the reporter. 
 * The message format is made in one function. Also :
 * - bug_time was changed to int ( time() )
 * - sort_mapping was removed. mappings can't be sorted, sort the keys.
 *   (replaced with sort_array efun call)
 * - remove bug now works, and when displaying bugs the list is walked
 *   through based on the keys, not an integer
 */

#include <ansi.h>

// DEFINES
#define SAVEDIR "/data/bug_data"

#define BUG_NAME(X) 	bug_data[X,0]
#define BUG_PATH(X) 	bug_data[X,1]
#define BUG_REPORT(X) 	bug_data[X,2]
#define BUG_REPORTER(X) bug_data[X,3]
#define BUG_TIME(X)     bug_data[X,4]

#define TP		this_player()

// VARS

mapping bug_data = ([ ]);

// PROTOS

void add_bug(string name, string path, string report, string reporter, int bug_time);
void remove_bug(int id);
void print_all_bugs();
void print_by_name(string str);
string print_bug(int bug_id);
mixed max_from_array(int *arr);

// CODE

void reset() 
{
 // +".o" added by Rag 11.5.2004
 if(file_size(SAVEDIR+".o") != -1) restore_object(SAVEDIR);
}

// Add bug to bug_data
void add_bug(string name, string path, string report, string reporter, int bug_time) 
{
 int i;
 string wiz_msg;

 i = (int) max_from_array( m_indices(bug_data) ) + 1;
 // i = m_sizeof(bug_data);

 bug_data += ([ i : name; path; report; reporter; bug_time, ]);

 wiz_msg = print_bug( i );

 for(i = 0; i < sizeof( users() ); i++)
    {
     if( users()[i]->query_wiz() > 0 )
      tell_object( users()[i], wiz_msg );
    }

 if( TP ) tell_object( TP, "\nBug report sent. Thank you for your input.\n\n");
         
 save_object(SAVEDIR);
 return;
}

// remove data from bug_data
void remove_bug(int id) 
{       
 if( member_array( id, m_indices(bug_data) ) == -1 ) 
   {
    write("No bug with ID "+id+" exists.\n");
    return;
   }

 bug_data -= ([ id ]);
        
 save_object(SAVEDIR);
 return;
}

// Prints every bug from the mapping
void print_all_bugs() 
{
 write( sprintf("%|78s\n\n", "- LISTING ALL REPORTED BUGS -") );
 print_by_name( 0 );
 return;
}

// need i say more?
void print_by_name(string str) 
{
 int n;
 int *mtmp;

 object pager;
 string result;

 pager = clone_object("/daemons/pager");
 pager->move( TP );

 result = "";

 mtmp = m_indices( bug_data );
 mtmp = sort_array( mtmp, #'>);	// Use this instead of sort_data, mappings
				// can't be sorted. -N
        
 for(n = 0; n < m_sizeof(bug_data); n++) 
 {
  if(!str || BUG_NAME( mtmp[n] ) == str) 
    {
     result += print_bug(mtmp[n]);
    }
 }

 pager->page(result);
 
 return;
}

// Returns a string with the bugs data in a sort of readable format -N
string print_bug(int bug_id)
{
 string buffy;
 int i;

 i = bug_id;
 
 buffy =  sprintf("ID: %s%-10s%s", RED_F, to_string( i ), OFF );

 if( stringp(BUG_NAME(i)) )
     buffy += sprintf("Target: %s%-31s%s", BOLD, capitalize(BUG_NAME(i)), OFF );
	else
     buffy += sprintf("%s%-31s%s", BOLD,"No target.", OFF);

 buffy += sprintf("BY: %s%-12s%s", GREEN_F, capitalize( BUG_REPORTER(i) ), OFF );
 buffy += sprintf("\nPath: %-47s", BUG_PATH(i) );
 buffy += sprintf("%-s", ctime( BUG_TIME(i) ) );
 buffy += sprintf("\nREPORT:\n %s\n\n", BUG_REPORT(i) );

 return buffy;
}


mapping query_bugdata() 
{
 return bug_data;
}


// A maximum finding fun. Couldn't find one in the lib. -N

mixed max_from_array(int *arr)
{
 int i;
 mixed cmax;

 if(!sizeof(arr))     return -1;
 if(sizeof(arr) == 1) return arr[0];

 cmax = arr[0];

 for(i = 1; i < sizeof(arr); i++ )
    {
     if( cmax < arr[i] ) cmax = arr[i];
    }

 return cmax;
}
