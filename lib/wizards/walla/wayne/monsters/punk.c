inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 20);
    call_other(this_object(), "set_name", "punk");
    call_other(this_object(), "set_alias", "punk");
    call_other(this_object(), "set_short", "A f**king punk stands here waiting to beat up Wayne");
    call_other(this_object(), "set_long", "This punk has a leather jacket and a knife that he's holding\n"+
                                         "in his hand. He doesn't seem to notice you much.\n");
    call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 0);                   
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Punk says: Hey asshole, you ain't seen that nogood son of a b**ch Wayne around, he's my friend, and I'd like to kic- talk to him.\n";
        chat_str[1] =
          "Punk spits on the ground.\n";
        chat_str[2] =
          "Punk throws his knife in the air \n";
        chat_str[3]=
          "Punk finishes his beer and breaks the bottle against the house corner.\n";
        chat_str[4]=
         "Punk stuffs some more gum into his mouth.\n";
          
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Punk says: Hey, fuck off asshole, I'm waiting for Wayne\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
   armour = clone_object("/wizards/walla/wayne/weapons/knife");   
    move_object(armour, this_object());
    init_command("wield knife");
 
    weapon = clone_object("/wizards/walla/wayne/armour/leatherjacket");
    move_object(weapon, this_object());
    init_command("wear jacket");
}


