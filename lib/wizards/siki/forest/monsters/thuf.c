inherit "obj/monster";
object rope;
reset(arg) {
	 string chat_str;
     ::reset(arg);
     if(arg) {return; }
     set_name("thuf");
     set_level(40+random(10));
     set_gender(2);
     set_al(-50+random(10));
     set_alias("lunatic");
     set_short("Thuf the lunatic young lady");
     set_long(
	 "She is constantly drooling and lots of her clothes are wet from saliva. She\n"+
	 "has a mad and lunatic look on her face. Something bad must have happened to\n"+
         "this once so beautiful looking young lady. She is wearing a rope to hold the\n"+
         "clothes from falling down from her body.\n");

	set_aggressive(1);
	set_log();
	set_str(query_str()+300);
	set_max_hp(query_hp()+50000);
	set_hp(query_max_hp());
	rope = clone_object("/wizards/siki/forest/objects/rope");
	move_object(rope, this_object());
}