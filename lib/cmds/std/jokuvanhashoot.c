cmd_shoot(string str) {
  string w, t;
  object shoot_ob;
  object with;
  object skill;
  object spell;
  skill = this_player()->query_use_skill();
  spell = this_player()->query_spell();
  if(!this_player()->check_condis()) { return 1; }
  if (environment(this_player())->query_property("no_skill")) {
      write("A mystical aura stops your attempt.\n");
      return 1;
  }
  shoot_ob = present("shoot_object", this_player());
  if(!str) { write("Shoot <with> at <target>\nShoot stop\n");  return 1; }
  if(str == "stop") {
  if(shoot_ob) {
	 write("You stop your shooting attempt!\n");
	 shoot_ob->stop_shoot();
	 return 1;
     } else { write("You are not attempting to shoot anything.\n");
 return 1;
 }
}
if(sscanf(str, "%s at %s", w, t) != 2) {
	  write("Usage: shoot <with> at <target>\n");
	  return 1;
  }
if(skill) {
	write("You stop your skill and start to shooting attempt.\n");
	destruct(skill);
}
if(spell) {
	write("You stop your casting and start to shooting attempt.\n");
    destruct(spell);
}
if(shoot_ob) {
  write("You decide to start a new shooting attempt.\n");
  destruct(shoot_ob);
}
  shoot_ob = clone_object("/wizards/siki/shoot_object");
  move_object(shoot_ob, this_player());
  shoot_ob->start_shoot(w, t);
  return 1;
}
