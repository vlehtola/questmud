cmd_lasttells(str) {
  object ob;
  if (!str) { write("Need argument.\n"); return 1; }
  ob = find_player(lower_case(str));
  if (!ob) { write("No such a player.\n"); return 1; }
  last_tell(ob->query_last_tells());
  if
 (ob->query_level()>this_player()->query_level() && this_player()->query_name()!="Nalle")
{ tell_object(ob,"[Last tells checked by "+this_player()->query_name()+"]\n"); }
  return 1;
}
  
    



status last_tell(string *arr)
{
  int x;
  for(x=0;x<sizeof(arr);x++)
  {
    write(arr[x]);
  }
  return 1;
}

