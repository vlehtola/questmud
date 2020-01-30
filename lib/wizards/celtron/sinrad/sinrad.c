inherit "obj/monster";

reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(90);
    set_race("human");
    set_gender(1);
    set_log();
    set_resists("fire", 100);
    set_resists("cold", 100);
    set_resists("electric", 100);

    set_name("sinrad");
    set_alias("guard");
    set_short("Sinrad, the cityguards commander");
    set_long("Sinrad is a mediocre sized human. His movements reveal that he\n"+
	"is very agile and strong. Maybe you shouldn't get in his way.\n");
    chat_str = allocate(5);
    chat_str[0] = "Sinrad makes some unbelievable combat movements.\n";
    chat_str[1] = "Sinrad says: 'Yep, i got a permanent protection against all sort of magic when i rescued Koldan's archmages.\n";
    chat_str[2] = "Sinrad says: 'I was a mighty fighter in my days.. and now i'm stuck in here looking after the capitals security.\n";
    chat_str[3] = "Sinrad says: 'They say you should push the statue.'\n";
    chat_str[4] = "Sinrad states: 'By the way, if you are trying to please Anrax, train your\n"+
			"attack skill and advance more in guilds..\n";
    load_chat(20, chat_str);
    set_block_dir("west");
    set_skill("round blow", 100);
    set_skill("tumble", 200);
    set_skill_chance("strike", 100);
    set_skill_chance("round blow", 100);
    move_object(clone_object("/wizards/celtron/sinrad/doomsday"),
	this_object());
    move_object(clone_object("/wizards/celtron/sinrad/guard_shield"),
	this_object());
    move_object(clone_object("/world/eq/armours/platemail"), this_object());
    move_object(clone_object("/world/eq/armours/bracers"), this_object());
    move_object(clone_object("/world/eq/armours/gauntlets"), this_object());
    move_object(clone_object("/world/eq/armours/helm"), this_object());
    move_object(clone_object("/world/eq/armours/leggings"), this_object());
    set_special(21);

    init_command("wield sword");
    init_command("lwield shield");
    init_command("wear plate");
    init_command("wear helm");
    init_command("wear bracers");
    init_command("wear gauntlets");
    init_command("wear leggings");
}

catch_tell(str) {
    object ob;
    string tmp, tmp2;
    ::catch_tell(str);
    if (sscanf(str, "%s attacks %s", tmp, tmp2) == 2) {
        ob = present(tmp);
        if (ob) {
           say("Guard grunts in anger and attacks "+ob->query_name()+"\n");
           attack_object(ob);
        }
    }
}

special_move() {
  object ob, env;
  int i;
  i = random(3);
  env = environment(this_object());
  if(i==0) {
    ob=all_inventory(env);
    while(ob[i] == this_object()) {
      i = random(sizeof(ob));
    }
    tell_room(env, "Sinrad jumps in the air makes and makes a voltage landing in front of "+
	ob[i]->query_name()+ " and brutally SLASHES "+ob[i]->query_objective()+"!\n");
     ob[i]->hit_with_spell(300+random(400));
    return 1;
  }
  if(i==1) {
    tell_room(env, "Sinrad CRUELLY thrusts his sword to "+query_attack()->query_name()+
	"'s torso!\n");
    query_attack()->hit_with_spell(400+random(400));
    return 1;
  }
  if(query_attack()->query_gender() != 1) return;
  tell_room(env, "Sinrad barbarically kicks "+query_attack()->query_name()+" into his balls!\n");
  tell_object(query_attack(), "OUCH! You get stunned by Sinrad's dirty kick.\n");
  query_attack()->hit_with_spell(200);
  query_attack()->set_stunned(6);
}
