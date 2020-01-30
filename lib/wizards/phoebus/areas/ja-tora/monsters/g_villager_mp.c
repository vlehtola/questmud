inherit "obj/monster";

reset(arg) {
string chat_str;
::reset(arg);

set_name("Gnome villager");
set_level(6);
set_al(60);
set_gender("male");
set_alias("gnome");
set_alt_name("villager");
set_race("gnome");

set_short("Gnome villager");
set_long("This Gnome is busy painting the front of his house. He doesn't look \n"+
                "too happy. In the background you can hear a females voice yelling \n"+
                "at him to hurry up and paint faster, must be his wife.\n");
if(!chat_str) {
chat_str = allocate(3);
chat_str[0] = "Man says: Paint the bloody house, huh. \n";
chat_str[1] = "Female says:.Hurry up you lazy Gnome. \n";
chat_str[2] = "Man says: The sooner i can finish the sooner i can go fishing. \n";
}
load_chat(10, chat_str);
}
