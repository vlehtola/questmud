/* rep command for QuestMUD by Nalle at 020602 */

status rep_loop(string str, string prefix);

status cmd_repeat(string prefix)
{
  if(!this_player()->check_condis())  { return 1; }
  if(!prefix) { write("Syntax: rep <string>\n"); return 1; }

  write("Entered rep mode. (Set to '"+prefix+"')\n");
  write("Enter '** <Enter>' to exit.\n");  
  rep_loop(0, prefix);  
  
  return 1; 
}

status rep_loop(string str, string prefix) { 
string output;
if(str=="**") { write("Exited rep mode.\n");
                return 1; }
if(str) {
output=prefix+" "+str;
command(output, this_player());
        }
input_to("rep_loop",0,prefix);
return 1;
}
