inherit "obj/monster"; 
 
reset(arg) {
    object money;
        ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 32);
    call_other(this_object(), "set_name", "vladimir");
    call_other(this_object(), "set_alias", "drunkard");
    call_other(this_object(), "set_short", "A man by the name of Vladimir sits at a table drinking tuika");
    call_other(this_object(), "set_long", "Vladimir laughs as he sees you. He mutters in his local\n" +
                                          "language that makes everyone laugh. You fail to find that anyhow\n" +
                                          "amusing.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_spell_chance(69, "exs brr blt");
    set_skill("cast essence", 69);
    set_skill("cast ice", 69);
    set_skill("cast bolt", 69);
    set_skill("mastery of ice", 100);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(5000)+1000);
    move_object(money, this_object());
 
}
