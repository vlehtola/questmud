inherit "obj/monster";

reset(arg) {

     string chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(25);
    set_name("scout");
    set_alias("gnome");
    set_short("A gnome scout looking at horizon");
    set_long("A gnome scout is keeping an eye on the gnomish empire. The scouts have long working hours and they are poorly paid for their job.\n");
    set_al(15);
    set_gender(1);
    set_race("gnome");
    set_aggressive(0);
    set_mage(1);

        if (!chat_str) {

        chat_str = allocate(1);

        chat_str[0] =

          "Scout says: 'My work is to keep an eye on strangers.'\n";



    }



    load_chat(1, chat_str);
}








