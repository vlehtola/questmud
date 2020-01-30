inherit "/obj/monster";

object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(90);
    set_name("manager");
    set_alias("gerdy");
    set_short("Gerdy, the contest manager");
    set_long("A strong looking fellow.\n");
    set_al(0);
    set_aggressive(0);
    set_gender(1);
    set_race("human");
        chat_str = allocate(3);
         chat_str[0] =
          "Gerdy says: Who might be the strongest?\n";
        chat_str[1] =
          "Gerdy says: Join the competition!\n";
        chat_str[2] =
          "Gerdy points at the sign and explains some rules.\n";
    load_chat(15, chat_str);

}               


self_destruct() {
destruct(present("gerdy",find_object("/world/city/cs")));    
	destruct(this_object());
}                                                               
