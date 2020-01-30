inherit "/obj/monster";

object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(25);
    set_name("rudolf");
    set_alias("man");
    set_undead(1);
    set_short("Rudolf the Rich is haunting here");
    set_long("This man has died sever years ago, something has disturbed his rest.\n");
    set_al(0);
    set_aggressive(0);
    set_gender(1);
    set_race("human");
    set_block_dir("out");
        chat_str = allocate(2);
         chat_str[0] =
          "Rudolf storms: Thou shall not leave here!\n";
        chat_str[1] =
          "Rudolf storms: Thee must rotten with me forever!\n";
    load_chat(15, chat_str);

}               

                                                               