/* Party teleport */
int real_x, real_y;
object caster_ob;
resolve(bonus, target, ob) {
	int mastery, x, y;
	string vroom;
	object p_ob;
	caster_ob = ob;
	vroom = "/room/out/outmap";
    if(!target) { tell_object(caster_ob, "Usage: cast exs zzt loc at coordinate1 coordinate2\n"); return 1; }
    mastery = caster_ob->query_skills("navigation mastery");

    if(sscanf(target, "%d %d", x, y) != 2) {
		tell_object(caster_ob, "Usage: cast exs zzt loc at coordinate1 coordinate2\n");
		return 1;
	}
	p_ob = caster_ob->query_party();
	if(!p_ob) { tell_object(caster_ob, "You are not in the party.\n"); return 1; }

  // random(1) == 0, random(2) == 0 OR 1

    real_x = x+random(get_mastery(mastery)+1);
    real_y = y+random(get_mastery(mastery)+1);
    if(caster_ob->query_wiz()) { tell_object(caster_ob, "X:"+real_x+" Y:"+real_y+"\n"); }
	if(vroom->check_no_walk(vroom->get_map_char(real_x, real_y))) {
	tell_object(caster_ob, "You get a fair away look and try to teleport the right spot.\n");
	wrong_tele();
	return 1;
}
	tell_object(caster_ob, "You get a fair away look and try to teleport the right spot.\n");
	right_tele();
	return 1;
}
get_mastery(int i) {
	switch(i) {
		case 0..10:return 10;
		case 11..20:return 9;
		case 21..30:return 8;
		case 31..40:return 7;
		case 41..50:return 6;
		case 51..60:return 5;
		case 61..70:return 4;
		case 71..80:return 3;
		case 81..90:return 2;
		case 91..99:return 1;
		case 100:return 0;
	}
	return 0;
}

// Fixed by Celtron

right_tele() {
     int i;
     object *ob;
     object p_ob;
     p_ob = caster_ob->query_party();
     ob = all_inventory(environment(caster_ob) );
     for(i=0; i < sizeof(ob); i++) {
	   if(ob[i] && p_ob->is_member(ob[i])) {
  	     tell_object(ob[i], "You have been teleported.\n");
	     ob[i]->move_player("to the outworld#virtual /room/out/outmap "+real_x+" "+real_y);
           }
     }
}

wrong_tele() {
    int i;
    object *ob;
    object p_ob;
    p_ob = caster_ob->query_party();
  ob = all_inventory(environment(caster_ob) );
  for(i=0; i < sizeof(ob); i++) {
    if(ob[i] && p_ob->is_member(ob[i])) {
      tell_object(ob[i], "You have been teleported to solid rock.\n");
      ob[i]->death();
    }
  }
}
