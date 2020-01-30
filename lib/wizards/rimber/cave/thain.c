inherit "obj/monster";
object ob;

reset(arg) {
	object weapon;
	object armour;
	::reset(arg);
	if(arg) return;
        set_level(56);
	set_race("human");
        set_con(query_con()*2);
        set_str(query_str()*1);
        set_max_hp(query_max_hp()*2);
        set_alias("king");
 set_name("king");
        set_alt_name("dweller");
	set_gender(1);
        set_short("Dark dweller king");
 set_long("King looks very much like the other dwellers, only\n"+
 "his red cape and ash grey crown separate him from the rest.\n"+
  "He has a stern look on his face. Your appeal seems to annoy him.\n");
       set_skill("strike", 100);
        weapon = clone_object("/wizards/rimber/cave/obj/warhammer.c");
	move_object(weapon, this_object());
	init_command("wield warhammer");
        armour = clone_object("/wizards/rimber/cave/obj/crown.c");
	move_object(armour, this_object());
	init_command("wear crown");
       set_log();
 set_dead_ob(this_object());
}

monster_died() {
 ob = query_attack();
 if(!ob->query_quests("Kill the dark dweller king")) {
 this_object()->query_attack()->set_party_quest("Kill the dark dweller king");
 tell_object(this_object()->query_attack(), "You have killed the dark dweller king and so completed 'Kill the dark dweller king' quest.\n");
 }
 else { tell_object(ob, "You have already completed this quest.\n"); }
 return 0;
}
