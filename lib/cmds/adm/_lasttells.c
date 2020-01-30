cmd_lasttells(str) 
{
  object ob;

  if (!str) { write("Need argument.\n"); return 1; }

  ob = find_player(lower_case(str));

  if (!ob) { write("No such player.\n"); return 1; }

  if( ob->query_wiz() && this_player()->query_level() < ob->query_level() )
     { write("Illegal.\n");  return 1; }

  last_tell(ob->query_last_tells());

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

