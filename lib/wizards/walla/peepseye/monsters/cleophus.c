inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
   call_other(this_object(), "set_level", 33);  
   call_other(this_object(), "set_name", "reverend");
    call_other(this_object(), "set_alias", "cleophus");
    call_other(this_object(), "set_short", "Reverend Cleophus James");
    call_other(this_object(), "set_long", "You see before you, the silhouette of a great man, no perhaps in size, but\n"+
                "sure enough in knowledge of the divine way. He seems to be happythat\n"+
                "you have come in here to listen to great gospel preachings.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

if (!chat_str) {
       chat_str = allocate(5);
        chat_str[0] =
          "Preacher screams: CAN YOU SEEEE THE LIGHT ??.\n";
        chat_str[1] =
          "Preacher screams: Prrrrraaise tha Loooooood !!!\n";
        chat_str[2] =
          "Preacher stutters: Weee aarrre alll chiiilllddrenn offf thee saaamee Gooooood !\n";
        chat_str[3]=
          "Preacher screams: Everybooody say : AAAAAMEEEEEN !\n";
        chat_str[4]=
         "Preacher screams: HAAAALLLLEEEEELUUUUJAAA !!!!\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
a_chat_str[0] = "Preacher throws himself to the ground shouting: WHY HAVE you FORSAKEN Me ?\n";
 }                 
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/walla/peepseye/eq/armour/preacherrobe");
    move_object(armour, this_object());
    init_command("wear robe");
 
 }
