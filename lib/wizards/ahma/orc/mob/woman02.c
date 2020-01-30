inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+18);
  set_name("woman");
  set_race("orc");
  set_gender(2);
  set_short("An Orcish woman is sitting on a chair");
  set_long("A common-looking Orcish woman is sitting on a chair and holding\n" + 
           "some kind of a cloth on her hands. She seems to be knitting socks\n" + 
           "to someone. Woman's lips are painted light red and she is wearing\n" + 
           "a pink dress. Woman seems to be a bit scared of you.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Woman tries to glance at you, but lowers her head quickly.\n";
    chat_str[1] = "Woman is struggling with a difficult knitting-pattern.\n";
    chat_str[2] = "Woman hums a quiet tune while knitting.\n";
  }
  load_chat(3, chat_str);

 if(!present("dress", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/dress"), this_object()); init_command("wear dress"); }
}
