inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_name("dibbler");
  set_race("human");
  set_level(1);
  set_exp(1);
  set_max_hp(query_max_hp()*1000000);
  set_hp(query_max_hp());
  set_aggressive(0);
  set_short("Dibbler, giving info about 'Con");
  set_long("Dibbler is walking around, talking with passing people.\n");
  set_random_pick(0);
  set_resists("physical", 100);
  set_resists("fire", 100);
  set_resists("acid", 100);
  set_resists("poison", 100);
  set_resists("psionic", 100);
  set_resists("asphyxiation", 100);
  set_resists("cold", 100);
  set_resists("electric", 100);
  set_str(query_str()*1000);
}

init() {
  ::init();
  if(random(100) > 50) random_quote(this_player());
}

random_quote(object ob) {
  string str;
  int num;

  tell_object(ob, "\nDibbler says '");
  num = random(6);
  switch(num) {
  case 0: str = "Hey, you there! Don't forget to come to 'Con and bring beer to your Arch's!"; break;
  case 1: str = "You are haven't forgotten about the 'Con, have you?\n"; break;
  case 2: str = "Meet your fellow players at 'Con, be there or be squirrel!"; break;
  case 3: str = "If you haven't 'register'ed to 'Con but are coming, run E of INN and do it today!"; break;
  case 4: str = "If you'r Arch, come drink free refreshments to 'Con! ..if you'r not, BRING refreshments to your Archs!"; break;
  case 5: str = "Now's your unique oppoturnity to support fellowship of the mud, come to 'Con!"; break;
  }
  tell_object(ob, str+"'\n\n");
  tell_object(ob, "Dibbler gives you a leaflet and says 'Read it for more info.'\n");
  move_object(clone_object("/wizards/archsin/misc/leaflet.c"), ob);
  return 1;
}
