cmd_healall(arg) {
  object list;
  int i,o;
  if(!arg || sscanf(arg, "%d", i) != 1) return;
  shout(this_player()->query_name()+" claps "+this_player()->query_possessive()+" hands together and sends out "+
	"an immense healing\nwave that spreads throughout the world! You are healed by unearthly force.\n");
  list = users();
  while(o<sizeof(list)) {
    list[o]->heal_self(i);
    o+=1;
  }
  write("Cast a "+i+" points strong healall.\n");
  return 1;
}
