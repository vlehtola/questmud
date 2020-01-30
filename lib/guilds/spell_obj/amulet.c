inherit "obj/armour";
int power;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("amulet");
    set_short("A shining amulet");
    set_long("You can 'tune_amulet' to boost some stat. This amulet will lose it's power in reboot.\n"+
	"It cannot be reloaded.\n");
    set_weight(1);
    set_slot("amulet");
}

query_no_save() { return 1; }

make_me(bonus,sp) {
  power = sp * bonus / 30000;
  if(power > 20) power = 20 + (power-20)/5;
  if(power > 40) power = 40;
}

init() {
  ::init();
  add_action("tune_amulet", "tune_amulet");
}

tune_amulet(str) {
  if(!str || sscanf(str, "to %s", str) != 1) {
    write("Usage: tune_amulet to <stat>\n");
    return 1;
  }
  if(!power) {
    write("The amulet has lost it's powers and turns to dust.\n");
    destruct(this_object());
    return 1;
  }
  if (str != "str" && str != "dex" && str != "con" &&
      str != "wis" && str != "int") {
	write("No such a tuning possibility.\n");
	return 1;
  }
  write("You activate the amulet and it glows for a while.\n");
  set_stats("str",0);
  set_stats("dex",0);
  set_stats("con",0);
  set_stats("int",0);
  set_stats("wis",0);
  set_stats(str,power);
  set_short("A shining amulet <"+capitalize(str)+" mode>");
    set_long("You can 'tune_amulet' to boost some stat. This amulet will lose it's power in reboot.\n"+
	"It cannot be reloaded.\n");
  return 1;
}
