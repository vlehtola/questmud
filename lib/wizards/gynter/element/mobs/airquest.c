inherit "obj/monster";

reset(arg) {
   string chat_str;
    ::reset(arg);
    set_race("elemental");
    set_mage(1);
    set_level(60);
    set_name("lord");
    set_alias("demon");
    set_short("The Lord of the Air realm");
    set_long("This is the lord of the elemental plane called Air. It is standing 20ft tall.\n"+
             "Its head is crowned with two hornes made out of solid gold.\n"+
             "The lords arms are plated with some strange armour that seems to move around its body.\n");
    set_al(0);
    set_al_aggr(200);
    set_spell_chance(100, "exs zzt blt");
    set_aggressive(0);
    set_init_ob(this_object());
if (!chat_str) {
  chat_str = allocate(3);
  chat_str[0] = "Lord says: If I only could get my hands on my sword!\n";
chat_str[1] = "Lord says: I would reward the man who brings it to me greatly!\n";
  chat_str[2] = "Lord says: Curse those who stole it!\n";
  }
  load_chat(30, chat_str);
    set_block_dir("southeast");
    set_skill("cast essence", 100);
    set_skill("cast electricity", 100);
    set_skill("cast bolt", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
}

catch_tell(str) {
  string tmp1, tmp2;
  ::catch_tell(str);
  if(sscanf(str, "%s gives A vorpal blade to %s.", tmp1,tmp2) == 2) {
    if (present("blade", this_object()) && this_player()->query_name() == tmp1) {
      write("As you give the sword to the lord of Air you see it sadden and\n");
      write("you instinctivly understands that it is sad that its people are\n");
      write("turning against it.\n");
      if (!this_player()->query_quest("Give vorpal blade to the lord of Air")) {
        this_player()->set_quest("Give vorpal blade to the lord of Air");
      }
       "/wizards/gynter/element/air/15"->quest_completed();
      call_out("nuke", 1);
      return 1;
    }
  }
}

nuke() {
  object saphire;
  say("It looks at you and silently gives "+this_player()->query_name()+" you a sapphire.\n");
  saphire = clone_object("/wizards/gynter/element/eq/saphire");
  move_object(saphire, this_player());
  destruct(present("blade",this_object()));
  destruct(this_object());
  return 1;
}
