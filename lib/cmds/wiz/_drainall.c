cmd_drainall(arg) 
{
  object *list;
  int i,o;
  if(!arg || sscanf(arg, "%d", i) != 1) return;
  if(this_player()->query_wiz()<4) {
	write("No can do. //Celtron\n");
	return 1;
  }
  shout(this_player()->query_name()+" spreads "+this_player()->query_possessive()+" arms and from his eyes and heart comes "+
  "an immense darkness.\nThe darkness rolls over you in waves stealing your health! You are drained by an unearthly force.\n");
  list = users();

  while(o<sizeof(list)) 
  {
    if(list[o]->query_hp() < i) {
        list[o]->set_hp(1);
    } else {
        list[o]->reduce_hp(i);
    }
    o++;
  }

  write("Cast a "+i+" points strong drainall.\nNow everyone will hate you! :P\nBut ain't it fun?\n");
  return 1;
}
