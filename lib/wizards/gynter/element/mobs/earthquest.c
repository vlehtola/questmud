inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    set_level(60);
    set_mage(1);
    set_name("elemental");
    set_short("A very old stone elemental");
    set_long("This is the oldest earth elemental left in the earth plane.\n"+
             "It is therefor considered the leader of the plane. It is looking down\n"+
             "at you with it's diamond eyes and every part of his body is covered in hard rock.\n");
    set_al(0);
    set_race("Elemental");
    set_aggressive(0);
    set_init_ob(this_object());
    if (!chat_str) {
      chat_str = allocate(3);
      chat_str[0] = "Elemental says: If I only could get my hands on a dust pouch!\n";
      chat_str[1] = "Elemental says: That would even be worth to give away the key for.\n";
      chat_str[2] = "Elemental says: But who would be foolish enough to get it from the granite giant?.\n";
    }
    load_chat(20, chat_str);
}

catch_tell(str) {
    string tmp1,tmp2;
    ::catch_tell(str);
    if (sscanf(str, "%s gives A pouch to %s.", tmp1, tmp2) == 2) {
      if (present("pouch", this_object()) && this_player()->query_name() == tmp1) {
        write("As you give the pouch to the elemental, it momentarily shines up with a smile\n");
        write("and slowly shakes its head.\n");
        if (!(this_player()->query_quest("Give pouch to the stone elemental"))) {
          this_player()->set_quest("Give pouch to the stone elemental");
        }
       "/wizards/gynter/element/earth/14"->quest_completed();
        call_out("nuke", 1);
        return 1;
      }
    }
}

nuke() {
  object diamond;
  say("The elemental seems content and gives a diamond to "+this_player()->query_name()+" before it disappears in a puff of smoke.\n");
  diamond = clone_object("/wizards/gynter/element/eq/diamond");
  move_object(diamond, this_player());
  destruct(present("pouch",this_object()));
  destruct(this_object());
  return 1;
}
