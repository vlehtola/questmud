inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 25);
    call_other(this_object(), "set_name", "maid");
    call_other(this_object(), "set_alias", "maid");
    call_other(this_object(), "set_short", "Mediterranian bearded cleaning maid, cleaning Wayne's crap");
    call_other(this_object(), "set_long", "The maid looks at you with her scary eyes, and you almost\n"+
                                         "jump up to the ceiling, she has a moustache, maybe you should get\n" +        "her a Gilette(R) Sensor Excel for Women for her christmas present.\n");
    call_other(this_object(), "set_al", 10);
 call_other(this_object(), "set_aggressive", 0);                   
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Mediterranean woman squeeks: Que pasa ?.\n";
        chat_str[1] =
          "Maid cries: Damn that Wayne, look at all this shit he leaves behind.\n";
        chat_str[2] =
          "Maid says: Buenos Nachos.\n";
        chat_str[3]=
          "Maid says: Wayne's just having fun again, if you wanna see him, check the Gasworks.\n";
        chat_str[4]=
         "Maid screams: Madre de dios, porque ce miser ?\n";
          
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Maid says: Hey, get off me, or don't...\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
   armour = clone_object("/wizards/walla/wayne/weapons/mopp");   
    move_object(armour, this_object());
    init_command("wield mopp");
 
    weapon = clone_object("/wizards/walla/wayne/armour/cloth");
    move_object(weapon, this_object());
    init_command("wear cloth");
}
