inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("robes");
    set_short("Black robes with bright red runes");
    set_long("Robes are very comfortable and warm. What might the runes mean?\n");
    set_value(10000);
    set_weight(350);
    set_slot("torso");
    set_stats("dex",-10);
    set_stats("int",30);
    set_stats("wis",20);
    set_stats("spr",20);
}
