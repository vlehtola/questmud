cmd_children(arg)
{
  object *list;
  int i,o;
  if(!arg || sscanf(arg, "%d", i) != 1) return;
  if(this_player()->query_wiz()<3) return;

  shout("You see a windy gust, in the form of a black cloud appear over your head... You hear screamings from the cloud,\n"+
  "screaming 'CHIIIIILDREEEEN OF THE NIIIIIIIIIGHT!'. As the cloud leaves you, you feel drained of your powers\n");
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

  write("IIVIL "+i+" childrenofthenight.\nNow everyone will hate you! :P\nBut ain't it fun?\n");
  return 1;
}

