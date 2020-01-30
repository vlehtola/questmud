/* Call command for QuestMUD by Cendor in 31th Aug 1997 */

/* Include file from original Heaven7 lib _heavily_ modified by Cendor */



#define LEV query_level()

#define WLEV query_wiz()

 

#include <mudlib.h>        

#include <call.h>



cmd_cal(string str) {

  mixed last_arg;

  string type_arg;

  object *ob;

  string who, do_str, arg1, arg2;

  int i, iarg1, iarg2;

  status use_int1, use_int2, load;

            

  if(!str){

    write("## Usage: call [OBJ;FUNC]\n"+

          "          call [OBJ;FUNC;ARG1]\n"+

          "          call [OBJ;FUNC;ARG1;ARG2]\n");

    write("Notes : This command MAY still bug a bit.\n");

    write("        Report all bugs to Cendor.\n");

    return 1;

}

  if(sscanf(str,"%s;%s;%s;%s",who, do_str, arg1, arg2) == 4) {

    if(sscanf(arg1,"%d",iarg1) == 1) use_int1 = 1;

    if(sscanf(arg2,"%d",iarg2) == 1) use_int2 = 1;

}

  else if(sscanf(str,"%s;%s;%s", who, do_str, arg1) == 3) {

    if(sscanf(arg1,"%d",iarg1) == 1) use_int1 = 1;

}

  else if(!sscanf(str,"%s;%s", who, do_str)) {

    who = str;    

    load = 1;    

}

  /* Only admins can call ALL USERS at the same time */

  if((who == "users") && this_player() -> WLEV < 4) {

  write("## Call : Permission denied.\n");

  return 1;

}



if(!sizeof((ob = PROCESS_ARG(who)))) { return 1; }

  for(i = 0; i < sizeof(ob); i++) {

    /* Wizards can't call higher level wizards. */

    if(this_player()->LEV < ob[i]->LEV) {

      write("## Call : Permission denied.\n");

      continue;

}

/* Only arches can call other players */

if((this_player()->WLEV < 3) && 

  living(ob[i]) && interactive(ob[i]) && 

  who == (string)ob[i]->query_real_name() &&

  who != (string)this_player()->query_real_name()) { 

  write("## Call : Permission denied.\n");

  return 1;

}

  write("\nOBJ: "+file_name(ob[i])+"\n");

  if(use_int1 && use_int2)

    last_arg = (mixed)call_other(ob[i],do_str,iarg1,iarg2);

  else if(use_int1 && arg2)

    last_arg = (mixed)call_other(ob[i],do_str,iarg1,arg2);

  else if(arg1 && use_int2)

    last_arg = (mixed)call_other(ob[i],do_str,arg1,iarg2);

  else if(use_int1)

    last_arg = (mixed)call_other(ob[i],do_str,iarg1);

  else if(arg1)

    last_arg = (mixed)call_other(ob[i],do_str,arg1);

  else if(do_str) 

    last_arg = (mixed)call_other(ob[i],do_str);

    write("## Call results :\n");     

    show_results(last_arg);

    

if(do_str) {

log_file("CALLS", (!living(ob[i]) ? "\"" + (string)file_name(ob[i]) + "\"" : (string)ob[i]->query_name()) + 

    " -> " + do_str + "(" + (arg1 ? (to_int(arg1) ? arg1 : "\"" + arg1 + "\"") : "") +

    (arg2 ? ", " + (to_int(arg2) ? arg2 : "\"" + arg2 + "\"") : "") + ") [" + this_player()->query_name() + " at " + ctime(time()) + "]\n");

}



if(!ob[i]) write("## Call : Object destructed itself!\n");



else if(!(last_arg || load)) {

  string sh;

  sh = (ob[i]->query_short()) ? (string)ob[i]->query_short()+", "+file_name(ob[i]) : "/" + file_name(ob[i]);

  /* Check if function exists */

  if(function_exists(do_str, ob[i])) {

  write("## Call : Function: '"+do_str+"' exists in "+sh+".\n");

  }

else {

    write("## Call : Function: '"+do_str+"' does not exist in "+sh+"\n");

     }

   }

 }

return 1;

}

        

