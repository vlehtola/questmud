inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 50);
    call_other(this_object(), "set_name", "stranger");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_hp", "100000");
    call_other(this_object(), "set_exp", "6666666");
    call_other(this_object(), "set_short", "A mysterious stranger");
    call_other(this_object(), "set_long", "This is a mysterious stranger.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);                   
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Stranger says: Niss uea gjak rosgety.\n";
        chat_str[1] =
          "Stranger says: Musd aljsyt aweig oraija.\n";
        chat_str[2] =
          "Stranger mumbles: Asjadn roiwan oraesia roasadlaks.\n";
        chat_str[3]=
          "Stranger looks at you and says: lsajh aorir oairjh sigs.\n";
        chat_str[4]=
         "Stranger says: Asmsdg Fya suck suck suuuuck\n";
          
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Stranger goes: kfsmn rihi aphk ienas.\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/walla/ravenloft/areas/stranger/hat");   
    move_object(armour, this_object());
    init_command("wear hat");
 
    weapon = clone_object("/wizards/walla/ravenloft/areas/stranger/cloak");
    move_object(weapon, this_object());
    init_command("wear cloak");

}

