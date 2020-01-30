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


cmd_ls(string path) 
{ 
    int verbose, i, longest, enable_pager;
    int rows, stringlen;
    string ls_path, buffy;
    string *result;
    object pager;
    int totalsize;


    totalsize = 0;
    enable_pager = 0;

    if(path)
      {
	// Check for a switch (ugly, fix if you add more)
        string temp;
	temp = path;
	if( temp == "-l"  || temp == "-lp" || temp == "-pl") 
	  {
	   verbose = 1;
	   if( temp == "-lp" || temp == "-pl" ) enable_pager = 1;
	   path = 0;
	  }
	 else
	  {
           if( sscanf(path, "-l %s", temp) == 1 )
	      { 
	       verbose = 1;
	       path = temp;
	      }

           if( sscanf(path, "-lp %s", temp) == 1 )
	      { 
	       enable_pager = 1;
	       verbose = 1;
	       path = temp;
	      }
	  }
      } 

    // Handle empty args
    if (!path) 
        path = "/" + this_player()->query_current_path();

    // Handle ~ -> userdir
    if (path == "~" || path == "~/") 
       {
         path = "/wizards/" +this_player()->query_real_name()+ path[1 .. (strlen(path)-1) ];
       }
       else

    if(strlen(path) >= 2)
      {
       if (path[0..1] == "~/") 
	  path = "/wizards/" +this_player()->query_real_name()+ path[1 .. (strlen(path)-1) ];
	else
	{
	 string tmp1, tmp2;
	  if( sscanf(path, "~%s/%s", tmp1,tmp2) == 2 )
	    {
	     path = "/wizards/"+tmp1+"/"+tmp2;
	    }
	    else
	    if( sscanf(path, "~%s", tmp1) == 1 )
	    {
	     path = "/wizards/"+tmp1;
	    }
	}
      }

    if (path != "/")
        path += "/.";

    // Cosmetics :)
    buffy = "";
    if( sscanf(path, "%s//.",  buffy) == 1 ) path = buffy + "/.";
    if( sscanf(path, "%s///.", buffy) == 1 ) path = buffy + "/.";

    /* ask gently so no error if no access */
    path = SIMUL->valid_read(path, this_player());

    if (!path)
       {
        write("Sorry, browse access denied.\n");
        return 1; 
       } 

    if( file_size(path) == -1 )
	{
	 write("No such directory or no read rights.\n");
	 return 1;
	}

    write("Directory listing of "+path+"\n");

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
	 if(result[i][1] >= 0) totalsize += result[i][1];
	}

    buffy += "\nA total of "+totalsize+" bytes displayed in "+sizeof(result)+" files.\n";

      if(enable_pager)
	{
	 pager = clone_object("/daemons/pager");
	 pager->move(this_player());
	 pager->page(buffy);
	} 
	 else 
	{ 
	 write(buffy+"\n"); 
	}

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

	 if(result[i][1] >= 0) totalsize += result[i][1];
	}

    buffy += "\n\nA total of "+totalsize+" bytes displayed in "+sizeof(result)+" files.\n";

      if(enable_pager)
	{
	 pager = clone_object("/daemons/pager");
	 pager->move(this_player());
	 pager->page(buffy);
	}
	 else 
	{ 
	 write(buffy+"\n"); 
	}

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
