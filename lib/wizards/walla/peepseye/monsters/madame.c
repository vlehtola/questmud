
inherit "obj/monster";

reset(arg) {
    object money;
        ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 39);
    call_other(this_object(), "set_name", "madame");
    call_other(this_object(), "set_exp", "696969");
    call_other(this_object(), "set_alias", "whore");
    call_other(this_object(), "set_short", "Madame Mona winks behind the desk");
    call_other(this_object(), "set_long", "As you run your eyes upon the curves of Madame Mona\n" +
                                          "she slaps you. Well, a well built lady like that should not be here. And\n" +
                                          "look at those BIG boo... lungs.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);


    money = clone_object("obj/money");
    call_other(money, "set_money", random(5000)+1000);
    move_object(money, this_object());

}
