inherit "obj/monster";
object *ob,*jutut,money;
int x,i,ii,xx;
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_level(40);
    set_name("thief");
    set_race("halfling");
    set_short("Thief walking in the shadows");
    set_long("Thief walking in the shadows.\n");
    set_gender(1);
    set_al(50);
    set_heart_beat(1);
    set_dead_ob(this_object());
    set_max_hp(query_hp()*4);
    set_hp(query_max_hp());
    set_special(70);
    money = clone_object("obj/new_money");
    money->set_type(6);
    move_object(money, this_object());
}

void heart_beat() {
   ::heart_beat();
   ob = all_inventory(environment(this_object()));
   for(i=0;i<sizeof(ob);i++) {
	   if(living(ob[i]) && random(100) > 90) {
		   x = random(i);
		   jutut = all_inventory(ob[x]);
		   for(ii=0;ii<sizeof(jutut);ii++) {
			   if(jutut[ii]->query_armour() || jutut[ii]->query_weapon() || jutut[ii]->query_money()) {
		   move_object(jutut[1], this_object());
		   tell_object(ob[x], "You feel like lost something.\n");
		   init_command(({ "north","south","west","east","northwest","northeast","southwest","southeast",})[random(8)]);
	   }
   }
}
}
}
special_move() {
     init_command(""+({ "north", "south", "northwest", "northeast", "west",
"southwest", "east", "southeast",})[random(8)]+"");
}

monster_died() {
	shout("Thief was killed by "+this_player()->query_name()+"\n");
	call_other("/wizards/neophyte/thief/start", "winner",0);
	return 0;
}