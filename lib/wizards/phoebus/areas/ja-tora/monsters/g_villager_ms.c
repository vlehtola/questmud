inherit "obj/monster";

reset(arg) {
string chat_str;
::reset(arg);

set_name("Gnome villager");
set_level(6);
set_al(60);
set_alias("gnome");
set_alt_name("villager");
set_race("gnome");

set_short("Gnome villager");
set_long("This Gnome is just sitting here having a good rest, he must have had. \n"+
                "a busy day. Or she's just plain lazy.\n");
 
if(!chat_str) {
chat_str = allocate(2);
chat_str[0] = "Gnome says: Im always tired, ahhhhh comfy chair.\n";
chat_str[1] = "Gnome says: Come in and take a seat, you look tired like me.\n";
}
load_chat(10, chat_str);
}
