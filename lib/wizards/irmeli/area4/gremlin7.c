inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money; 
    ::reset(arg);
    if (arg) { return; }
    set_level(16);
    set_name("gremlin");
    set_alias("captain");
    set_short("A muscular gremlin captain");
    set_long("A muscular gremlin captain is watching after its recruits. Gremlin captain is well trained and muscular. Its torso is so muscular that your punch will just pop out and break your fist. Captain is largest gremlin in this tower.\n");
    set_al(15);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Captain shows its muscles to you.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Captain rips its shirt off.\n";
    }
    load_chat(4, chat_str);
    load_a_chat(2, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(8));
    move_object(money, this_object());
    
}

