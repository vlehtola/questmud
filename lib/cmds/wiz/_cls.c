// Coloured ls by Nalle -- 2003
// Colour funs used in a strange way because of sprintf issue

#include <ansi.h>

#define SIMUL "/secure/simul_efun"


/**********************************************************************/
// Prototypes

string color_file(string str, int size);
string colorize(string str, string color);
string dir_filter(int size);

/**********************************************************************/


cmd_cls(string path) 
{ 
    int verbose, i, longest;
    int rows, stringlen;
    string ls_path, buffy;
    string *result;
    object pager;


    if(path)
      {
	// Check for a switch
        string temp;
	temp = path;
	if( temp == "-l" ) 
	  {
	   verbose = 1;
	   path = 0;
	  }
	 else
	  {
           if( sscanf(path, "-l %s", temp) == 1 )
	      { 
	       verbose = 1;
	       path = temp;
	      }
	  }
      } 

    if (!path) 
        path = "/" + this_player()->query_current_path();
    if (path != "/") 
        path = path + "/.";
    /* ask gently so no error if no access */
    path = SIMUL->valid_read(path, this_player());

    if (!path) 
       {
        write("Sorry, browse access denied.\n");
        return 1; 
       } 

    buffy  = "";
    result = transpose_array(
		({ 
		get_dir(path, 0x21), 
		get_dir(path, 2), 
		get_dir(path, 4) 
		}) );

  if(verbose) // Verbose mode output
    {
     for(i = 0;i < sizeof(result); i++)
	{
	 buffy += sprintf("%s%-30s%s %15s  %20s\n",
			color_file(result[i][0], result[i][1]),		
			result[i][0],
			OFF,
			dir_filter(result[i][1]),
			ctime(result[i][2])
			 );
	}

    buffy += "\nA total of "+sizeof(result)+" files displayed.\n";

    pager = clone_object("/daemons/pager");
    pager->move(this_player());
    pager->page(buffy);

    return 1; 
     
    } // Endof verbose mode output

   // Now for the Unverbose.

    longest = 0;

    // Check the longest file
    for(i = 0; i < sizeof(result); i++) 
	if( strlen(result[i][0]) > longest ) longest = strlen(result[i][0]);
 

    // Adjust rows accordingly
     if(longest < 19)
	{
	 rows = 4; stringlen = 19;
	} 
	 else 
	{ 
	 rows = 3; stringlen = 24;
	}

    for(i = 0;i < sizeof(result); i++)
	{
	 if(!(i%rows)) buffy += "\n";
	 buffy += sprintf("%s%-"+stringlen+"s%s",
			color_file(result[i][0], result[i][1]),		
			result[i][0] + dir_filter2(result[i][1]),
			OFF
			 );

	}

    buffy+="\n\nA total of "+sizeof(result)+" files displayed.\n";

    pager = clone_object("/daemons/pager");
    pager->move(this_player());
    pager->page(buffy);

    return 1; 

}   

/**********************************************************************/

string color_file(string str, int size)
{
 string temp, temp2;

 // Sanity
 if(!str) return "";
 temp = str;

 // Dir
 if(size == -2) return colorize(str, "blue");

 // .c
 if(sscanf(temp, "%s.c", temp2) == 1) return colorize(str, "green");

 // .h
 if(sscanf(temp, "%s.h", temp2) == 1) return colorize(str, "magenta");

 // .o
 if(sscanf(temp, "%s.o", temp2) == 1) return colorize(str, "yellow");

 // .txt
 if(sscanf(temp, "%s.txt", temp2) == 1) return colorize(str, "cyan");

 return "";
}

/**********************************************************************/

string dir_filter(int size) 
{ 
 if(size == -2) return "Directory";

 return to_string(size)+" bytes";
}

string dir_filter2(int size)
{
 if(size == -2) return "/";
 return "";
}

/**********************************************************************/

string colorize(string str, string color)
{
 if( !this_player()->query_terminal() ) return str;

 switch(color)
	{
	 case "blue"	: return HIB;
	 case "green"	: return GREEN_F;
	 case "magenta"	: return MAGENTA_F;
	 case "yellow"	: return YELLOW_F;
	 case "cyan"	: return CYAN_F;
	 default : return "";
	}

}
