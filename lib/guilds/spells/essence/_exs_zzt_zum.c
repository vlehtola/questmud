resolve(bonus, target, caster_ob) {
  object ob, room;
  int i;
  string str, tmp, tmp2;
  tell_object(caster_ob, "You release the spell.\n");

  if(target) {
        switch(target) {
                case "w": target = "west"; break;
                case "nw": target = "northwest"; break;
                case "n": target = "north"; break;
                case "ne": target = "northeast"; break;
                case "e": target = "east"; break;
                case "se": target = "southeast"; break;
                case "s": target = "south"; break;
                case "sw": target = "southest"; break;
        }
  }

  str = environment(caster_ob)->query_valid_dir(target);
  if(str && stringp(str) && sscanf(str, "%s#%s", tmp,tmp2) != 2) {
    call_other(str, "???");
    room = find_object(str);
  }
  if(str && objectp(str)) room = str;
  if(!room) {
    if(caster_ob->query_tester()) tell_object(caster_ob, "Casting an environment()\n");
    room = environment(caster_ob);
  }
  ob = all_inventory(room);
  while(i<sizeof(ob)) {
    if(ob[i]->query_force_field() || ob[i]->query_shelter() || ob[i]->query_amf()) {
      tell_room(environment(ob[i]), ob[i]->short()+" suddenly vanishes!\n");
      destruct(ob[i]);
    }
    i += 1;
  }
  return 1;
}
