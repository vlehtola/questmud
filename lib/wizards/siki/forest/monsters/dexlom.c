inherit "obj/monster";
object belt;
object robe;
object hat;

reset(arg) {
	 string chat_str;
     ::reset(arg);
     if(arg) {return; }
     set_name("dexlom");
     set_level(65+random(10));
     set_gender(1);
     set_al(-50+random(10));
     set_alias("druid");
     set_alt_name("black druid");
     set_move_at_reset();
     set_short("Dexlom the black druid");
     set_long(
	 "He was once a noble keeper of the balance, but somehow his mind has been\n"+
	 "turned towards evil. The eyes of Dexlom look like burning in madness. He\n"+
         "is constantly glancing and touching his precious-looking belt. He is\n"+
	 "wearing a quite long black robes which almost cover his entire body. He\n"+
         "is also wearing a twisted-looking pointed black hat.\n");

	set_aggressive(1);
	set_log();
	set_str(query_str()+300);
	set_max_hp(query_hp()+50000);
	set_hp(query_max_hp());
	set_whimpy();
	set_move_at_reset();
	belt = clone_object("/wizards/siki/forest/objects/belt");
	move_object(belt, this_object());
	robe = clone_object("/wizards/siki/forest/objects/robes");
	move_object(robe, this_object());
	hat = clone_object("/wizards/siki/forest/objects/hat");
	move_object(hat, this_object());
	init_command("wear belt");
	init_command("wear robe");
	init_command("wear hat");
}
catch_tell(str) {
   string who;
   if(sscanf(str, "%s is DEAD, R.I.P.", who) == 1) {
   tell_room(environment(this_object()), "Dexlom drains something from the body of "+who+".\n");
   this_object()->heal_self(15000);
    return 1;
}
if(sscanf(str, "%s leaves out", who) == 1) {
	tell_object(find_player(lower_case(who)), "Dexlom tells you 'Hah pitiful mortal running away that soon!'\n");
}
}
