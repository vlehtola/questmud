/* this function works on monster files 
   add it in to your monsters and configure it */

catch_tell(str) {
  object ob,player;
  string tmp,tmp2;
  if(sscanf(str,"%s gives %s to "+cap_name+".",tmp,tmp2) == 2) {
    if(ob = present(tmp2,this_object())) {
      if(ob == find_object("/wizards/walla/eku")) {
	player = find_player(tmp);
	/* quest completed */
	player->add_exp(1);
	player->add_money(1);
	tell_object(player,cap_name+" gives you <eku>.\n");
	move_object(clone_object("/wizards/walla/eku2"), player);
        return 1;
      } else {
	say(cap_name+" says: 'Thanks!'\n");
	return 1;
    }
  }
}

