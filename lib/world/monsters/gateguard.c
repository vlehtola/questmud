inherit "obj/monster";
reset(arg) {
  object eq,eq2,eq3,eq4;
  ::reset(arg);
  if(arg) return;
  set_level(35);
  set_str(query_str()*2);
  set_exp(query_exp() /2);
  set_name("guard");
  set_alias("gateguard");
  set_short("A guard watching the gate of Duranghom");
  set_long("The guard looks skillful and muscular. He is dressed\n"+
  	"in white and green, the colors of Duranghom.\n"+
	"He's mission is to maintain law and order and to protect\n"+
	"the city from invaders.\n");  
  
  set_skill_chance("kick", 100);
  set_skill("kick", 100);
}

init() {
  add_action("stop_undead", "north");
  add_action("stop_undead", "south");
  add_action("stop_undead", "west");
  add_action("stop_undead", "east");
}

stop_undead() {
  string dir, dirs, file;
  string tmp,tmp2;
  object room;
  if(!this_player()->query_undead()) return 0;
  if(!this_player()->query_npc() && !this_player()->query_berserk()) return 0;
  dir = query_verb();
  room = environment(this_object());
  if(!room) return 0;
  dirs = room->query_dest_dir();
  file = dirs[member_array(dir, dirs)-1];
  if(sscanf(file, "%sworld/city%s", tmp, tmp2) != 2 &&
     sscanf(file, "world/city%s", tmp) != 1) return 0;
  tell_room(room, short()+" stops "+this_player()->short()+" from entering the city!\n"+
	query_name()+" says 'You are not wanted here. Get lost!'\n");
  return 1;
}

catch_tell(str) {
  string tmp,tmp2;
  object ob;
  if(str && sscanf(str, "%s is in vigorous combat with %s.",tmp,tmp2)==2) {
    if(tmp != "Guard") {
      ob = present(tmp, environment(this_object()));
      if(!ob) return;
      say(query_name()+" gets mad on "+tmp+"'s hostile actions!\n");
      attack_object(ob);
    }
  }
}
