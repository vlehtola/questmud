inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object robes, pants;
    ::reset(arg);
    if(arg) { return; }
    set_level(10);
    set_name("monk");
    set_alias("prayer");
    set_short("A praying monk");
    set_long("The monk has retired here, to pray to his gods.\n");
    set_race("human");
    set_gender(1);
    set_al(50);
    set_aggressive(0);
 
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Monk puts his finger in front of his mouth, advicing not to speak\n";
        chat_str[1] =
          "The dragon's eyes flicker.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Monk shouts: 'You must DIE!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
 
 
    if(!robes) {
    robes = clone_object("/wizards/walla/area2/stuph/basicrobes");
    move_object(robes, this_object());
    init_command("wear robes");
  }
    if(!pants) {
    pants = clone_object("/wizards/walla/area2/stuph/basicpants");
    move_object(pants, this_object());
    init_command("wear pants");
  }
}



