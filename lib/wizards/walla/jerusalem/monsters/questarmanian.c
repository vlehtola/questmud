inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 17";
    call_other(this_object(), "set_name", "citizen");
    call_other(this_object(), "set_alias", "zephaniah");
    call_other(this_object(), "set_short", "Zephaniah, an armenian citizen of Jerusalem");
    call_other(this_object(), "set_long", "Zephaniah is a man that has seen many things. He has a big beard\n" +
                                          "and he twirls his finger around it like he was unpatient of something. His clothing\n" +
                                          "is of the cheapest sort, and it looks like it jus some skin, put on the mans body.\n");
    call_other(this_object(), "set_al", 10);
 call_other(this_object(), "set_aggressive", 0);                 
  if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Zephaniah gurgles with his last words: 'Water', please bring me water.\n";
        chat_str[1] =
          "The citizen sits up and begs for water.\n";
        
  }
    if (!a_chat_str) {
  a_chat_str = allocate(1);                      
 a_chat_str[0] = "I prefer to die in battle than die of thirst.\n";
    }
    load_chat(50, chat_str);
    load_a_chat(35, a_chat_str);
 
 
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear rags");
 
}

