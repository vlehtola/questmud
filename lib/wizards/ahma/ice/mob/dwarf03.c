inherit "obj/monster";

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(20);
  set_name("harald");
  set_race("dwarf");
  set_gender(1);
  set_short("Harald, the sturdy Dwarf");
  set_long("Harald is a big and muscular Dwarf. He really must be familiar with cold\n" +
           "because he is not wearing any upper-body equipment. His long, grey beard\n" +
           "has been twisted into sturdy braids which hang down from his chin, looking\n" +
           "quite funny. In general, Harald seems to be very peaceful Dwarf, but his\n" +
           "muscles and few scars on the forehead show that fighting is not an\n" +
           "unfamiliar thing to this man.\n");
  
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Harald says: 'Serak is a lunatic. He once tried to kill my pet wolverine.'\n";
    chat_str[1] = "Harald says: 'Once I tamed my pet wolverine, Serak got jealous and got his own.'\n";
    chat_str[2] = "Harald says: 'It's so hard to make up a good name for your pet. I ended up with Trunz.'\n";
    chat_str[3] = "Harald says: 'I think Trunz is a funny name for a pet wolverine.'\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Harald begins a scornful laugh as he lands a strike on you.\n";
    a_chat_str[1] = "Harald tries to kick you in the neck, but misses barely.\n";
  }
  
  load_chat(4, chat_str);
  load_a_chat(10, a_chat_str);
  set_resists("cold", 50);

  move_object(clone_object("/wizards/ahma/ice/eq/lpants"), this_object()); init_command("wear pants");
  move_object(clone_object("/wizards/ahma/ice/eq/lshoes"), this_object()); init_command("wear slippers");
}
