inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(17);
    set_name("skeleton");
    set_alias("Skeleton");
    set_short("A skeleton roaming around the cemetary");
    set_long("A fleshless creature walking around the premises.\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "The skeleton looks at you curiously.\n";
        chat_str[1] =
          "Bones rattle as the skeleton moves around the room.\n";
     }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The skeleton's fleshless face grins demonically.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    weapon = clone_object("/wizards/nalle/area/eq/knstaff");
    move_object(weapon, this_object());
    init_command("wield staff");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
