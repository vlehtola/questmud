inherit "obj/monster";

reset(arg) {
object weapon;
::reset(arg);
if(arg) return;
set_level(27);
set_race("human");
set_name("dweller");
set_alias("dweller");
set_alt_name("guard");
set_gender(1);
set_short("Dark dweller king's royal guard");
 set_long("This dweller has symbols of a cave on his skirt. He has\n"+
  "a muscular body and he stands firmly on his spot,\n"+
  "letting no-one pass. After all, this guy\n"+
  "is one of the royal guards.\n");
set_skill("strike", 60);
weapon = clone_object("/wizards/rimber/cave/obj/club.c");
move_object(weapon, this_object());
init_command("wield club");
set_block_dir("north");
}

catch_tell(str) {
 object ob;
 string who, what;
 if(sscanf(str,"%s attacks %s!",who,what) == 2) {
  ob = present(lower_case(who), environment(this_object()));
 if(what == "King" || what == "Dweller" || what == "Guard") {
   say("Guard shouts: 'Attaaack!'\n");
  attack_object(ob);
 }
}
}
