inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;  
     object money;
        ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 70);
    call_other(this_object(), "set_name", "scarecrow");
    call_other(this_object(), "set_alias", "fig");
    call_other(this_object(), "set_short", "A scarecrow planted at CS");
    call_other(this_object(), "set_long", "'This looks like a normal scarecrow.\n" +
                                          "It is made of hay, and has some rags on it.\n" +
                                          "It's hat is full of holes");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_spell_chance(69, "exs zzt blt");          
    set_skill("cast essence", 69); 
    set_skill("cast electricity", 69);  
    set_skill("cast bolt", 69);    
    set_skill("mastery of electricity", 100);
    
     if (!chat_str) {   
        chat_str = allocate(2);
        chat_str[0] =
          "A crow lands on the scarecrow, just demonstrating it's efficiency.\n";
        chat_str[1] =
          "A pigeon living on Central Square picks on the pole the scarecrow stands on.\n";
            }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The scarecrow animates itself: You stupid fool ! You will surely perish now !\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);


    money = clone_object("obj/money");
    call_other(money, "set_money", random(5000)+1000);
    move_object(money, this_object());
 
}
