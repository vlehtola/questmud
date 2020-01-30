// An early testing-version of a more versatile 'call'- command.
// -- Nalle 14.12.2003
/*
 * You are free to make changes/enhancements, but make a backup
 * and comment your work. Also be familiar with the existing code
 * before altering this, please. -N
 */


#define TP this_player()

#include <ansi.h>
#include "/cmds/wiz/call.h"

cmd_ncall(string str) 
{
 mixed *result;
 object target;
 string fun;
 mixed *args;

 if(!str)
   {
    write("Syntax: call <object> <function> [arguments]\n" );
    return 1;
   }

 target = parse_target(str);
 
 if(!target) { write("Invalid target object.\n"); return 1; }

 fun = parse_fun(str);

 if(!fun) { write("Invalid function.\n"); return 1; }

 if(!function_exists(fun, target))
	{
	 write(RED_F+"Caution"+OFF+" : Function '"+fun+"' does not exist in '"+file_name(target)+"'.\n");
	 return 1;
	}

 args = parse_arguments(str);

 if(!pointerp(args) && args) args = ({ args });

 write("Success. \""+file_name(target)+"\"->"+fun+"( "+sizeof(args)+" arguments ).\n");

 switch (sizeof(args))
	{
	 case 0	:	result = call_other(target, fun); 
			break;
	 case 1	:	result = call_other(target, fun, args[0]); 
			break;
	 case 2	:	result = call_other(target, fun, args[0], args[1]); 
			break;
	 case 3	:	result = call_other(target, fun, args[0], args[1], args[2]); 
			break;
	 case 4	:	result = call_other(target, fun, args[0], args[1], args[2], args[3]); 
			break;
	 case 5	:	result = call_other(target, fun, args[0], args[1], args[2], args[4]); 
			break;
	 case 6	:	result = call_other(target, fun, args[0], args[1], args[2], args[4], args[5]); 
			break;
	 case 7	:	result = call_other(target, fun, args[0], args[1], args[2], args[4], args[5], args[6]); 
			break;
	 case 8	:	result = call_other(target, fun, args[0], args[1], args[2], args[4], args[5], args[6], args[7]); 
			break;
	 case 9	:	result = call_other(target, fun, args[0], args[1], args[2], args[4], args[5], args[6], args[7], args[8]); 
			break;
	 case 10:	result = call_other(target, fun, args[0], args[1], args[2], args[4], args[5], args[6], args[9]); 
			break;
	 default : break;
	}

   show_results(result);

   if(pointerp(result)) write("\nResult size "+sizeof(result)+".\n");

   return 1;
}

        
/*******************************************************************/

object parse_target(string str)
{
 string target, temp, pwd;
 if(!str) return 0;

 pwd = TP->query_working_directory()+"/";

 if(! sscanf(str, "%s %s", target, temp )) return 0;

 // Filename
 if(file_size(target) != -1 && file_size(target) != -2) 
   {
    return find_object(target);
   }

 // Filename 2 (without .c)
 if(file_size(target+".c") != -1 && file_size(target+".c") != -2) 
   {
    return find_object(target+".c");
   }

 // Filename w/pwd
 if(file_size(pwd+target) != -1 && file_size(target) != -2) 
   {
    return find_object(target);
   }

 // Filename 2 (without .c) w/pwd
 if(file_size(pwd+target+".c") != -1 && file_size(pwd+target+".c") != -2) 
   {
    return find_object(pwd+target+".c");
   }

 // This room
 if(target == "here") return environment(TP);

 // This player
 if(target == "me") return TP;


 // Player (put this lower when debugged)
 if( find_player(target) ) return find_player(target);

 // Something in TP
 if( present(target, TP ) ) return present(target, TP );

 // Something in TPs environment
 if( present(target, environment(TP) ) ) return present(target, environment(TP));

 return 0;
}

/*******************************************************************/

string parse_fun(string str)
{
 string *strs;
 string fun;
 
 if(!str) return 0;

 strs = explode(str, " ");

 if(sizeof(strs) < 2) return 0;
 
 fun = strs[1];

 if(!fun || strlen(fun) < 2) return 0;

 return fun;
}

/*******************************************************************/

mixed *parse_arguments(string str)
{
 string *strs, *tmp;
 int i;
 string temp;
 mixed *result;

 tmp = explode(str, " ");

 strs = ({});

 for( i = 0 ; i < sizeof(tmp) ; i++ )
    {
     if( i > 1 ) strs += ({ tmp[i] });
    }

 if(!sizeof(strs)) return 0;

 // Remove commas
 for(i = 0; i < sizeof(strs); i++)
    {
     if(strs[i][strlen(strs[i])-1..strlen(strs[i])-1] == ",")
        strs[i] = strs[i][0 .. strlen(strs[i])-1];
    }

 // String/int conversions
 
 result = allocate(sizeof(strs));

 for(i = 0; i < sizeof(strs); i++)
    {
     if(strs[i] == "me" || strs[i] == "here")
       {
	if(strs[i] == "me")	result[i] = TP;
	if(strs[i] == "here")	result[i] = environment(TP);
       }
	else
     if(sscanf( strs[i], "\"%s\"", temp) == 1) result[i] = temp;
	else 
	{ result[i] = to_int(strs[i]); }
    }

 return result;
}

/*******************************************************************/

