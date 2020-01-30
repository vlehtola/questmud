/* Teleport */
resolve(bonus, target, caster_ob) {
	int mastery, x, y;
	int real_x, real_y;
	string vroom;
	object ob;
	vroom = "/room/out/outmap";
    if(!target) { tell_object(caster_ob, "Usage: cast exs sol loc at coordinate1 coordinate2\n"); return 1; }
    mastery = caster_ob->query_skills("navigation mastery");

    if(sscanf(target, "%d %d", x, y) != 2) {
		tell_object(caster_ob, "Usage: cast exs sol loc at coordinate1 coordinate2\n");
		return 1;
	}
    real_x = x+random(get_mastery(mastery));
    real_y = y+random(get_mastery(mastery));
    if(caster_ob->query_wiz()) { tell_object(caster_ob, "X:"+real_x+" Y:"+real_y+"\n"); }
    if(vroom->check_no_walk(vroom->get_map_char(real_x, real_y))) {
		tell_object(caster_ob, "You accidently teleport yourself in to solid rock.\n");
		caster_ob->death();
		return 1;
	}
	tell_object(caster_ob, "You teleport yourself in to the outworld.\n");
	caster_ob->move_player("to the outworld#virtual /room/out/outmap "+real_x+" "+real_y);
	tell_room(environment(caster_ob),caster_ob->query_name()+" arrives in the puff of smoke.\n", ({caster_ob}));
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

