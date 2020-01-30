/* TAA MONSU ON SIT UNKILLABLE, ETTA SEMMOSTA //Celtron */

inherit "obj/monster";

reset(arg) {
  int i;
  string chat_str, a_chat_str;
  object money, weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(80);
  set_race("giant");
  set_str(query_str()*3);
  set_regen(query_max_hp()/20); /* 10 minuutis maxii */
  set_gender(1);
  set_log();
  i = 0;
  while(i<m_sizeof(resists)) {
    set_resists(i,66);
    i += 1;
  }
  set_special(25);
  set_name("heinr");
  set_alias("giant");
  set_short("Heinr, the leader of the giant tribe");
  set_long(
"Heinr looks very strong, his shirt has ripped from several places\n"+
"and his enormous muscles can be seen to move under his bronze skin.\n"+
"He seems to be well prepared for battle, as his armor and weapons\n"+
"are just oiled and polished.\n");
  chat_str = allocate(4);
  chat_str[0] = "Heinr hits the table with his fist and it lets out a horrible\n"+
		  "creaking noise. One more hit and it might break totally.\n";
  chat_str[1] = "Heinr laughs and says '..did you hear how they screamed when I stomped on them?'\n";
  chat_str[2] = "Heinr says 'One more beer! For the victory.'\n";
  chat_str[3] = "Heinr looks at Grumph and says 'Thanks for the magicks, I still feel unbeatable! Har har!'\n";
  load_chat(20, chat_str);
  set_skill("round blow", 100);
  set_skill_chance("strike", 100);
  set_skill_chance("round blow", 100);
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  if(!ob || file_name(environment(this_object()) ) != "wizards/celtron/ogremage/2") return 0;
  tell_object(ob, "Heinr steps forward and BASHES you with an AWESOME force causing you to fly backwards!\n");
  say("Heinr suddenly BASHES "+ob->query_name()+" with an AWESOME force causing "+ob->query_possessive()+" to fly backwards!\n",ob);
  move_object(ob, "/wizards/celtron/ogremage/room1");
  tell_object(ob, "You hit the wall! OUCH!\n");
  tell_room(environment(ob), ob->query_name()+" flies backwards through the room and collides with the wall!\n", ({ob,}) );
  ob->set_stunned(10);
  ob->hit_with_spell(1000); /* tarkotus tappaa tms */
}
