inherit "obj/monster";

reset(arg) {
	string chat_str, a_chat_str;
        object staff;
        object strap;
	::reset(arg);
	if (arg) return;
        set_level(35);
	set_short("Dark dweller shaman");
	set_name("Dark dweller shaman");
	set_alias("shaman");
        set_alt_name("dweller");
 set_long("The shaman has a long black beard and a long grey hair.\n"+
  "He is wearing a long, worn dark grey tunic.\n"+
  "Shaman moves gracefully, though his wrinkled hands shake a bit.\n");
	set_race("human");
        staff = clone_object("/wizards/rimber/cave/obj/staff.c");
        move_object(staff, this_object());
        init_command("wield staff");
        strap = clone_object("/wizards/rimber/cave/obj/strap.c");
       move_object(strap, this_object());
	set_gender(1);
	if (!chat_str) {
		chat_str = allocate(3);
		chat_str[0] =
"Shaman chants: 'Ungata bugada. Akiat Eet!'\n";
		chat_str[1] =
"Shaman mutters: 'Mmmumm... Mamamama... Gruhhummummum... PRAAAGH!'\n";
                chat_str[2] =
"Shaman whispers: 'Don't be afrait. You won't feel pain when you die.'\n";
	}
	load_chat(5, chat_str);
    set_block_dir("out");
}

