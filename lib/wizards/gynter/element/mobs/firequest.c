inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    set_mage(1);
    set_level(60);
    set_name("demon");
    set_gender("male");
    set_short("A HUGE fire demon");
     set_long("This is the leader of the fireelementals. It is entirelly made out\n"+
             "out of flames. It is burning so hot that it is almost white.\n");
    set_al(0);
    set_race("Elemental");
    set_al_aggr(200);
    set_aggressive(0);
    set_spell_chance(90, "exs fla blt");
    set_skill("cast essence", 100);
    set_skill("cast fire", 100);
    set_skill("cast bolt", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
    set_init_ob(this_object());
    if (!chat_str) {
      chat_str = allocate(3);
      chat_str[0] = "Demon shouts: Where is my key?!?!?!\n";
      chat_str[1] = "Demon shouts: The one that returnes it to me will get a great reward!!\n";
      chat_str[2] = "With a cackle the demon's eyes starts to glow red and as it looks at you\n"+
                      "it feels like it can see right through you!\n";
    }
    load_chat(40, chat_str);
}

catch_tell(str) {
   string tmp1, tmp2;
   ::catch_tell(str);
   if (sscanf(str, "%s gives An old rusty key to %s.", tmp1, tmp2) == 2) {
     if (present("key", this_object()) && this_player()->query_name() == tmp1) {
       write("When you give the key to the fire demon it carefully looks at it.\n");
       if (!this_player()->query_quest("Return the key to the Fire Demon")) {
         this_player()->set_quest("Return the key to the Fire Demon");
       "/wizards/gynter/element/fire/15"->quest_completed();
       call_out("nuke", 1);
       return 1;
       }
     }
   }
}

nuke() {
  object ruby;
  say("The demon seems content and gives "+this_player()->query_name()+" a ruby before it disappears in a puff of smoke.\n");
  ruby = clone_object("/wizards/gynter/element/eq/ruby");
  move_object(ruby, this_player());
  destruct(present("key",this_object()));
  destruct(this_object());
  return 1;
}
