/* Say command for QuestMUD by Nalle at 160502 */
/* Parts of some code from Cendor's _tell.c    */

string * rem_say(string arg,string * arr);
status last_say(string *arr);

status cmd_say(string str)
{
  int i;
  object *ob;
  string *last_tell;

  if(!this_player()->check_condis())  { return 1; }

  if(str=="last")   {
    last_say(this_player()->query_say_messages());
    return 1;       } 

  if(!str)   {
    write("Syntax : say <message or 'last'>\n");
    return 1;
              }

  ob = all_inventory(environment(this_player()));

for(i=0;i<sizeof(ob);i++) {
 if(ob[i]!=this_player() && living(ob[i]))
 ob[i]->set_say_messages(
   rem_say(sprintf("["+ctime()[11..15]+"] %s says '%s'\n",this_player()->query_name(),str)
   ,ob[i]->query_say_messages()));
                          }

  write("You say '" +str+ "'\n");
  say(this_player()->query_name() + " says '" +str+ "'\n");
  return 1;

}

string * rem_say(string arg, string * arr)
{
  int x;
  if(!pointerp(arr)) arr = ({});
  if(!arg) return 0;
  if(sizeof(arr)>19)
  {
    for(x=1;x<sizeof(arr);x++)
    {
      arr[x-1]=arr[x];
    }
    arr[19]=arg;
    return arr;
  }
  arr += ({ arg });
  return arr;
}

last_say(string *arr)
{
  int x; 
  if(!pointerp(arr)) return 1;
  for(x=0;x<sizeof(arr);x++)
  {
    printf("%s",arr[x]);
  }
  return 1;
}
