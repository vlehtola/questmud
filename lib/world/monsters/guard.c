inherit "obj/monster";

int phase;

reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(30);
    set_name("guard");
    set_short("A guard of Duranghom on break");
    set_long("This man looks quite tall and he is dressed in the green and white\n" +
	 "clothes, the colors of Duranghom.\n");
    set_al(40);
    set_aggressive(0);

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Guard says: 'Obey the rules of the city.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Guard shouts: 'You will regret this!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(20, a_chat_str);
        
    call_out("do_phase", 300);

    weapon = clone_object("world/eq/weapons/shortsword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}

do_phase(arg) {
    string str;
    if (this_object()->query_attack()) { return 1; }
    if (arg) { set_short("A guard of Duranghom on patrol"); }
    if (phase >= 0 && phase < 7) { str = "east"; }
    if (phase == 7) { str = "south"; }
    if (phase > 7 && phase < 11) { str = "east"; }
    if (phase > 10 && phase < 14) { str = "south"; }
    if (phase > 13 && phase < 17) { str = "west"; }
    if (phase > 16 && phase < 21) { str = "south"; }
    if (phase > 20 && phase < 26) { str = "west"; }
    if (phase > 25 && phase < 29) { str = "north"; }
    if (phase > 28 && phase < 31) { str = "west"; }
    if (phase > 30 && phase < 37) { str = "north"; }
    if (phase > 36 && phase < 39) { str = "east"; }
    if (phase == 39) { str = "south"; }
    if (phase == 40) { str = "west"; }
    phase += 1;
    command(str);
    if (phase == 41) {
	set_short("A guard of Duranghom on break");
	phase = 0;
	call_out("do_phase", 300, 1);
	return 1;
    }
    call_out("do_phase", 1);
}

catch_tell(str) {
    object ob;
    string tmp, tmp2;
    if (sscanf(str, "%s attacks %s", tmp, tmp2) == 2) {
	ob = present(tmp);
	if (ob) {
	   say("Guard grunts in anger and attacks "+ob->query_name()+"\n");
	   attack_object(ob);
	}
    }
}
