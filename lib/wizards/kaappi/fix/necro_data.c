/* can the corpse be animated? how much sps will it cost? etc */
valid_corpse(object ob, string undead) {
  int spcost;

  /*
  if(ob->query_animal()) {
    write("You cannot add animal corpses to your horde.\n");
    return 0;
  }
   */
  if(!valid_limit(ob,undead)) {
    write("This corpse is too weak to be animated to a "+undead+".\n");
    return 0;
  }
  return 1;
}

valid_limit(object ob, string undead) {
  int i;
  i = ob->query_level();
  switch(undead) {
  case "skeleton"     : return 1;
  case "zombie"       : return i >= 10;
  case "wight"        : return i >= 10;
  }
  return 1;
}
