/* -Nalle */

status cmd_hidemarriage(string str)
{
  int i;
  string name;

  if(!this_player()->check_condis())  { return 1; }

  if(!strlen(this_player()->query_married())) 
 { write("You are not married.\n");  return 1; }

  sscanf(this_player()->query_married(),"%d %s",i, name);

  if(i) this_player()->set_married("0 "+name); else
        this_player()->set_married("1 "+name);
  write("Done.\n");

return 1;
}
